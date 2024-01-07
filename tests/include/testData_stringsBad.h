#include <stdlib.h>
#include "internal/errors.h"

/*
	Create UTF-8 from UTF-32 using the following JS code:

	const inputValues= [
		// 'u+DFFFu+00'
	];
	for (var i = 0; i < inputValues.length; i++) {
		const utf32String = inputValues[i];
		const utf32Array = utf32String.split('u+').filter(Boolean);
		const utf8Array = utf32Array.map(utf32 => {
			const codePoint = parseInt(utf32, 16);
			if (codePoint < 0x80) {
				return codePoint;
			} else if (codePoint < 0x800) {
				return [0xc0 | (codePoint >> 6),
					0x80 | (codePoint & 0x3f)];
			} else if (codePoint < 0x10000) {
				return [0xe0 | (codePoint >> 12),
					0x80 | ((codePoint >> 6) & 0x3f),
					0x80 | (codePoint & 0x3f)];
			} else {
				return [0xf0 | (codePoint >> 18),
					0x80 | ((codePoint >> 12) & 0x3f),
					0x80 | ((codePoint >> 6) & 0x3f),
					0x80 | (codePoint & 0x3f)];
			}
		});
		const utf8Result = utf8Array.flat().map(
		code => `0x${code.toString(16).padStart(2, '0')}`);
		console.log(utf8Result.join(', '));
	}

	E.g. run at: https://reqbin.com/code/javascript

*/


static struct {
	const char * string;
	enum Error_TinyUTF8 expectedError;
} const testStringsBad[ ] = {

	// Surrogates
	{ "\xED\xA0\x80", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xAD\xBF", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xAE\x80", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xAF\xBF", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xB0\x80", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xBE\x80",  InvalidCodedCP_Error_TinyUTF8 },
	{ "\xED\xBF\xBF", InvalidCodedCP_Error_TinyUTF8 },

	// Non-characters
	{ "\xEF\xB7\x90", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xEF\xB7\xAF", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xEF\xBF\xBE", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xEF\xBF\xBF", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xF4\x8F\xBF\xBE", InvalidCodedCP_Error_TinyUTF8 },
	{ "\xF4\x8F\xBF\xBF", InvalidCodedCP_Error_TinyUTF8 },


	// Bad start of sequence
	{ "\xA4", InvalidCoding_Error_TinyUTF8 },

	// Bad continuation of sequence
	{ "\xC3\xC3", InvalidCoding_Error_TinyUTF8 },
	{ "\xE2\x82\xC3", InvalidCoding_Error_TinyUTF8 },
	{ "\xE2\x82\xE2", InvalidCoding_Error_TinyUTF8 },
	{ "\xE2\xC3\xAC", InvalidCoding_Error_TinyUTF8 },
	{ "\xE2\xE2\xAC", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\x84\xC3", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\x84\xE2", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\x84\xF0", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\xC3\x9E", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\xE2\x9E", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x9D\xF0\x9E", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\xC3\x84\x9E", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\xE2\x84\x9E", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\xF0\x84\x9E", InvalidCoding_Error_TinyUTF8 },

	// Sequence outside of valid range
	{ "\xF5\x9D\x84\x9E", InvalidCoding_Error_TinyUTF8 },

	// Not smallest representation
	{ "\xC0\x80", InvalidCoding_Error_TinyUTF8 },
	{ "\xC0\xAF", InvalidCoding_Error_TinyUTF8 },
	{ "\xC1\xA4", InvalidCoding_Error_TinyUTF8 },
	{ "\xC1\xBF", InvalidCoding_Error_TinyUTF8 },
	{ "\xE0\x80\x80", InvalidCoding_Error_TinyUTF8 },
	{ "\xE0\x80\xAF", InvalidCoding_Error_TinyUTF8 },
	{ "\xE0\x9F\xBF", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x80\x80\xAF", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x80\x80\x80", InvalidCoding_Error_TinyUTF8 },
	{ "\xF0\x8F\xBF\xBF", InvalidCoding_Error_TinyUTF8 },

	{ NULL, No_Error_TinyUTF8 }
};