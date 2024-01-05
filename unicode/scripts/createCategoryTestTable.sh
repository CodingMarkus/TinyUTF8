#!/bin/sh
set -e -u

. "$( dirname "$0")/shared.inc"

input=$( checkForUnicodeDataFile )

printHeaderComment

output="
#include \"internal/types.h\"
#include \"internal/categories.h\"

static
const struct {
	CodePoint_TinyUTF8 cp;
	CodePointCategory_TinyUTF8 category;
} categoryTestTable[ ] = {
"
printf '%s' "$output"

firstRun=

# shellcheck disable=2013
for entry in $( cut -f 1,3 -d ';' "$input" )
do
	cp="0x${entry%;*}"
	category="${entry#*;}_CodePointCategory_TinyUTF8"

	if [ -z "$firstRun" ]
	then
		firstRun=false
	else
		printf ',\n'
	fi

	printf '\t{ %s, %s }' "$cp" "$category"
done

output="
};

const size_t categoryTestTableCount =
	sizeof(categoryTestTable) / sizeof(*categoryTestTable);
"
printf '%s' "$output"
