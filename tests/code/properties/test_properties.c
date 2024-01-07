#include "testing.h"

#include "properties.h"

#include "test_properties+categories.h"

#include "code.h"
Begin
// ============================================================================

static
void test_categoryMapping( )
{
	for (size_t i = 0; i < categoryTestTableCount; i++) {
		CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(
			categoryTestTable[i].cp
		);
		testAssertMsg(category == categoryTestTable[i].category,
			"0x%X: Expected: %d, Got: %d",
			categoryTestTable[i].cp, categoryTestTable[i].category, category
		);
	}
}


static
void test_categoryMappingUnassigned( )
{
	CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(0x10FFFC);
	testAssertMsg(category == Cn_CodePointCategory_TinyUTF8,
		"Expected: %d, Got: %d",
		Cn_CodePointCategory_TinyUTF8, category
	);
}


static
void test_categoryMappingInvalid( )
{
	CodePointCategory_TinyUTF8 category = categoryOf_TinyUTF8(
		CodePoint_MAX_TinyUTF8 + 1
	);
	testAssertMsg(category == Invalid_CodePointCategory_TinyUTF8,
		"Expected: %d, Got: %d",
		Invalid_CodePointCategory_TinyUTF8, category
	);
}


static
void test_isCharacter( )
{
	for (size_t i = 0; i < categoryTestTableCount; i++) {
		bool isChar = isCharacter_TinyUTF8(categoryTestTable[i].cp);
		bool expected = true;
		switch (categoryTestTable[i].category) {
			case Mn_CodePointCategory_TinyUTF8:
			case Mc_CodePointCategory_TinyUTF8:
			case Me_CodePointCategory_TinyUTF8:
			case Zl_CodePointCategory_TinyUTF8:
			case Zp_CodePointCategory_TinyUTF8:
			case Cc_CodePointCategory_TinyUTF8:
			case Cf_CodePointCategory_TinyUTF8:
			case Cs_CodePointCategory_TinyUTF8:
			case Co_CodePointCategory_TinyUTF8:
			case Cn_CodePointCategory_TinyUTF8: expected = false; break;
			default: break;
		}
		testAssertMsg(isChar == expected,
			"0x%X: %d != %d",
			categoryTestTable[i].cp, isChar, expected
		);
	}
}


static
void test_isUpperCase( )
{
	for (size_t i = 0; i < categoryTestTableCount; i++) {
		bool isUpper = isUpperCaseCharacter_TinyUTF8(categoryTestTable[i].cp);
		bool expected = false;
		switch (categoryTestTable[i].category) {
			case Lu_CodePointCategory_TinyUTF8: expected = true; break;
			default: break;
		}
		testAssertMsg(isUpper == expected,
			"0x%X: %d != %d",
			categoryTestTable[i].cp, isUpper, expected
		);
	}
}


static
void test_isLowerCase( )
{
	for (size_t i = 0; i < categoryTestTableCount; i++) {
		bool isLower = isLowerCaseCharacter_TinyUTF8(categoryTestTable[i].cp);
		bool expected = false;
		switch (categoryTestTable[i].category) {
			case Ll_CodePointCategory_TinyUTF8: expected = true; break;
			default: break;
		}
		testAssertMsg(isLower == expected,
			"0x%X: %d != %d",
			categoryTestTable[i].cp, isLower, expected
		);
	}
}


int main( )
{
	test_categoryMapping();
	test_categoryMappingUnassigned();
	test_categoryMappingInvalid();

	test_isCharacter();
	test_isUpperCase();
	test_isLowerCase();

	return 0;
}

// ============================================================================
End
