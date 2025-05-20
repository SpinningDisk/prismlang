#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

// custom types
//      big int
typedef struct { int64_t parts[2]; }int128_t;
typedef struct { int64_t parts[4]; }int256_t;
typedef struct { int64_t parts[8]; }int512_t;
typedef struct { uint64_t parts[2]; }uint128_t;
typedef struct { uint64_t parts[4]; }uint256_t;
typedef struct { uint64_t parts[8]; }uint512_t;

//      float
// these non-sensical values here (outside of float and double) have been determined using linear interpolation; (3, 8) and (5, 11) have been used for exp and (3, 2.3) (5, 5.2) for man, and then just 2 units up or down
typedef struct __attribute__((packed)){ int sign: 1; unsigned int exp: 5;   unsigned int man: 3;    }f5_3;
typedef struct __attribute__((packed)){ int sign: 1; unsigned int exp: 8;   unsigned long long man: 23;   }f8_23_float;
typedef struct __attribute__((packed)){ int sign: 1; unsigned int exp: 10;  unsigned long long man: 42;   }f10_42;
typedef struct __attribute__((packed)){ int sign: 1; unsigned int exp: 11;  unsigned long long man: 52;   }f11_52_double;
typedef struct __attribute__((packed)){ int sign: 1; unsigned int exp: 14;  uint32_t man[3];   }f14_71;            // 71 might be wrong here using linear, but I don't care