#pragma once

#include "internal/categories.h"

#include "header.h"
BeginHeader
// ============================================================================

CodePointCategory_TinyUTF8 categoryOf_TinyUTF8 (
	CodePoint_TinyUTF8 cp );


/**
	Whether the code point describes a printable character.
	Code points that are intended to be combined with other code points to
	form a single character, as well as control code points and code points
	controlling text flow, are not considered printable characters. "Printable"
	does not imply that anything is actually printed to as a space is also a
	printable character, a line break on the other hand is not, as it is  a
	control code point and controls text flow.
*/
bool isCharacter_TinyUTF8 ( CodePoint_TinyUTF8 cp );


/**
	Some characters do not have a dedicated case,
	those are considered neither upper nor lower case.
*/
bool isUpperCaseCharacter_TinyUTF8 ( CodePoint_TinyUTF8 cp );


/**
	Some characters do not have a dedicated case,
	those are considered neither upper nor lower case.
*/
bool isLowerCaseCharacter_TinyUTF8 ( CodePoint_TinyUTF8 cp );

// ============================================================================
EndHeader