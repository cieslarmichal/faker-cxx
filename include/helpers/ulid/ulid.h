#ifndef ULID_HH
#define ULID_HH

// http://stackoverflow.com/a/23981011
#ifdef __SIZEOF_INT128__
#define ULIDUINT128
#endif

#ifdef ULIDUINT128
#include "ulid_uint128.h"
#else
#include "ulid_struct.h"
#endif // ULIDUINT128

#endif // ULID_HH