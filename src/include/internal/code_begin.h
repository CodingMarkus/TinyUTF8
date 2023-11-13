#pragma once

#if __clang__
	#define BeginCode_TinyUTF8  _Pragma("clang assume_nonnull begin")
	#define EndCode_TinyUTF8    _Pragma("clang assume_nonnull end")
#else
	#define BeginCode_TinyUTF8
	#define EndCode_TinyUTF8
#endif


#ifndef public_TinyUTF8
	#define public_TinyUTF8
#endif

#ifndef internal_TinyUTF8
	#define internal_TinyUTF8
#endif
