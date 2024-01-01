#pragma once

static
const char composedUTF8TestString[ ] = {
	0x7E, 0xD0, 0x90, 0xE1, 0xB8, 0x82, 0xE2, 0xB2, 0xA4, 0xF0, 0x9D, 0x97,
	0x97, 0xF0, 0x9D, 0x96, 0xA4, 0xF0, 0x9D, 0x97, 0x99, 0xEA, 0x9E, 0xA0,
	0xEA, 0x93, 0xA7, 0xC8, 0x8A, 0xF0, 0x9D, 0x90, 0x89, 0xF0, 0x9D, 0x9C,
	0xA5, 0xEA, 0x93, 0xA1, 0xF0, 0x9D, 0x91, 0x80, 0xF0, 0x9D, 0x91, 0xB5,
	0xC7, 0xAC, 0xF0, 0x9D, 0x99, 0xBF, 0xF0, 0x9D, 0x91, 0x84, 0xC5, 0x96,
	0xF0, 0x9D, 0x91, 0x86, 0xF0, 0x9D, 0x92, 0xAF, 0xF0, 0x9D, 0x96, 0xB4,
	0xF0, 0x9D, 0x98, 0x9D, 0xF0, 0x9D, 0x98, 0x9E, 0xEA, 0x93, 0xAB, 0xC5,
	0xB8, 0xF0, 0x9D, 0x9C, 0xA1, 0xE1, 0xBA, 0xA3, 0xF0, 0x9D, 0x98, 0xA2,
	0xC6, 0x80, 0xF0, 0x9D, 0x96, 0xBC, 0xE1, 0xB8, 0x8B, 0xE1, 0xBA, 0xBF,
	0xE1, 0xB5, 0xAE, 0xE2, 0x84, 0x8A, 0xF0, 0x9D, 0x99, 0x9D, 0xE1, 0x8E,
	0xA5, 0xF0, 0x9D, 0x95, 0x9B, 0xD0, 0xBA, 0xCE, 0xB9, 0xE1, 0xB9, 0x83,
	0xD5, 0xA4, 0xE2, 0xB1, 0xBA, 0xF0, 0x9D, 0x93, 0x85, 0xF0, 0x9D, 0x98,
	0xB2, 0xF0, 0x9D, 0x95, 0xA3, 0xF0, 0x9D, 0x96, 0x98, 0xC5, 0xA7, 0xF0,
	0x9D, 0x91, 0xA2, 0xE1, 0xB9, 0xBD, 0xE1, 0xBA, 0x89, 0xF0, 0x9D, 0x98,
	0x85, 0xE1, 0x83, 0xA7, 0xC5, 0xBE, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36,
	0x37, 0x38, 0x39, 0x30, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5E, 0x26, 0x2A,
	0x28, 0x29, 0x2D, 0x5F, 0x3D, 0x2B, 0x5B, 0x7B, 0x5D, 0x7D, 0x3B, 0x3A,
	0x27, 0x22, 0x2C, 0x3C, 0x2E, 0x3E, 0x2F, 0x3F, 0x7E, 0xD1, 0xA6, 0xF0,
	0x9D, 0x99, 0xB1, 0xC6, 0x87, 0xE1, 0x97, 0x9E, 0xCE, 0xA3, 0xE2, 0x84,
	0xB1, 0xD4, 0x8D, 0xD2, 0xA4, 0xD9, 0xA1, 0xF0, 0x9D, 0x94, 0x8D, 0xD0,
	0x9A, 0xF0, 0x9D, 0x93, 0x9B, 0xF0, 0x9D, 0x93, 0x9C, 0xC6, 0x9D, 0xC8,
	0x8E, 0xF0, 0x9D, 0x9A, 0xB8, 0xF0, 0x9D, 0x91, 0x84, 0xE1, 0xB9, 0x9A,
	0xF0, 0x9D, 0x93, 0xA2, 0xE1, 0xB9, 0xAE, 0xE1, 0xB9, 0xBA, 0xC6, 0xB2,
	0xE1, 0x8F, 0x94, 0xEA, 0x93, 0xAB, 0xF0, 0x9D, 0x9A, 0x88, 0xF0, 0x9D,
	0x9A, 0xAD, 0xF0, 0x9D, 0x9C, 0xB6, 0xE1, 0x8F, 0x8F, 0xC3, 0xA7, 0xE1,
	0x83, 0xAB, 0xF0, 0x9D, 0x91, 0x92, 0xF0, 0x9D, 0x96, 0xBF, 0xF0, 0x9D,
	0x97, 0x80, 0xE1, 0xB8, 0xA7, 0xF0, 0x9D, 0x97, 0x82, 0xF0, 0x9D, 0x90,
	0xA3, 0xD2, 0x9D, 0xC9, 0xAD, 0xE1, 0xB8, 0xBF, 0xF0, 0x9D, 0x95, 0x9F,
	0xF0, 0x9D, 0x90, 0xA8, 0xF0, 0x9D, 0x9D, 0x94, 0xF0, 0x9D, 0x95, 0xA2,
	0xE1, 0xB9, 0x9B, 0xF0, 0x9D, 0x93, 0xBC, 0xD1, 0x82, 0xC3, 0xBA, 0xF0,
	0x9D, 0x94, 0xB3, 0xE1, 0xBA, 0x83, 0xE2, 0xA4, 0xAC, 0xF0, 0x9D, 0x9D,
	0xB2, 0xF0, 0x9D, 0x97, 0x93, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
	0x38, 0x39, 0x30, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5E, 0x26, 0x2A, 0x28,
	0x29, 0x2D, 0x5F, 0x3D, 0x2B, 0x5B, 0x7B, 0x5D, 0x7D, 0x3B, 0x3A, 0x27,
	0x22, 0x2C, 0x3C, 0x2E, 0x3E, 0x2F, 0x3F, 0x7E, 0xF0, 0x9D, 0x96, 0xA0,
	0xCE, 0x92, 0xF0, 0x9D, 0x92, 0x9E, 0xF0, 0x9D, 0x98, 0x8B, 0xF0, 0x9D,
	0x99, 0xB4, 0xF0, 0x9D, 0x93, 0x95, 0xC4, 0xA2, 0xC8, 0x9E, 0xE1, 0xBB,
	0x88, 0xF0, 0x9D, 0x95, 0xB5, 0xEA, 0x93, 0x97, 0xCA, 0x9F, 0xF0, 0x9D,
	0x99, 0xBC, 0xE2, 0x84, 0x95, 0xE0, 0xA7, 0xA6, 0xF0, 0x9D, 0x9A, 0xB8,
	0xF0, 0x9D, 0x97, 0xA4, 0xD5, 0x80, 0xEA, 0x93, 0xA2, 0xE1, 0xB9, 0xB0,
	0xC7, 0x93, 0xE2, 0x85, 0xA4, 0xF0, 0x9D, 0x94, 0x9A, 0xE2, 0xB2, 0xAC,
	0xF0, 0x9D, 0x91, 0x8C, 0xF0, 0x9D, 0x99, 0x95, 0xF0, 0x9D, 0x98, 0xA2,
	0xF0, 0x9D, 0x95, 0xA4, 0x00
}; // 508 bytes + \0, 213 code points


