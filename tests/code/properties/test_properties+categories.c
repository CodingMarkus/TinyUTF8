#include "testing.h"

#include "properties.h"

#include "test_properties+categories_data.h"

#include "code.h"
Begin
// ============================================================================

void test_categoryMapping( )
{
	for (size_t i = 0; i < categoryTestTableCount; i++) {
		CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(
			categoryTestTable[i].cp
		);
		testAssertMsg(category == categoryTestTable[i].category,
			"0x%zX: Expected: %d, Got: %d",
			i, categoryTestTable[i].category, category
		);
	}
}


void test_categoryMappingUnassigned( )
{
	CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(0x10FFFC);
	testAssertMsg(Cn_CodePointCategory_TinyUTF8 == category,
		"Expected: %d, Got: %d",
		Cn_CodePointCategory_TinyUTF8, category
	);
}


void test_categoryMappingInvalid( )
{
	CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(
		CodePoint_MAX_TinyUTF8 + 1
	);
	testAssertMsg(Invalid_CodePointCategory_TinyUTF8 == category,
		"Expected: %d, Got: %d",
		Invalid_CodePointCategory_TinyUTF8, category
	);
}


// ============================================================================
End
