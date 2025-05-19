#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

// custom types
typedef struct { int64_t parts[2]; }int128_t;
typedef struct { int64_t parts[4]; }int256_t;
typedef struct { int64_t parts[8]; }int512_t;
typedef struct { uint64_t parts[2]; }uint128_t;
typedef struct { uint64_t parts[4]; }uint256_t;
typedef struct { uint64_t parts[8]; }uint512_t;