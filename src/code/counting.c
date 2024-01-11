#include "counting.h"

#include "coding.h"
#include "properties.h"

#include "code.h"
Begin
// ============================================================================

public
bool getStringCounts_TinyUTF8(
	const char * string,
	size_t * optional outByteCount,
	size_t * optional outCPCount,
	size_t * optional outCharCount,
	Error_TinyUTF8 * optional outError )
{
	initError();

	bool result = true;
	size_t cpCount = 0;
	size_t byteCount = 0;
	size_t charCount = 0;

	size_t minBytesLeft = 0;
	const char * ptr = string;

	for (;;) {
		while (minBytesLeft < UTF8_Bytes_MAX_TinyUTF8
			&& ptr[minBytesLeft] != 0)
		{
				minBytesLeft++;
		}
		if (minBytesLeft == 0) break;

		CodePoint_TinyUTF8 cp = InvalidCodedCP_Error_TinyUTF8;
		size_t bytesUsed = decode_TinyUTF8(
			ptr, minBytesLeft, &cp, outError
		);

		if (bytesUsed == 0) { result = false; break; }

		ptr += bytesUsed;
		minBytesLeft -= bytesUsed;

		cpCount++;
		byteCount += bytesUsed;
		if (outCharCount && isCharacter_TinyUTF8(cp)) charCount++;
	}

	if (outByteCount) *outByteCount = byteCount;
	if (outCPCount) *outCPCount = cpCount;
	if (outCharCount) *outCharCount = charCount;
	return result;
}


public
void unsafeGetStringCounts_TinyUTF8(
	const char * string,
	size_t * optional outByteCount,
	size_t * optional outCPCount,
	size_t * optional outCharCount )
{
	size_t cpCount = 0;
	size_t byteCount = 0;
	size_t charCount = 0;

	size_t minBytesLeft = 0;
	const char * ptr = string;

	for (;;) {
		while (minBytesLeft < UTF8_Bytes_MAX_TinyUTF8
			&& ptr[minBytesLeft] != 0)
		{
			minBytesLeft++;
		}
		if (minBytesLeft == 0) break;

		CodePoint_TinyUTF8 cp = InvalidCodedCP_Error_TinyUTF8;
		size_t bytesUsed = unsafeDecode_TinyUTF8(ptr, &cp);

		ptr += bytesUsed;
		minBytesLeft -= bytesUsed;

		cpCount++;
		byteCount += bytesUsed;
		if (outCharCount && isCharacter_TinyUTF8(cp)) charCount++;
	}

	if (outByteCount) *outByteCount = byteCount;
	if (outCPCount) *outCPCount = cpCount;
	if (outCharCount) *outCharCount = charCount;
}

// ============================================================================
End
