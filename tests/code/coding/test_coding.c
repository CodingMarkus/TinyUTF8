#include "testing.h"

#include "TinyUTF8/coding.h"

#include "code_begin.h"
Begin
// ============================================================================

static
void test_encodingDecoding( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		size_t written = encodeCodePoint_TinyUTF8(cp, buffer, 4, &error);
		testAssertMsg(written > 0 && !error,
			"Error: %d", error
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		size_t read = decodeCodePoint_TinyUTF8(buffer, 4, &decoded, &error);
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

		size_t written = encodeCodePoint_TinyUTF8(
			cps[i], buffer, i, &error
		);
		testAssertMsg(written == 0 && error == DestTooSmall_Error_TinyUTF8,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
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

		size_t written = encodeCodePoint_TinyUTF8(
			cps[i], buffer, i + 1, &error
		);
		testAssertMsg(written > 0 && !error,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		size_t read = decodeCodePoint_TinyUTF8(
			buffer, i, &decoded, &error);
		testAssertMsg(read == 0 && error == SrcTooSmall_Error_TinyUTF8,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_invalidCoding( )
{

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
