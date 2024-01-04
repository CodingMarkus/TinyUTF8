#!/bin/sh
set -e -u

readonly lookupTableUpTo=127
readonly outValuesPerLineLookupTable=8
readonly outValuesPerLineSearchTable=4

input='UnicodeData.txt'
if [ ! -f "$input" ]
then
	echo "File $input not found!" >&2
	exit 1
fi


mapCategory( )
{
	case $1 in
		Lu) printf '1\n' ;;
		Ll) printf '2\n' ;;
		Lt) printf '3\n' ;;

		Lm) printf '4\n' ;;
		Lo) printf '5\n' ;;

		Mn) printf '6\n' ;;
		Mc) printf '7\n' ;;
		Me) printf '8\n' ;;

		Nd) printf '9\n' ;;
		Nl) printf '10\n' ;;
		No) printf '11\n' ;;

		Pc) printf '12\n' ;;
		Pd) printf '13\n' ;;
		Ps) printf '14\n' ;;
		Pe) printf '15\n' ;;
		Pi) printf '16\n' ;;
		Pf) printf '17\n' ;;
		Po) printf '18\n' ;;

		Sm) printf '19\n' ;;
		Sc) printf '20\n' ;;
		Sk) printf '21\n' ;;
		So) printf '22\n' ;;

		Zs) printf '23\n' ;;
		Zl) printf '24\n' ;;
		Zp) printf '25\n' ;;

		Cc) printf '26\n' ;;
		Cf) printf '27\n' ;;
		Cs) printf '28\n' ;;
		Co) printf '29\n' ;;
		Cn) printf '30\n' ;;

		*)
			echo "Bad category $1!" >&2
			exit 1
	esac
}


tableValue1=
tableValue2=
tableValue3=

outValuesCurrentLine=0


printTableEntry( )
{
	#  0                   1                   2                   3
	#  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# |U|  Value1 |  Value2 |  Value3 |
	# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	calculation="($tableValue1 * 2^10) + ($tableValue2 * 2^5) + $tableValue3"
	result=$( printf 'obase=16; %s' "$calculation" | bc )
	result="0x$result"

	if [ $outValuesCurrentLine -eq 0 ]
	then
		printf '\t%s' "$result"
	elif [ $outValuesCurrentLine -ge "$outValuesPerLineLookupTable" ]
	then
		printf ',\n\t%s' "$result"
		outValuesCurrentLine=0
	else
		printf ', %s' "$result"
	fi

	outValuesCurrentLine=$(( outValuesCurrentLine + 1 ))
}


output="
#include \"internal/stdc.h\"

/// Table up to code point $lookupTableUpTo
static
const uint16_t categoryLookupTable[ ] = {
"
printf '%s' "$output"


# shellcheck disable=2013
for entry in $( cut -f 1,3 -d ';' "$input" )
do
	cp=$( printf '%llu' "0x${entry%;*}" )
	category=$( mapCategory "${entry#*;}" )

	[ "$cp" -le 31 ] && continue
	[ "$cp" -gt $lookupTableUpTo ] && break

	if [ -z "$tableValue1" ]
	then
		tableValue1=$category
		continue
	fi

	if [ -z "$tableValue2" ]
	then
		tableValue2=$category
		continue
	fi

	tableValue3=$category
	printTableEntry
	tableValue1=
	tableValue2=
	tableValue3=
done

if [ -n "$tableValue1" ]
then
	[ -z "$tableValue2" ] && tableValue2=0
	[ -z "$tableValue3" ] && tableValue3=0
	printTableEntry
fi

output="
};

const size_t categoryLookupTableCount = $lookupTableUpTo;

"
printf '%s' "$output"


rangeNext=
rangeStart=
rangeLength=
rangeCategory=

rangesCount=0
outValuesCurrentLine=0


printRange( )
{
	#  0                   1                   2                   3
	#  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	# |       First code point or range         |  Len  |   Category  |
	# +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	calculation="($rangeStart * 2^11) + ($rangeLength * 2^5) + $rangeCategory"
	result=$( printf 'obase=16; %s' "$calculation" | bc )
	result="0x$result"

	if [ $outValuesCurrentLine -eq 0 ]
	then
		printf '\t%s' "$result"
	elif [ $outValuesCurrentLine -ge "$outValuesPerLineSearchTable" ]
	then
		printf ',\n\t%s' "$result"
		outValuesCurrentLine=0
	else
		printf ', %s' "$result"
	fi

	outValuesCurrentLine=$(( outValuesCurrentLine + 1 ))
	rangesCount=$(( rangesCount + 1 ))
}


output="
/// Starts at code point $(( lookupTableUpTo + 1 ))
static
const uint32_t categorySearchTable[ ] = {
"
printf '%s' "$output"


# shellcheck disable=2013
for entry in $( cut -f 1,3 -d ';' "$input" )
do
	cp=$( printf '%llu' "0x${entry%;*}" )
	category=$( mapCategory "${entry#*;}" )

	# First run
	if [ -z "$rangeStart" ]
	then
		[ "$cp" -le 31 ] && continue
		[ "$cp" -le $lookupTableUpTo ] && continue

		rangeStart=$cp
		rangeLength=0
		rangeNext=$(( cp + 1 ))
		rangeCategory=$category
		continue
	fi

	# category changed or length exceeds 6 bits or discontinuation
	if
		[ "$category" != "$rangeCategory" ] \
		|| [ "$rangeLength" -eq 127 ]       \
		|| [ "$cp" != "$rangeNext" ]
	then
		printRange
		rangeStart=$cp
		rangeLength=0
		rangeNext=$(( cp + 1 ))
		rangeCategory=$category
		continue
	fi

	rangeNext=$(( rangeNext + 1 ))
	rangeLength=$(( rangeLength + 1 ))
done

printRange

output="
};

/// == $rangesCount
const size_t categorySearchTableCount =
	sizeof(categorySearchTable) / sizeof(*categorySearchTable);
"
printf '%s' "$output"
