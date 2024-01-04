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

// ============================================================================
End
