#include "testing.h"

#include "coding.h"

#include "code.h"
Begin
// ============================================================================

static
void test_validCodePoint( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		bool expected = true;
		if ((cp & 0xFFFE) == 0xFFFE) expected = false;
		if (cp >= 0xD800 && cp <= 0xDFFF) expected = false;
		if (cp >= 0xFDD0 && cp <= 0xFDEF) expected = false;

		bool valid = isValidCodePoint_TinyUTF8(cp);
		testAssertMsg(valid == expected, PRICP_TinyUTF8" failed", cp);
	}
}


static
void test_encodingDecoding( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		// Skip surrogates
		if (cp == 0xD800) { cp = 0xDFFF; continue; }
		// Skip non-characters
		if (cp == 0xFDD0) { cp = 0xFDEF; continue; }
		if ((cp & 0xFFFF) == 0xFFFE) { cp++; continue; }

		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		const size_t written = encode_TinyUTF8(
			cp, buffer, 4, &error
		);

		testAssertMsg(written > 0 && !error,
			"Error: %d", error
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;

		const size_t read = decode_TinyUTF8(
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
void test_decodingEncoding( )
{
	struct {
		const char * bytes;
		CodePoint_TinyUTF8 cp;
	} samples[ ] = {
		{ "\x79", 0x79 },
		{ "\xC3\xA4", 0xE4 },
		{ "\xC2\xAE", 0xAE },
		{ "\xE2\x82\xAC", 0x20AC },
		{ "\xF0\x9D\x84\x9E", 0x1D11E },
		{ NULL, 0 }
	};

	for (size_t i = 0; samples[i].bytes; i++) {
		char buffer[4] = { 0 };
		size_t length = strlen(samples[i].bytes);
		Error_TinyUTF8 error = No_Error_TinyUTF8;
		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;

		const size_t read = decode_TinyUTF8(
			samples[i].bytes, length, &decoded, &error
		);

		testAssertMsg(read == length && !error,
			"Error: %s", nameOfError_TinyUTF8(error)
		);
		testAssertMsg(decoded == samples[i].cp,
			PRICP_TinyUTF8" != "PRICP_TinyUTF8, decoded, samples[i].cp
		);

		const size_t written = encode_TinyUTF8(
			decoded, buffer, 4, &error
		);

		testAssertMsg(written > 0 && !error,
			"Error: %d", error
		);
		testAssertMsg(read == written, "%zu != %zu", read, written);
		testAssert(0 == memcmp(buffer, samples[i].bytes, read));
	}
}


static
void test_invalidCP( )
{
	CodePoint_TinyUTF8 cps[ ] = {
		0xD800, 0xDFFF,
		0xFDD0, 0xFDEF,
		0xFFFE, 0xFFFF, 0x1FFFE, 0x1FFFF, 0x10FFFE, 0x10FFFF
	};
	size_t count = sizeof(cps) / sizeof(cps[0]);

	for (size_t i = 0; i < count; i++) {
		char buffer[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		const size_t written = encode_TinyUTF8(
			cps[i], buffer, i, &error
		);

		testAssertMsg(written == 0 && error == InvalidCP_Error_TinyUTF8,
			"%zu: Written: %zu, Error: %s",
			i, written, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_outOfRange( )
{
	char buffer[4] = { 0 };
	Error_TinyUTF8 error = No_Error_TinyUTF8;

	size_t written = encode_TinyUTF8(
		CodePoint_MAX_TinyUTF8 + 1, buffer, 4, &error
	);

	testAssertMsg(written == 0 && error == CPOutOfRange_Error_TinyUTF8,
		"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
	);

	written = encode_TinyUTF8(
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

		const size_t written = encode_TinyUTF8(
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

		const size_t written = encode_TinyUTF8(
			cps[i], buffer, i + 1, &error
		);

		testAssertMsg(written > 0 && !error,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);

		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;
		const size_t read = decode_TinyUTF8(
			buffer, i, &decoded, &error
		);

		testAssertMsg(read == 0 && error == SrcTooSmall_Error_TinyUTF8,
			"Written: %zu, Error: %s", written, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_invalidCoding( )
{
	const char * badStrings[ ] = {
		// Bad start of sequence
		"\xA4", // 0

		// Bad continuation of sequence
		"\xC3\xC3", // 1
		"\xE2\x82\xC3",
		"\xE2\x82\xE2",
		"\xE2\xC3\xAC",
		"\xE2\xE2\xAC", // 5
		"\xF0\x9D\x84\xC3",
		"\xF0\x9D\x84\xE2",
		"\xF0\x9D\x84\xF0",
		"\xF0\x9D\xC3\x9E",
		"\xF0\x9D\xE2\x9E", // 10
		"\xF0\x9D\xF0\x9E",
		"\xF0\xC3\x84\x9E",
		"\xF0\xE2\x84\x9E",
		"\xF0\xF0\x84\x9E",

		// Sequence outside of valid range
		"\xF5\x9D\x84\x9E", // 15

		// Not smallest representation
		"\xC0\x80", // 16
		"\xC0\xAF",
		"\xC1\xA4",
		"\xC1\xBF",
		"\xE0\x80\x80", // 20
		"\xE0\x80\xAF",
		"\xE0\x9F\xBF",
		"\xF0\x80\x80\xAF",
		"\xF0\x80\x80\x80",
		"\xF0\x8F\xBF\xBF", // 25

		NULL

	};
	size_t i = 0;
	while (badStrings[i]) {
		const char * str = badStrings[i++];
		const size_t count = strlen(str);
		Error_TinyUTF8 error = No_Error_TinyUTF8;
		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;

		const size_t read = decode_TinyUTF8(
			str, count, &decoded, &error
		);

		testAssertMsg(read == 0, "%zu: Read: %zu", i - 1, read);
		testAssertMsg(error == InvalidCoding_Error_TinyUTF8,
			"%zu: Error: %s", i - 1, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_invalidCoddedCP( )
{
	const char * badStrings[ ] = {
		// Surrogates
		"\xED\xA0\x80", // 0
		"\xED\xAD\xBF",
		"\xED\xAE\x80",
		"\xED\xAF\xBF",
		"\xED\xB0\x80",
		"\xED\xBE\x80", // 5
		"\xED\xBF\xBF",

		// Non-characters
		"\xEF\xB7\x90", // 7
		"\xEF\xB7\xAF",
		"\xEF\xBF\xBE",
		"\xEF\xBF\xBF", // 10
		"\xF4\x8F\xBF\xBE",
		"\xF4\x8F\xBF\xBF",

		NULL
	};
	size_t i = 0;
	while (badStrings[i]) {
		const char * str = badStrings[i++];
		const size_t count = strlen(str);
		Error_TinyUTF8 error = No_Error_TinyUTF8;
		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;

		const size_t read = decode_TinyUTF8(
			str, count, &decoded, &error
		);

		testAssertMsg(read == 0, "%zu: Read: %zu", i - 1, read);
		testAssertMsg(error == InvalidCodedCP_Error_TinyUTF8,
			"%zu: Error: %s", i - 1, nameOfError_TinyUTF8(error)
		);
	}
}


static
void test_unsafeEncodingDecoding( )
{
	for (CodePoint_TinyUTF8 cp = 0; cp <= 0x10FFFF; cp++) {
		// Skip surrogates
		if (cp == 0xD800) { cp = 0xDFFF; continue; }
		// Skip non-characters
		if (cp == 0xFDD0) { cp = 0xFDEF; continue; }
		if ((cp & 0xFFFF) == 0xFFFE) { cp++; continue; }

		char buffer[4] = { 0 };
		size_t written = unsafeEncode_TinyUTF8(cp, buffer);
		CodePoint_TinyUTF8 decoded = CodePoint_None_TinyUTF8;

		size_t read = unsafeDecode_TinyUTF8(buffer, &decoded);;

		testAssertMsg(read == written, "%zu != %zu", read, written);

		char buffer2[4] = { 0 };
		Error_TinyUTF8 error = No_Error_TinyUTF8;

		size_t written2 = encode_TinyUTF8(cp, buffer2, 4, &error);

		testAssert(written == written2);
		testAssert(0 == memcmp(buffer, buffer2, written));

		CodePoint_TinyUTF8 decoded2 = CodePoint_None_TinyUTF8;
		size_t read2 = decode_TinyUTF8(buffer, 4, &decoded2, &error);

		testAssert(read == read2);
		testAssert(decoded == decoded2);
	}
}


int main( )
{
	test_validCodePoint();
	test_encodingDecoding();
	test_decodingEncoding();

	test_invalidCP();
	test_outOfRange();
	test_destTooSmall();
	test_srcTooSmall();
	test_invalidCoding();
	test_invalidCoddedCP();

	test_unsafeEncodingDecoding();
	return 0;
}

// ============================================================================
End
