#pragma once

#if __clang__
	#define optional_TinyUTF8  _Nullable
	#define BeginHeader_TinyUTF8  _Pragma("clang assume_nonnull begin")
	#define EndHeader_TinyUTF8    _Pragma("clang assume_nonnull end")
#else
	#define optional_TinyUTF8
	#define BeginHeader_TinyUTF8
	#define EndHeader_TinyUTF8
#endif
