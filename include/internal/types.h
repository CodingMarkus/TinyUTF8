#pragma once

#include "stdc.h"
#include "errors.h"

typedef enum Error_TinyUTF8 Error_TinyUTF8;

/**
	Representing an Unicode code point.
*/
typedef uint_least32_t  CodePoint_TinyUTF8;


/**
	Highest possible code point.
*/
#define CodePoint_MAX_TinyUTF8  ((CodePoint_TinyUTF8)0x10FFFF)


/**
	Used as a placeholder for no code point.
*/
#define CodePoint_None_TinyUTF8  ((CodePoint_TinyUTF8)UINT32_MAX)


/**
	Used for printing code points in `printf()`.
*/
#define PRIuCP_TinyUTF8  PRIuLEAST32
#define PRIXCP_TinyUTF8  PRIXLEAST32
#define PRICP_TinyUTF8   "U+%"PRIXLEAST32