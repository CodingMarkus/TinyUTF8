#pragma once

#include "internal/const.h"

/**
	Marking a pointer optional allows it to be NULL. By default all pointers
	in TinyUTF8 are assumed to never be NULL, unless marked optional.
*/
#define optional  optional_TinyUTF8

/**
	Sets some compiler flags at the beginning of a header.
*/
#define BeginHeader  BeginHeader_TinyUTF8

/**
	Resets some compiler flags at the end of a header.
*/
#define EndHeader  EndHeader_TinyUTF8


#include "internal/header.h"
