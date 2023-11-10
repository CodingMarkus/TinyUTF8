#pragma once

#include "TinyUTF8/header_begin.h"

#undef Begin
#undef End

#if __clang__

	#define Begin  _Pragma("clang assume_nonnull begin")
	#define End    _Pragma("clang assume_nonnull end")

#else

	#define Begin
	#define End

#endif

#define initError() \
	if (outError) *outError = No_Error_TinyUTF8

#define throw(error) \
	if (outError) *outError = error ## _Error_TinyUTF8