#include "properties.h"

#include "properties+categories.h"

#include <stdio.h>
#include <unistd.h>

#include "code.h"
Begin
// ============================================================================

public
CodePointCategory_TinyUTF8 categoryOf_TinyUTF8 (
	CodePoint_TinyUTF8 cp )
{
	if (cp <= 31) return Cc_CodePointCategory_TinyUTF8;

	if (cp <= categoryLookupTableEndsAt) {
		div_t divisionResult = div((int)(cp - 32), 3);
		uint16_t entry = categoryLookupTable[divisionResult.quot];
		switch (divisionResult.rem) {
			case 0: return ((entry >> 10) & 0x1F);
			case 1: return ((entry >>  5) & 0x1F);
		}
		return (entry & 0x1F);
	}

	if (cp > CodePoint_MAX_TinyUTF8) return Invalid_CodePointCategory_TinyUTF8;

	size_t left = 0;
	size_t right = categorySearchTableCount - 1;
	while (left != right) {
		size_t middle = (left + right + 1) / 2;
		uint32_t entry = categorySearchTable[middle];
		CodePoint_TinyUTF8 rangeStart = entry >> 11;
		if (rangeStart > cp) {
			right = middle - 1;
		} else {
			left = middle;
		}
	}

	uint32_t entry = categorySearchTable[left];
	CodePoint_TinyUTF8 rangeStart = entry >> 11;
	CodePoint_TinyUTF8 rangeEnd = rangeStart + (entry & 0x3F);
	if (cp < rangeStart || cp > rangeEnd) {
		return Cn_CodePointCategory_TinyUTF8;
	}
	return ((entry >> 6) & 0x1F);
}


public
bool isCharacter_TinyUTF8 ( CodePoint_TinyUTF8 cp )
{
	CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(cp);

	if (category >= Lu_CodePointCategory_TinyUTF8
		&& category <= Lo_CodePointCategory_TinyUTF8)
	{
		return true;
	}

	if (category >= Nd_CodePointCategory_TinyUTF8
		&& category <= Zs_CodePointCategory_TinyUTF8)
	{
		return true;
	}

	return false;
}

// ============================================================================
End
