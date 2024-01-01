#include "testing.h"

#include "counting.h"

#include "test_strings.h"

#include "code.h"
Begin
// ============================================================================

static
void test_countBytes( )
{
	size_t countBytes = 0;
	Error_TinyUTF8 error = No_Error_TinyUTF8;

	bool success = getStringCounts_TinyUTF8(
		composedUTF8TestString,
		&countBytes, NULL, NULL,
		&error
	);

	testAssertMsg(success && !error, "Error: %s", nameOfError_TinyUTF8(error));
	testAssertMsg(countBytes == 508, "Count: %zu", countBytes);

	success = getStringCounts_TinyUTF8(
		decomposedUTF8TestString,
		&countBytes, NULL, NULL,
		&error
	);

	testAssertMsg(success && !error, "Error: %s", nameOfError_TinyUTF8(error));
	testAssertMsg(countBytes == 525, "Count: %zu", countBytes);
}


static
void test_countCodePoints( )
{
	size_t countCP = 0;
	Error_TinyUTF8 error = No_Error_TinyUTF8;

	bool success = getStringCounts_TinyUTF8(
		composedUTF8TestString,
		NULL, &countCP, NULL,
		&error
	);

	testAssertMsg(success && !error, "Error: %s", nameOfError_TinyUTF8(error));
	testAssertMsg(countCP == 212, "Count: %zu", countCP);

	success = getStringCounts_TinyUTF8(
		decomposedUTF8TestString,
		NULL, &countCP, NULL,
		&error
	);

	testAssertMsg(success && !error, "Error: %s", nameOfError_TinyUTF8(error));
	testAssertMsg(countCP == 242, "Count: %zu", countCP);
}


int main( )
{
	test_countBytes();
	test_countCodePoints();
	return 0;
}

// ============================================================================
End
