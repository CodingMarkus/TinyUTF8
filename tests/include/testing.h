#pragma once

#include <stdio.h>


#define testAssert( condition )                           \
	if (!(condition)) {                                   \
		fprintf(stderr, "Test assertion failed!\n");      \
		fprintf(stderr, "Expectation: %s\n", #condition); \
		fprintf(stderr, "In %s:%u (%s:%u)\n",             \
			__FUNCTION__, __LINE__, __FILE__, __LINE__    \
		);                                                \
		exit(1);                                          \
	}


#define testAssertMsg( condition, format, ... )             \
	if (!(condition)) {                                     \
		fprintf(stderr, "Test assertion failed: ");         \
		fprintf(stderr, format, ## __VA_ARGS__);            \
		fprintf(stderr, "\nExpectation: %s\n", #condition); \
		fprintf(stderr, "In %s:%u (%s:%u)\n",               \
			__FUNCTION__, __LINE__, __FILE__, __LINE__      \
		);                                                  \
		exit(1);                                            \
	}
