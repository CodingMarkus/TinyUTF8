#pragma once

#include "stdc.h"
#include "types.h"

/**
	Highest possible code point.
*/
#define CodePoint_MAX_TinyUTF8  ((CodePoint_TinyUTF8)0x10FFFF)


/**
	Used as a placeholder for no code point.
*/
#define CodePoint_None_TinyUTF8  ((CodePoint_TinyUTF8)UINT32_MAX)


/**
	Maximum number of bytes for a single UTF-8 encoded code point
*/
#define UTF8_Bytes_MAX_TinyUTF8  4

/**
	Used for printing code points in `printf()`.
*/
#define PRIuCP_TinyUTF8  PRIuLEAST32
#define PRIXCP_TinyUTF8  PRIXLEAST32
#define PRICP_TinyUTF8   "U+%"PRIXLEAST32
