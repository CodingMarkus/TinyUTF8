#include "properties.h"

#include "properties+categories.h"

#include "code.h"
Begin
// ============================================================================

public
CodePointCategory_TinyUTF8 categoryOf_TinyUTF8 (
	CodePoint_TinyUTF8 cp )
{
	if (cp <= 31) return Cc_CodePointCategory_TinyUTF8;

	return Cc_CodePointCategory_TinyUTF8;
}


public
bool isCharacter_TinyUTF8 ( CodePoint_TinyUTF8 cp )
{
	return false;
}

// ============================================================================
End
