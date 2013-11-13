#pragma once
#ifndef ZXMATH_H
#define ZXMATH_H
#include "int.h"

ZXC_OPEN
#define ZX___BASEMAX( B ) ( ZXUIMAX_MAX - ( ZXUIMAX_MAX % B ) )
static char    const zx___cBase[] =  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static wchar_t const zx___wBase[] = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static zxuc    const zx___baseLen = 62;
static zxum ZXUNUSED( zx___baseMax[] ) =
{
  0u, 0u, ZXUIMAX_MAX,
  ZX___BASEMAX( 3 ),  ZX___BASEMAX( 4 ),  ZX___BASEMAX( 5 ),
  ZX___BASEMAX( 6 ),  ZX___BASEMAX( 7 ),  ZX___BASEMAX( 8 ),
  ZX___BASEMAX( 9 ),  ZX___BASEMAX( 10 ), ZX___BASEMAX( 11 ),
  ZX___BASEMAX( 12 ), ZX___BASEMAX( 13 ), ZX___BASEMAX( 14 ),
  ZX___BASEMAX( 15 ), ZX___BASEMAX( 16 ), ZX___BASEMAX( 17 ),
  ZX___BASEMAX( 18 ), ZX___BASEMAX( 19 ), ZX___BASEMAX( 20 ),
  ZX___BASEMAX( 21 ), ZX___BASEMAX( 22 ), ZX___BASEMAX( 23 ),
  ZX___BASEMAX( 24 ), ZX___BASEMAX( 25 ), ZX___BASEMAX( 26 ),
  ZX___BASEMAX( 27 ), ZX___BASEMAX( 28 ), ZX___BASEMAX( 29 ),
  ZX___BASEMAX( 30 ), ZX___BASEMAX( 31 ), ZX___BASEMAX( 32 ),
  ZX___BASEMAX( 33 ), ZX___BASEMAX( 34 ), ZX___BASEMAX( 35 ),
  ZX___BASEMAX( 36 ), ZX___BASEMAX( 37 ), ZX___BASEMAX( 38 ),
  ZX___BASEMAX( 39 ), ZX___BASEMAX( 40 ), ZX___BASEMAX( 41 ),
  ZX___BASEMAX( 42 ), ZX___BASEMAX( 43 ), ZX___BASEMAX( 44 ),
  ZX___BASEMAX( 45 ), ZX___BASEMAX( 46 ), ZX___BASEMAX( 47 ),
  ZX___BASEMAX( 48 ), ZX___BASEMAX( 49 ), ZX___BASEMAX( 50 ),
  ZX___BASEMAX( 51 ), ZX___BASEMAX( 52 ), ZX___BASEMAX( 53 ),
  ZX___BASEMAX( 54 ), ZX___BASEMAX( 55 ), ZX___BASEMAX( 56 ),
  ZX___BASEMAX( 57 ), ZX___BASEMAX( 58 ), ZX___BASEMAX( 59 ),
  ZX___BASEMAX( 60 ), ZX___BASEMAX( 61 ), ZX___BASEMAX( 62 )
};

#define ZX__ILASTBITI( N, TBITS ) static size_t const zx_##N##_LastBitI = (TBITS - 1)
#define ZX__ILASTBIT(  N, T, TBITS ) static T const zx_##N##_LastBit = ZX_LB( TBITS )
#define ZX__UDIV_INC(  N, T ) T zx_##N##_udiv(  unsigned T src, unsigned T val, unsigned T *remainder )
#define ZX__USDIV_INC( N, T ) T zx_##N##_usdiv( unsigned T src, signed   T val, unsigned T *remainder )
#define ZX__SDIV_INC(  N, T ) T zx_##N##_sdiv(  signed   T src, signed   T val, signed T *remainder )
#define ZX__SUDIV_INC( N, T ) T zx_##N##_sudiv( signed   T src, unsigned T val, signed T *remainder )
#define ZX__IDIV_INC(  N, T, TBITS, DLL ) \
  ZX__ILASTBITI(       N, TBITS ); \
  ZX__ILASTBIT(        N, T, TBITS ); \
  DLL ZX__UDIV_INC(    N, T ); \
  DLL ZX__USDIV_INC(   N, T ); \
  DLL ZX__SDIV_INC(    N, T ); \
  DLL ZX__SUDIV_INC(   N, T )
#define ZX__UDIV_SRC(  N, T ) \
  T zx_##N##_udiv( unsigned T src, unsigned T val, unsigned T *remainder ) { \
    size_t i = zx_##N##_LastBitI; \
    unsigned T des = 0u, quo = 0u, bit = zx_##N##_LastBit, rem = 0u; \
    if ( remainder ) \
      *remainder = 0u; \
    if ( !src ) \
      return 0u; \
    if ( !val ) \
      return 0u; \
    for ( ; bit != 0u && src >= val; bit >>= 1, --i ) \
    { \
      des <<= 1; \
      quo <<= 1; \
      rem |= bit; \
      if ( src & bit ) \
        des |= 1u; \
      if ( des >= val ) \
      { \
        des -= val; \
        quo |= 1u; \
        src ^= rem; \
        src |= ( des << i ); \
      } \
    } \
    if ( remainder ) \
      *remainder = quo; \
    return des; \
  }
ZX__IDIV_INC( char,   char,   ZXCHAR_BITS, ZXCORE );
ZX__IDIV_INC( short,  short,  ZXSHRT_BITS, ZXCORE );
ZX__IDIV_INC( long,   long,   ZXLONG_BITS, ZXCORE );
ZX__IDIV_INC( int,    int,    ZXINT_BITS,  ZXCORE );
ZX__IDIV_INC( imax,   ZXIMAX, ZXIMAX_BITS, ZXCORE );

static size_t const zxc_size_LastBitI = (ZXSIZE_BITS - 1);
static size_t const zxc_size_LastBit  = ZX_LB( ZXSIZE_BITS );
ZXCORE size_t zxc_size_udiv(  size_t  src, size_t  val, size_t  *remainder );
ZXCORE size_t zxc_size_usdiv( size_t  src, ssize_t val, size_t  *remainder );
ZXCORE size_t zxc_size_sdiv(  ssize_t src, ssize_t val, ssize_t *remainder );
ZXCORE size_t zxc_size_sudiv( ssize_t src, size_t  val, ssize_t *remainder );

static zxui const zxm_test_i =
#if ZXINT_BITS == 16
    0x5678;
#else
    0x12345678;
#endif
ZXCORE void zxm_i2c( zxui value, zxuc* dst, zxuc i );
ZXCORE void zxm_i2s( zxui value, zxus* dst, zxuc i );

ZXC_SHUT

#endif
