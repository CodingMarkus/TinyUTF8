#pragma once

enum Error_TinyUTF8 {

	/**
		Placeholder for "no error".
	*/
	No_Error_TinyUTF8,

	/**
		Source of a read operation is too small
		for the amount of data to be read.
	*/
	SrcTooSmall_Error_TinyUTF8,

	/**
		Destination of a write operation is too small
		for the amount of data to be written.
	*/
	DestTooSmall_Error_TinyUTF8,

	/**
		A code point argument was beyond U+10FFFF.
	*/
	CPOutOfRange_Error_TinyUTF8,

	/**
		Invalid UTF-8 byte stream.
	*/
	InvalidCoding_Error_TinyUTF8,

	/**
		UTF-8 byte stream encodes a code point that is not allowed to be
		encoded in UTF-8, e.g. surrogates..
	*/
	InvalidCodedCP_Error_TinyUTF8,
};


const char * nameOfError_TinyUTF8( enum Error_TinyUTF8 error );