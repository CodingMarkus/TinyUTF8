#include "testing.h"

#include "coding.h"

#include <string.h>

#include "code_begin.h"
Begin
// ============================================================================

static
void test_encodingDecoding( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		const size_t written = encodeCodePoint_TinyUTF8(
			cp, buffer, 4, &error
		);
		testAssertMsg(written > 0 && !error,
			"Error: %d", error
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		const size_t read = decodeCodePoint_TinyUTF8(
			buffer, 4, &decoded, &error
		);
		testAssertMsg(read > 0 && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(read == written, "%zu != %zu", read, written);
		testAssertMsg(decoded == cp,
			PRICP_TinyUTF8" != "PRICP_TinyUTF8, decoded, cp
		);
	}
}


static
void test_outOfRange( )
{
	char buffer[4] = { 0 };
	Error_TinyUTF8 error = No_Error_TinyUTF8;

	size_t written = encodeCodePoint_TinyUTF8(
		0x10FFFF + 1, buffer, 4, &error
	);
	testAssertMsg(written == 0 && error == CPOutOfRange_Error_TinyUTF8,
		"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
	);

	written = encodeCodePoint_TinyUTF8(
		CodePoint_None_TinyUTF8, buffer, 4, &error
	);
	testAssertMsg(written == 0 && error == CPOutOfRange_Error_TinyUTF8,
		"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
	);
}


static
void test_destTooSmall( )
{
	CodePoint_TinyUTF8 cps[ ] = {
		0x60, 0x600, 0x6000, 0x60000
	};
	size_t count = sizeof(cps) / sizeof(cps[0]);

	for (size_t i = 0; i < count; i++) {
		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		const size_t written = encodeCodePoint_TinyUTF8(
			cps[i], buffer, i, &error
		);
		testAssertMsg(written == 0 && error == DestTooSmall_Error_TinyUTF8,
			"%zu: Written: %zu, Error: %s",
			i, written, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_srcTooSmall( )
{
	CodePoint_TinyUTF8 cps[ ] = {
		0x60, 0x600, 0x6000, 0x60000
	};
	size_t count = sizeof(cps) / sizeof(cps[0]);

	for (size_t i = 0; i < count; i++) {
		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		const size_t written = encodeCodePoint_TinyUTF8(
			cps[i], buffer, i + 1, &error
		);
		testAssertMsg(written > 0 && !error,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		const size_t read = decodeCodePoint_TinyUTF8(
			buffer, i, &decoded, &error);
		testAssertMsg(read == 0 && error == SrcTooSmall_Error_TinyUTF8,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_invalidCoding( )
{
	const char * badStrings[ ] = {
		"\xA4",
		"\xC3\xC3",
		"\xE2\x82\xC3",
		"\xE2\x82\xE2",
		"\xE2\xC3\xAC",
		"\xE2\xE2\xAC",
		"\xF0\x9D\x84\xC3",
		"\xF0\x9D\x84\xE2",
		"\xF0\x9D\x84\xF0",
		"\xF0\x9D\xC3\x9E",
		"\xF0\x9D\xE2\x9E",
		"\xF0\x9D\xF0\x9E",
		"\xF0\xC3\x84\x9E",
		"\xF0\xE2\x84\x9E",
		"\xF0\xF0\x84\x9E",
		NULL
	};
	size_t i = 0;
	while (badStrings[i]) {
		const char * str = badStrings[i++];
		const size_t count = strlen(str);
		Error_TinyUTF8 error = No_Error_TinyUTF8;
		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		const size_t read = decodeCodePoint_TinyUTF8(
			str, count, &decoded, &error
		);
		testAssertMsg(read == 0, "%zu: Read: %zu", i - 1, read);
		testAssertMsg(error == InvalidCoding_Error_TinyUTF8,
			"%zu: Error: %s", i - 1, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_unsafeEncodingDecoding( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		char buffer[4] = { 0 };
		size_t written = unsafeEncodeCodePoint_TinyUTF8(cp, buffer);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		size_t read = unsafeDecodeCodePoint_TinyUTF8(buffer, &decoded);;
		testAssertMsg(read == written, "%zu != %zu", read, written);

		char buffer2[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		size_t written2 = encodeCodePoint_TinyUTF8(cp, buffer2, 4, &error);
		testAssert(written == written2);
		testAssert(0 == memcmp(buffer, buffer2, written));

		CodePoint_TinyUTF8 decoded2 = CodePoint_None_TinyUTF8;
		size_t read2 = decodeCodePoint_TinyUTF8(buffer, 4, &decoded2, &error);
		testAssert(read == read2);
		testAssert(decoded == decoded2);
	}
}


int main( )
{
	test_encodingDecoding();
	test_outOfRange();
	test_destTooSmall();
	test_srcTooSmall();
	test_invalidCoding();
	test_unsafeEncodingDecoding();
	return 0;
}

// ============================================================================
End
