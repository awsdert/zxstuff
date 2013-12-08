#pragma once
#ifndef ZXMATH_H
#define ZXMATH_H
#include "int.h"

ZXC_OPEN

static char    const zx___cBase[] =  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static wchar_t const zx___wBase[] = L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static zxuc    const zx___baseLen = 62;

#define ZXM__LBITI(  NAME,    BITS ) static size_t \
  const zxm_##NAME##_LastBitI = (BITS - 1)
#define ZXM__LBIT(   NAME, T, BITS ) static T      \
  const zxm_##NAME##_LastBit  = ZX_LB( BITS )

#define ZXM___DIV(   FUN, T, T1, T2, DLL ) \
  DLL FUN( T1 src, T2 val, T *remainder )

#define ZXM__DIV(   NAME, FUN, T, T1, T2, DLL, CALL ) \
  ZXM___DIV( CALL T zxdiv##FUN##_##NAME, T, T1, T2, DLL )

#define ZXM__UDIV(  NAME, T, DLL, CALL ) \
  ZXM__DIV( NAME, u,  unsigned T, zxum, zxum, DLL, CALL )

#define ZXM__USDIV( NAME, T, DLL, CALL ) \
  ZXM__DIV( NAME, us, unsigned T, zxum, zxsm, DLL, CALL )

#define ZXM__SDIV(  NAME, T, DLL, CALL ) \
  ZXM__DIV( NAME, s,  signed   T, zxsm, zxsm, DLL, CALL )

#define ZXM__SUDIV( NAME, T, DLL, CALL ) \
  ZXM__DIV( NAME, su, signed   T, zxsm, zxum, DLL, CALL )

#define ZXM_DIV( NAME, T, BITS, DLL, CALL ) \
  ZXM__LBITI(    NAME,    BITS ); \
  ZXM__LBIT(     NAME, T, BITS ); \
  ZXM__UDIV(     NAME, T, DLL, CALL ); \
  ZXM__USDIV(    NAME, T, DLL, CALL ); \
  ZXM__SDIV(     NAME, T, DLL, CALL ); \
  ZXM__SUDIV(    NAME, T, DLL, CALL )

#define ZXM_DEC_UDIV(  NAME, T, DLL, CALL, ULIMIT ) \
  ZXM__UDIV( NAME, T, DLL, CALL ) \
  { \
    zxum quo = 0; \
    src = zxdivu_imax( src, val, &quo ) & ULIMIT; \
    if ( remainder ) \
      *remainder = quo & ULIMIT; \
    return src & ULIMIT; \
  }

#define ZX___OUT( MSG ) _Pragma( #MSG )
#define ZX__OUT( FUN, MSG )  ZX___OUT( FUN( MSG ) )
#define ZX_OUT( MSG )   ZX__OUT( message ZXMSG, MSG )
#define ZXOUT( MSG )    ZX_OUT( MSG )

ZXM_DIV( char,   char,        ZXCHAR_BITS, ZXCORE, ZXCORE_CALL );
ZXM_DIV( short,  short,       ZXSHRT_BITS, ZXCORE, ZXCORE_CALL );
ZXM_DIV( long,   long,        ZXLONG_BITS, ZXCORE, ZXCORE_CALL );
ZXM_DIV( int,    int,         ZXINT_BITS,  ZXCORE, ZXCORE_CALL );
ZXM_DIV( imax,   ZXIMAX,      ZXIMAX_BITS, ZXCORE, ZXCORE_CALL );
ZXM_DIV( size,   ZXSIZE_TYPE, ZXSIZE_BITS, ZXCORE, ZXCORE_CALL );

#define ZX_TO( VAL, T ) (VAL & (T)-1)
#define ZXTOINT(  VAL ) ZX_TO( VAL, int   )
#define ZXTOCHAR( VAL ) ZX_TO( VAL, char  )
#define ZXTOSHRT( VAL ) ZX_TO( VAL, short )
#define ZXTOLONG( VAL ) ZX_TO( VAL, long  )

#ifdef ZXILL
#define ZXTOILL(  VAL ) ZX_TO( VAL, ZXILL )
#endif

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
