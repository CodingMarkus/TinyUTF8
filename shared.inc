#!/bin/sh
set -e

# shellcheck disable=2034
readonly LIBNAME='libTinyUTF8.a'

NEWLINE=$( printf '\n_' ); NEWLINE=${NEWLINE%_}; readonly NEWLINE


syntaxError()
{
	_errorMsg=$1

	printf '\nSyntax Error: %s!\n' "$_errorMsg" >&2
	printHelp 1
}


error()
{
	_errorMsg=$1

	printf '\nError: %s!\n' "$_errorMsg" >&2
	exit 1
}



findCompileFlags()
{
	_srcFile=$1
	_stopDir=$2

	_flagsdir=$( dirname "$_srcFile" )
	while :
	do
		if [ -f "$_flagsdir/compile_flags.txt" ]
		then
			printf %s "$_flagsdir/compile_flags.txt"
			return 0
		fi
		if [ "$_flagsdir" = "$_stopDir" ]
		then
			echo "compile_flags.txt not found for \"$_srcFile\"" >&2
			return 1
		fi
		_flagsdir=$( dirname "$_flagsdir" )
	done
}


quote()
{
	_toQuote=$1

	case $_toQuote in
		*[\ \']*)
			printf "'%s'" "$( printf "%s" "$_toQuote" | sed "s/'/'\\\\''/g")"
		;;
		*) printf '%s' "$_toQuote"
	esac
}


anyFileIsNewerThan()
{
	compareTo=$1

	shift
	[ -n "$( find "$@" -newer "$compareTo" )" ]
}


objectFileIsOutdated()
{
	_objectFile=$1
	_srcFile=$2
	_flagsFileContent=$3
	_flagsFileDir=$4

	# If the file does not exist, it's always outdated
	[ -f "$_objectFile" ] || return 0

	(
		[ -n "$_flagsFileDir" ] && cd "$_flagsFileDir"

		if ! depList=$( eval "clang -MM $_flagsFileContent \"$_srcFile\"" )
		then
			exit 1
		fi

		depList=$(
			printf '%s' "$depList" | xargs -n1 | grep -v '^$' \
			| grep -v '\.o:$' | sed 's/\(.*\)/"\1" /' | tr -d '\n'
		)
		eval "anyFileIsNewerThan \"$1\" $depList"
	)
}


parseCfgFile()
{
	_varName=$1
	_cfgFile=$2

	_filecontent=
	while IFS= read -r _line
	do
		[ -z "$_line" ] && continue
		_filecontent="$_filecontent $( quote "$_line" )"
	done <"$_cfgFile"
	eval "$_varName=\$_filecontent"
}


shouldLinkAddressSanitizer()
{
	_buildArgs=$1

	case $_buildArgs in
		*'-fsanitize=address'*) return 0
	esac
	return 1
}
