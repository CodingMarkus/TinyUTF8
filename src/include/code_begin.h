#pragma once

#include "header_begin.h"

#undef Begin
#undef End

/**
	Sets some compiler flags at the beginning of code.
*/
#define Begin  BeginCode_TinyUTF8

/**
	Resets some compiler flags at the end of code.
*/
#define End    EndCode_TinyUTF8


/**
	Mark a symbol as public.
*/
#define public public_TinyUTF8

/**
	Mark a symbol as internal.
*/
#define internal internal_TinyUTF8



#define initError() \
	if (outError) *outError = No_Error_TinyUTF8

#define throw(error) \
	if (outError) *outError = error ## _Error_TinyUTF8



#include "internal/code_begin.h"
