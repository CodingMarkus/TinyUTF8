Terms used by TinyUTF8
======================

Code Point
----------

Classical character encodings consist of a table of characters where every entry in that table represents exactly one independent character. This is not the case with Unicode, where a single visible character on screen might be described by multiple Unicode characters. E.g. o and ¨ are two Unicode characters but on screen they form a single character ö. Aside from combining characters, Unicode also has all sorts of meta characters that don't describe any visible character at all and also don't add to an existing character, like the BOM (Byte Order Mark), the surrogate pairs, or characters that encode information like the text direction. Using the term "character" to refer to all of that is very confusing as that's not what most people associate with that term.

Instead TinyUTF8 uses the term "code point", which is also used by the Unicode standard itself. The Unicode standard defines a set of code points, which are just numeric values between 0 an 1048575 (both inclusive). Every character gets a code point assigned but not every code point describes a character.


Character
---------

When TinyUTF8 refers to character, it means a "printable" character on screen, which may in fact have a single code point or it may be the result of combining multiple code points together. o and ¨ are two code points and together they form a single character ö.

The term "printable" can be slightly misleading in this context, as whitespace (spaces, tabs, etc.) or line breaks are also characters, yet they don't print anything on the screen, they just move other characters around, but they do influence what is printed and they are independent characters. Also control characters (escape, backspace, bell, etc.) would be characters, despite the fact that they usually don't print anything on the screen (they don't have a defined representation) and may not even have an effect on what is visible on the screen (backspace may have an effect, escape rather not, end of record almost never), but those are rather historical and historical they have always been treated as characters.

A BOM (Byte Order Mark) or a code point changing the text direction would not be a character. A ¨ on its own would also not be a character, as it always must be combined with another code point to actually form a character. In this text document, ¨ is in fact represented by combing the code point of ¨ with the code point of a space and only those two together form a character.

Note that depending on language, multiple characters may still be perceived as a single character and a single character may be perceived as multiple characters by the user. E.g. ﬁ is a single character with only a single code point but in fact it represents the characters f and i as a single glyph, a so called "ligature".


Encoding
--------

An encoding stores a sequence of code points as a sequence of bytes. The number of bytes required to store a single code point may vary depending on code point value. Common encodings are UTF-8, UTF-16, and UTF-32. The same sequence of code points may result in an entirely different sequence of bytes if a different encoding is being used.

If there is no need to be able to express all Unicode characters, there are even encodings that can only represent a given subset of it, like UCS-2 (it can represent all Unicode characters within the basic plane only) and even ASCII is such an encoding (it can represent the first 127 Unicode characters).

Unless explicitly noted otherwise, string in TinyUTF8 are always expected to be in UTF-8 encoding. The advantage of this encoding is that every C string API that can handle C strings with extended ASCII characters (characters in the range 0 to 255) can also handle UTF-8 strings. For code points below 127 it will even be able to interpret them correctly and string functions like `strlen()` or case conversion will even deliver expected results. It cannot interpret code points above 127 correctly, but most code will just store, copy, compare and pass on strings to other APIs and all of that will work correctly for any UTF-8 string.


Normalization
-------------

Some characters can be expressed by a different sequence of code points. E.g. ö can be composed out of o and ¨, but there also exists a single code point that describes the letter ö. Both representations are valid and the Unicode standard treats them as equivalent. If all characters in a string are expressed as a series of code points that cannot be decomposed any further, the standard calls this the "Normalization Form D" or NFD. If on the other hand all compositions that can be expressed as a single code point are represented as a single code point, the standard calls this "Normalization Form C" or NFC.

A mixed form is allowed by the standard, where some characters may be fully composed, others fully decomposed and some even partially decomposed. But if you want to compare, combine or convert strings in code, you usually want that all your strings are in the same standardized form, that's why Unicode strings are typically normalized by either converting them to NFD or NFC, depending on what you plan to do with them.

Unless explicitly specified, the normalized form always refers to NFC in TinyUTF8. This form has the advantages that it requires the smallest amount of storage (disk and memory) and is fastest to process for most common operations. The disadvantages are that NFC normalization is slower to perform than NFD normalization and there are a few less common operations that are way simpler and faster to perform in NFD form. But since normalization only needs to happen once and only on strings that aren't known to already be correctly normalized (which doesn't need to happen at runtime), NFC seems the preferable option and is what most software implementations use by default.