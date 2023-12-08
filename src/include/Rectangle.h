#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GenericTraits.h"
#include "stdint.h"

/// Use `DECLARE_STRUCT` to declare the struct in less than 5 lines.
DECLARE_STRUCT(Rectangle, {
	GenericTraits *impl;
	int64_t height;
	int64_t width;
})


#endif