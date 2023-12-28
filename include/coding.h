#pragma once

#include "header_begin.h"
Begin

/**
	@param cp Code point to test.
*/
bool isValidCodePoint_TinyUTF8( CodePoint_TinyUTF8 cp );


/**
	@param cp Code point to encode.
	@param dst Memory where bytes are written to.
	@param maxOut Maximum number of bytes to write.
	@param[out] outError In case of an error, where the error is written to.

	@returns
	The number of bytes written or 0 in case of an error.
*/
size_t encodeCodePoint_TinyUTF8(
	CodePoint_TinyUTF8 cp, void * dst, size_t maxOut,
	Error_TinyUTF8 * optional outError );


/**
	@param src Memory where bytes are read from.
	@param maxIn Maximum number of bytes read write.
	@param[out] outCP Where the decoded code point is written to.
	@param[out] outError In case of an error, where the error is written to.

	@returns
	The number of bytes read or 0 in case of an error.
*/
size_t decodeCodePoint_TinyUTF8(
	const void * src, size_t maxIn, CodePoint_TinyUTF8 * outCP,
	Error_TinyUTF8 * optional outError );


/**
	This function works the same as `encodeCodePoint_TinyUTF8()` but it does
	not perform any error checking and it assumes that no matter how many
	bytes it wants to write, `dst` has room for it.

	@note
	You must only use this function with will formatted input data and
	sufficient output space, otherwise it's behavior is undefined and it may
	cause security vulnerabilities or even crash the process.

	@param cp Code point to encode.
	@param dst Memory where bytes are written to.

	@returns
	The number of bytes written.
*/
size_t unsafeEncodeCodePoint_TinyUTF8( CodePoint_TinyUTF8 cp, void * dst );


/**
	This function works the same as `decodeCodePoint_TinyUTF8()` but it does
	not perform any error checking and it assumes that no matter how many
	bytes it wants to read, `src` has that many bytes to offer.

	@note
	You must only use this function with will formatted input data and
	sufficient output space, otherwise it's behavior is undefined and it may
	cause security vulnerabilities or even crash the process.

	@param src Memory where bytes are read from.
	@param[out] outCP Where the decoded code point is written to.

	@returns
	The number of bytes read or 0 in case of an error.
*/
size_t unsafeDecodeCodePoint_TinyUTF8(
	const void * src, CodePoint_TinyUTF8 * outCP );



End
#include "header_end.h"