static
const char decomposedUTF8TestString[ ] = {
	0x7E, 0xD0, 0x90, 0x42, 0xCC, 0x87, 0xE2, 0xB2, 0xA4, 0xF0, 0x9D, 0x97,
	0x97, 0xF0, 0x9D, 0x96, 0xA4, 0xF0, 0x9D, 0x97, 0x99, 0xEA, 0x9E, 0xA0,
	0xEA, 0x93, 0xA7, 0x49, 0xCC, 0x91, 0xF0, 0x9D, 0x90, 0x89, 0xF0, 0x9D,
	0x9C, 0xA5, 0xEA, 0x93, 0xA1, 0xF0, 0x9D, 0x91, 0x80, 0xF0, 0x9D, 0x91,
	0xB5, 0x4F, 0xCC, 0xA8, 0xCC, 0x84, 0xF0, 0x9D, 0x99, 0xBF, 0xF0, 0x9D,
	0x91, 0x84, 0x52, 0xCC, 0xA7, 0xF0, 0x9D, 0x91, 0x86, 0xF0, 0x9D, 0x92,
	0xAF, 0xF0, 0x9D, 0x96, 0xB4, 0xF0, 0x9D, 0x98, 0x9D, 0xF0, 0x9D, 0x98,
	0x9E, 0xEA, 0x93, 0xAB, 0x59, 0xCC, 0x88, 0xF0, 0x9D, 0x9C, 0xA1, 0x61,
	0xCC, 0x89, 0xF0, 0x9D, 0x98, 0xA2, 0xC6, 0x80, 0xF0, 0x9D, 0x96, 0xBC,
	0x64, 0xCC, 0x87, 0x65, 0xCC, 0x82, 0xCC, 0x81, 0xE1, 0xB5, 0xAE, 0xE2,
	0x84, 0x8A, 0xF0, 0x9D, 0x99, 0x9D, 0xE1, 0x8E, 0xA5, 0xF0, 0x9D, 0x95,
	0x9B, 0xD0, 0xBA, 0xCE, 0xB9, 0x6D, 0xCC, 0xA3, 0xD5, 0xA4, 0xE2, 0xB1,
	0xBA, 0xF0, 0x9D, 0x93, 0x85, 0xF0, 0x9D, 0x98, 0xB2, 0xF0, 0x9D, 0x95,
	0xA3, 0xF0, 0x9D, 0x96, 0x98, 0xC5, 0xA7, 0xF0, 0x9D, 0x91, 0xA2, 0x76,
	0xCC, 0x83, 0x77, 0xCC, 0xA3, 0xF0, 0x9D, 0x98, 0x85, 0xE1, 0x83, 0xA7,
	0x7A, 0xCC, 0x8C, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
	0x30, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5E, 0x26, 0x2A, 0x28, 0x29, 0x2D,
	0x5F, 0x3D, 0x2B, 0x5B, 0x7B, 0x5D, 0x7D, 0x3B, 0x3A, 0x27, 0x22, 0x2C,
	0x3C, 0x2E, 0x3E, 0x2F, 0x3F, 0x7E, 0xD1, 0xA6, 0xF0, 0x9D, 0x99, 0xB1,
	0xC6, 0x87, 0xE1, 0x97, 0x9E, 0xCE, 0xA3, 0xE2, 0x84, 0xB1, 0xD4, 0x8D,
	0xD2, 0xA4, 0xD9, 0xA1, 0xF0, 0x9D, 0x94, 0x8D, 0xD0, 0x9A, 0xF0, 0x9D,
	0x93, 0x9B, 0xF0, 0x9D, 0x93, 0x9C, 0xC6, 0x9D, 0x4F, 0xCC, 0x91, 0xF0,
	0x9D, 0x9A, 0xB8, 0xF0, 0x9D, 0x91, 0x84, 0x52, 0xCC, 0xA3, 0xF0, 0x9D,
	0x93, 0xA2, 0x54, 0xCC, 0xB1, 0x55, 0xCC, 0x84, 0xCC, 0x88, 0xC6, 0xB2,
	0xE1, 0x8F, 0x94, 0xEA, 0x93, 0xAB, 0xF0, 0x9D, 0x9A, 0x88, 0xF0, 0x9D,
	0x9A, 0xAD, 0xF0, 0x9D, 0x9C, 0xB6, 0xE1, 0x8F, 0x8F, 0x63, 0xCC, 0xA7,
	0xE1, 0x83, 0xAB, 0xF0, 0x9D, 0x91, 0x92, 0xF0, 0x9D, 0x96, 0xBF, 0xF0,
	0x9D, 0x97, 0x80, 0x68, 0xCC, 0x88, 0xF0, 0x9D, 0x97, 0x82, 0xF0, 0x9D,
	0x90, 0xA3, 0xD2, 0x9D, 0xC9, 0xAD, 0x6D, 0xCC, 0x81, 0xF0, 0x9D, 0x95,
	0x9F, 0xF0, 0x9D, 0x90, 0xA8, 0xF0, 0x9D, 0x9D, 0x94, 0xF0, 0x9D, 0x95,
	0xA2, 0x72, 0xCC, 0xA3, 0xF0, 0x9D, 0x93, 0xBC, 0xD1, 0x82, 0x75, 0xCC,
	0x81, 0xF0, 0x9D, 0x94, 0xB3, 0x77, 0xCC, 0x81, 0xE2, 0xA4, 0xAC, 0xF0,
	0x9D, 0x9D, 0xB2, 0xF0, 0x9D, 0x97, 0x93, 0x31, 0x32, 0x33, 0x34, 0x35,
	0x36, 0x37, 0x38, 0x39, 0x30, 0x21, 0x40, 0x23, 0x24, 0x25, 0x5E, 0x26,
	0x2A, 0x28, 0x29, 0x2D, 0x5F, 0x3D, 0x2B, 0x5B, 0x7B, 0x5D, 0x7D, 0x3B,
	0x3A, 0x27, 0x22, 0x2C, 0x3C, 0x2E, 0x3E, 0x2F, 0x3F, 0x7E, 0xF0, 0x9D,
	0x96, 0xA0, 0xCE, 0x92, 0xF0, 0x9D, 0x92, 0x9E, 0xF0, 0x9D, 0x98, 0x8B,
	0xF0, 0x9D, 0x99, 0xB4, 0xF0, 0x9D, 0x93, 0x95, 0x47, 0xCC, 0xA7, 0x48,
	0xCC, 0x8C, 0x49, 0xCC, 0x89, 0xF0, 0x9D, 0x95, 0xB5, 0xEA, 0x93, 0x97,
	0xCA, 0x9F, 0xF0, 0x9D, 0x99, 0xBC, 0xE2, 0x84, 0x95, 0xE0, 0xA7, 0xA6,
	0xF0, 0x9D, 0x9A, 0xB8, 0xF0, 0x9D, 0x97, 0xA4, 0xD5, 0x80, 0xEA, 0x93,
	0xA2, 0x54, 0xCC, 0xAD, 0x55, 0xCC, 0x8C, 0xE2, 0x85, 0xA4, 0xF0, 0x9D,
	0x94, 0x9A, 0xE2, 0xB2, 0xAC, 0xF0, 0x9D, 0x91, 0x8C, 0xF0, 0x9D, 0x99,
	0x95, 0xF0, 0x9D, 0x98, 0xA2, 0xF0, 0x9D, 0x95, 0xA4, 0x00
}; // 525 bytes + \0, 243 code points