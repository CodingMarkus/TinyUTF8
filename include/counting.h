#pragma once

#include "header.h"
BeginHeader
// ============================================================================

/**
	@param string `\0` terminated UTF-8 string.
	@param[out] outByteCount Number of bytes in `string` w/o terminating `\0`.
	@param[out] outCPCount Number of code points in `string`.
	@param[out] outCarCount Number of characters in `string`.
	@param[out] outError In case of an error, where the error is written to.

	@returns
	Whether `string` could be successfully processed. If `false`, an error is
	written to `outError` unless `NULL`.

	@note
	In case of a failure, `outByteCount`, `outCPCount`, and `outCharCount` are
	still written to and represent the number of processed units before the
	error was discovered.

	@note
	All out values are optional and all out values not required should be set
	to `NULL`, because letting the function know which values are required
	allows for internal optimizations. E.g. obtaining the character count is
	requires some extra work, which is simply skipped if that value has not
	been requested.
*/
bool getStringCounts_TinyUTF8(
	const char * string,
	size_t * optional outByteCount,
	size_t * optional outCPCount,
	size_t * optional outCharCount,
	Error_TinyUTF8 * optional outError );


/**
	This function works the same as `getStringCounts_TinyUTF8()` but it does
	not perform any error checking and it assumes that no matter how many
	bytes it wants to write, `dst` has room for it.

	@param string `\0` terminated UTF-8 string.
	@param[out] outByteCount Number of bytes in `string` w/o terminating `\0`.
	@param[out] outCPCount Number of code points in `string`.
	@param[out] outCarCount Number of characters in `string`.

	@note
	All out values are optional and all out values not required should be set
	to `NULL`, because letting the function know which values are required
	allows for internal optimizations. E.g. obtaining the character count is
	requires some extra work, which is simply skipped if that value has not
	been requested.
*/
void unsafeGetStringCounts_TinyUTF8(
	const char * string,
	size_t * optional outByteCount,
	size_t * optional outCPCount,
	size_t * optional outCharCount );

// ============================================================================
EndHeader