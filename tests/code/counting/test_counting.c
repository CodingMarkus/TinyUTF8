#include "testing.h"

#include "counting.h"

#include "testData_stringsNF.h"
#include "testData_stringsBad.h"

#include "code.h"
Begin
// ============================================================================

static
void test_count( )
{
	for (size_t i = 0; testStringsNFC[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFC[i].string,
			&count, NULL, NULL,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFC[i].byteCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFC[i].byteCount
		);
	}

	for (size_t i = 0; testStringsNFD[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFD[i].string,
			&count, NULL, NULL,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFD[i].byteCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFD[i].byteCount
		);
	}
}


static
void test_countCodePoints( )
{
	for (size_t i = 0; testStringsNFC[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFC[i].string,
			NULL, &count, NULL,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFC[i].codepointCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFC[i].codepointCount
		);
	}

	for (size_t i = 0; testStringsNFD[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFD[i].string,
			NULL, &count, NULL,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFD[i].codepointCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFD[i].codepointCount
		);
	}

}


static
void test_countCharacters( )
{
	for (size_t i = 0; testStringsNFC[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFC[i].string,
			NULL, NULL, &count,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFC[i].charaterCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFC[i].charaterCount
		);
	}

	for (size_t i = 0; testStringsNFD[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsNFD[i].string,
			NULL, NULL,&count,
			&error
		);

		testAssertMsg(success && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(count == testStringsNFD[i].charaterCount,
			"Count: %zu, Expected: %zu",
			count, testStringsNFD[i].charaterCount
		);
	}

}


static
void test_badStrings( )
{
	for (size_t i = 0; testStringsBad[i].string; i++) {
		size_t count = 0;
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		bool success = getStringCounts_TinyUTF8(
			testStringsBad[i].string,
			&count, &count, &count,
			&error
		);
		testAssertMsg(!success, "%zu incorrectly succeeded", i);
		testAssertMsg(error == testStringsBad[i].expectedError,
			"%zu: Error: %s, Expected: %s",
			i, nameOfError_TinyUTF8(error),
			nameOfError_TinyUTF8(testStringsBad[i].expectedError)
		);
	}
}


int main( )
{
	test_count();
	test_countCodePoints();
	test_countCharacters();
	test_badStrings();
	return 0;
}

// ============================================================================
End
