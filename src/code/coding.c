#include "coding.h"

#include "code_begin.h"
Begin
// ============================================================================

static inline
bool isValidCodePoint( CodePoint_TinyUTF8 cp )
{
	if ((cp & 0xFFFE) == 0xFFFE) return false;
	if (cp >= 0xD800 && cp <= 0xDFFF) return false;
	if (cp >= 0xFDD0 && cp <= 0xFDEF) return false;
	if (cp >= 0x10FFFF) return false;
	return true;
}


public
bool isValidCodePoint_TinyUTF8( CodePoint_TinyUTF8 cp )
{
	return isValidCodePoint(cp);
}


public
size_t encodeCodePoint_TinyUTF8(
	CodePoint_TinyUTF8 cp, void * dst, size_t maxOut,
	Error_TinyUTF8 * optional outError )
{
	initError();
	uint8_t * ptr = dst;

	if (cp <= 0x7F) {
		if (maxOut < 1) {
			throw(DestTooSmall);
			return 0;
		}
		*ptr = (uint8_t)cp;
		return 1;
	}

	if (cp <= 0x7FF) {
		if (maxOut < 2) {
			throw(DestTooSmall);
			return 0;
		}
		*(ptr++) = (uint8_t)(0xC0 | (cp >> 6));
		*ptr = 0x80 | (cp & 0x3F);
		return 2;
	}

	if (cp <= 0xFFFF) {
		if (maxOut < 3) {
			throw(DestTooSmall);
			return 0;
		}
		*(ptr++) = (uint8_t)(0xE0 | (cp >> 12));
		*(ptr++) = 0x80 | ((cp >> 6) & 0x3F);
		*ptr = 0x80 | (cp & 0x3F);
		return 3;
	}

	if (cp <= 0x10FFFF) {
		if (maxOut < 4) {
			throw(DestTooSmall);
			return 0;
		}
		*(ptr++) = (uint8_t)(0xF0 | (cp >> 18));
		*(ptr++) = 0x80 | ((cp >> 12) & 0x3F);
		*(ptr++) = 0x80 | ((cp >> 6) & 0x3F);
		*ptr = 0x80 | (cp & 0x3F);
		return 4;
	}

	throw(CPOutOfRange);
	return 0;
}


public
size_t unsafeEncodeCodePoint_TinyUTF8( CodePoint_TinyUTF8 cp, void * dst )
{
	uint8_t * ptr = dst;

	if (cp <= 0x7F) {
		*ptr = (uint8_t)cp;
		return 1;
	}

	if (cp <= 0x7FF) {
		*(ptr++) = (uint8_t)(0xC0 | (cp >> 6));
		*ptr = 0x80 | (cp & 0x3F);
		return 2;
	}

	if (cp <= 0xFFFF) {
		*(ptr++) = (uint8_t)(0xE0 | (cp >> 12));
		*(ptr++) = 0x80 | ((cp >> 6) & 0x3F);
		*ptr = 0x80 | (cp & 0x3F);
		return 3;
	}

	*(ptr++) = (uint8_t)(0xF0 | (cp >> 18));
	*(ptr++) = 0x80 | ((cp >> 12) & 0x3F);
	*(ptr++) = 0x80 | ((cp >> 6) & 0x3F);
	*ptr = 0x80 | (cp & 0x3F);
	return 4;
}



public
size_t decodeCodePoint_TinyUTF8(
	const void * src, size_t maxIn, CodePoint_TinyUTF8 * outCP,
	Error_TinyUTF8 * optional outError )
{
	initError();
	const uint8_t * ptr = src;
	*outCP = CodePoint_None_TinyUTF8;

	if (maxIn < 1) {
		throw(SrcTooSmall);
		return 0;
	}
	const uint8_t firstByte = *ptr;

	if ((firstByte & 0x80) == 0) {
		*outCP = firstByte;
		return 1;
	}

	if ((firstByte & 0xE0) == 0xC0) {
		if (maxIn < 2) {
			throw(SrcTooSmall);
			return 0;
		}

		CodePoint_TinyUTF8 cp = firstByte & 0x1F;
		cp <<= 6;

		CodePoint_TinyUTF8 nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}

		cp |= (nextByte & 0x3F);
		if (cp <= 0x7F) {
			throw(InvalidCoding);
			return 0;
		}

		*outCP = cp;
		return 2;
	}

	if ((firstByte & 0xF0) == 0xE0) {
		if (maxIn < 3) {
			throw(SrcTooSmall);
			return 0;
		}

		CodePoint_TinyUTF8 cp = firstByte & 0x0F;
		cp <<= 12;

		CodePoint_TinyUTF8 nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}
		cp |= (nextByte & 0x3F) << 6;

		nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}

		cp |= (nextByte & 0x3F);
		if (cp <= 0x7FF) {
			throw(InvalidCoding);
			return 0;
		}
		if ((cp >= 0xD800 && cp <= 0xDFFF)
			|| (cp >= 0xFDD0 && cp <= 0xFDEF)
			|| (cp >= 0xFFFE))
		{
			throw(InvalidCodedCP);
			return 0;
		}

		*outCP = cp;
		return 3;
	}

	if ((firstByte & 0xF8) == 0xF0) {
		if (maxIn < 4) {
			throw(SrcTooSmall);
			return 0;
		}

		if ((firstByte & 0x07) >= 5) {
			throw(InvalidCoding);
			return 0;
		}

		CodePoint_TinyUTF8 cp = firstByte & 0x07;
		cp <<= 18;

		CodePoint_TinyUTF8 nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}
		cp |= (nextByte & 0x3F) << 12;

		nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}
		cp |= (nextByte & 0x3F) <<6;

		nextByte = *(++ptr);
		if ((nextByte & 0xC0) != 0x80) {
			throw(InvalidCoding);
			return 0;
		}

		cp |= (nextByte & 0x3F);
		if (cp <= 0xFFFF) {
			throw(InvalidCoding);
			return 0;
		}
		if ((cp & 0xFFFE) == 0xFFFE) {
			throw(InvalidCodedCP);
			return 0;
		}

		*outCP = cp;
		return 4;
	}

	throw(InvalidCoding);
	return 0;
}


public
size_t unsafeDecodeCodePoint_TinyUTF8(
	const void * src, CodePoint_TinyUTF8 * outCP )
{
	const uint8_t * ptr = src;
	const uint8_t firstByte = *ptr;

	if ((firstByte & 0x80) == 0) {
		*outCP = firstByte;
		return 1;
	}

	if ((firstByte & 0xE0) == 0xC0) {
		CodePoint_TinyUTF8 cp = firstByte & 0x1F;
		cp <<= 6;

		CodePoint_TinyUTF8 nextByte = *(++ptr);
		*outCP = cp | (nextByte & 0x3F);
		return 2;
	}

	if ((firstByte & 0xF0) == 0xE0) {
		CodePoint_TinyUTF8 cp = firstByte & 0x0F;
		cp <<= 12;

		CodePoint_TinyUTF8 nextByte = *(++ptr);
		cp |= (nextByte & 0x3F) << 6;

		nextByte = *(++ptr);
		*outCP = cp | (nextByte & 0x3F);
		return 3;
	}

	CodePoint_TinyUTF8 cp = firstByte & 0x07;
	cp <<= 18;

	CodePoint_TinyUTF8 nextByte = *(++ptr);
	cp |= (nextByte & 0x3F) << 12;

	nextByte = *(++ptr);
	cp |= (nextByte & 0x3F) <<6;

	nextByte = *(++ptr);
	*outCP = cp | (nextByte & 0x3F);
	return 4;
}


// ============================================================================
End
