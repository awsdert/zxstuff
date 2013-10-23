#pragma once
#include "std/math.h"
#include "std/text.h"
#include "endian.h"
#include "std/vector.h"

#ifndef ZXVLI_H
#define ZXVLI_H

ZXC_OPEN

typedef struct zxVLI_struct
{
  zxVECTOR m_vector;
  size_t m_lastByte;
  size_t m_bits;
  zxuchr m_lastBit;
  bool   m_isSigned;
} zxVLI;
/* Behaves as constructor would and assumes object has not been used already */
ZXCORE void zxcInit_zxVLI( zxVLI *obj );
ZXCORE void zxcKill_zxVLI( zxVLI *obj );
/* Will only grow object */
ZXCORE void   zxc_zxVLI_grow( zxVLI* obj, size_t newSize );
ZXCORE void   zxc_zxVLI_growb( zxVLI* obj, size_t newBits );
/* Returns src */
ZXCORE zxVLI* zxc_zxVLI_opEql(   zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opAdd(   zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opAnd(   zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opDiv(   zxVLI       *src, zxVLI  const *val, zxVLI *remainder  );
ZXCORE zxVLI* zxc_zxVLI_opMul(   zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opMvl(   zxVLI       *src, size_t        bits );
ZXCORE zxVLI* zxc_zxVLI_opMvr(   zxVLI       *src, size_t        bits );
ZXCORE zxVLI* zxc_zxVLI_opNot(   zxVLI       *src  );
ZXCORE zxVLI* zxc_zxVLI_opOr(    zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opSub(   zxVLI       *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_opXor(   zxVLI       *src, zxVLI  const *val  );
/* returns dst */
ZXCORE zxVLI* zxc_zxVLI_cpyEql(  zxVLI       *dst, zxVLI  const *src  );
ZXCORE zxVLI* zxc_zxVLI_cpyAdd(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_cpyAnd(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_cpyDiv(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val, zxVLI *remainder  );
ZXCORE zxVLI* zxc_zxVLI_cpyMul(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_cpyMvl(  zxVLI       *dst, zxVLI  const *src, size_t        bits );
ZXCORE zxVLI* zxc_zxVLI_cpyMvr(  zxVLI       *dst, zxVLI  const *src, size_t        bits );
ZXCORE zxVLI* zxc_zxVLI_cpyNot(  zxVLI       *dst, zxVLI  const *src  );
ZXCORE zxVLI* zxc_zxVLI_cpyOr(   zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_cpySub(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
ZXCORE zxVLI* zxc_zxVLI_cpyXor(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );

ZXCORE bool   zxc_zxVLI_isEqual( zxVLI const *src, zxVLI  const *val, size_t       *I    );
ZXCORE bool   zxc_zxVLI_cmpEQ(   zxVLI const *src, zxVLI  const *val  );
ZXCORE bool   zxc_zxVLI_cmpNE(   zxVLI const *src, zxVLI  const *val  );
ZXCORE bool   zxc_zxVLI_cmpMT(   zxVLI const *src, zxVLI  const *val  );
ZXCORE bool   zxc_zxVLI_cmpME(   zxVLI const *src, zxVLI  const *val  );
ZXCORE bool   zxc_zxVLI_cmpLT(   zxVLI const *src, zxVLI  const *val  );
ZXCORE bool   zxc_zxVLI_cmpLE(   zxVLI const *src, zxVLI  const *val  );

ZXCORE zxusht   zxGetUSht(    zxuchr* src, size_t size );
ZXCORE zxssht   zxGetSSht(    zxuchr* src, size_t size );
ZXCORE zxulng   zxGetULng(    zxuchr* src, size_t size );
ZXCORE zxslng   zxGetSLng(    zxuchr* src, size_t size );
ZXCORE zxuint   zxGetUInt(    zxuchr* src, size_t size );
ZXCORE zxsint   zxGetSInt(    zxuchr* src, size_t size );
#ifdef ZXILL
ZXCORE zxuill   zxGetUIll(    zxuchr* src, size_t size );
ZXCORE zxsill   zxGetSIll(    zxuchr* src, size_t size );
#endif
ZXCORE zxumax   zxGetUMax(    zxuchr* src, size_t size );
ZXCORE zxsmax   zxGetSMax(    zxuchr* src, size_t size );
ZXCORE size_t   zxGetSize_t(  zxuchr* src, size_t size );
ZXCORE ssize_t  zxGetSSize_t( zxuchr* src, size_t size );

typedef struct zx___vli
{
  const zxVLI def;
  /* All return obj */
  void   (*construct)( zxVLI *obj );
  void   (*destruct)(  zxVLI *obj );
  zxVLI* (*opAdd)(   zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opAnd)(   zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opDiv)(   zxVLI       *src, zxVLI  const *val, zxVLI *remainder  );
  zxVLI* (*opMul)(   zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opMvl)(   zxVLI       *src, size_t        bits );
  zxVLI* (*opMvr)(   zxVLI       *src, size_t        bits );
  zxVLI* (*opNot)(   zxVLI       *src );
  zxVLI* (*opOr)(    zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opSub)(   zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opXor)(   zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*cpyEql)(  zxVLI       *dst, zxVLI  const *src  );
  zxVLI* (*cpyAdd)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  zxVLI* (*cpyAnd)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  zxVLI* (*cpyDiv)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val, zxVLI *remainder  );
  zxVLI* (*cpyMul)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  zxVLI* (*cpyMvl)(  zxVLI       *dst, zxVLI  const *src, size_t        bits );
  zxVLI* (*cpyMvr)(  zxVLI       *dst, zxVLI  const *src, size_t        bits );
  zxVLI* (*cpyNot)(  zxVLI       *dst, zxVLI  const *src );
  zxVLI* (*cpyOr)(   zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  zxVLI* (*cpySub)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  zxVLI* (*cpyXor)(  zxVLI       *dst, zxVLI  const *src, zxVLI  const *val  );
  /* i will be 0, SIZE_MAX or first non-equal byte from end */
  bool   (*isEqual)( zxVLI const *src, zxVLI  const *val, size_t *i );
  bool   (*cmpEQ)(   zxVLI const *src, zxVLI  const *val  );
  bool   (*cmpNE)(   zxVLI const *src, zxVLI  const *val  );
  bool   (*cmpMT)(   zxVLI const *src, zxVLI  const *val  );
  bool   (*cmpME)(   zxVLI const *src, zxVLI  const *val  );
  bool   (*cmpLT)(   zxVLI const *src, zxVLI  const *val  );
  bool   (*cmpLE)(   zxVLI const *src, zxVLI  const *val  );
} zx__vli;

static zx__vli const zxvli =
{
  {{0}},
  zxcInit_zxVLI,
  zxcKill_zxVLI,
  zxc_zxVLI_opAdd,
  zxc_zxVLI_opAnd,
  zxc_zxVLI_opDiv,
  zxc_zxVLI_opMul,
  zxc_zxVLI_opMvl,
  zxc_zxVLI_opMvr,
  zxc_zxVLI_opNot,
  zxc_zxVLI_opOr,
  zxc_zxVLI_opSub,
  zxc_zxVLI_opXor,
  zxc_zxVLI_cpyEql,
  zxc_zxVLI_cpyAdd,
  zxc_zxVLI_cpyAnd,
  zxc_zxVLI_cpyDiv,
  zxc_zxVLI_cpyMul,
  zxc_zxVLI_cpyMvl,
  zxc_zxVLI_cpyMvr,
  zxc_zxVLI_cpyNot,
  zxc_zxVLI_cpyOr,
  zxc_zxVLI_cpySub,
  zxc_zxVLI_cpyXor,
  zxc_zxVLI_isEqual,
  zxc_zxVLI_cmpEQ,
  zxc_zxVLI_cmpNE,
  zxc_zxVLI_cmpMT,
  zxc_zxVLI_cmpME,
  zxc_zxVLI_cmpLT,
  zxc_zxVLI_cmpLE
};

ZXC_SHUT

#if ZXCPP
class zxVli : public zxVLI
{
public:
  size_t bits( void ) { return m_bits; }
  zxVli( void );
  zxVli( char          val );
  zxVli( zxuchr const  val );
  zxVli( zxschr const  val );
  zxVli( zxusht const  val );
  zxVli( zxssht const  val );
  zxVli( zxulng const  val );
  zxVli( zxslng const  val );
  zxVli( zxuint const  val );
  zxVli( zxsint const  val );
#ifdef ZXILL
  zxVli( zxuill const  val );
  zxVli( zxsill const  val );
#endif
  zxVli( zxVLI  const  val );
  zxVli( zxVli  const &val );
  ~zxVli( void );
  void   resize( size_t       setCount )
  {
    zxv.resize( &m_vector, setCount, NULL );
    m_lastByte = setCount - 1;
    m_bits = setCount * CHAR_BIT;
  }
  void   resize( size_t       setCount,
                 zxuchr const setNew )
    { zxv.resize( &m_vector, setCount, &setNew ); }
  void   rebits( size_t       setBits )
  {
    size_t tmp = 0, setCount = zxc_size_udiv( setBits, CHAR_BIT, &tmp );
    bool isNeg = ( m_isSigned && m_vector.m_data[ m_lastByte ] & m_lastBit );
    if ( tmp )
      ++setCount;
    else
      tmp = CHAR_BIT - 1;
    zxv.resize( &m_vector, setCount, NULL );
    m_bits     = setBits;
    m_lastBit  = 1u << tmp;
    m_lastByte = m_vector.m_count - 1;
    if ( isNeg )
    {
      zxVli add = 1u;
      add.m_bits = 1u;
      zxvli.opNot( this );
      zxvli.opAdd( this, &add );
    }
  }
  zxVli& operator=   ( zxVli val );
  zxVli  operator~   ( void );
  zxVli  operator&   ( zxVli val );
  zxVli& operator&=  ( zxVli val );
  zxVli  operator^   ( zxVli val );
  zxVli& operator^=  ( zxVli val );
  zxVli  operator|   ( zxVli val );
  zxVli& operator|=  ( zxVli val );
  zxVli  operator>>  ( zxVli val );
  zxVli& operator>>= ( zxVli val );
  zxVli  operator<<  ( zxVli val );
  zxVli& operator<<= ( zxVli val );
  zxVli  operator+   ( zxVli val );
  zxVli& operator+=  ( zxVli val );
  zxVli& operator++  ( void );
  zxVli  operator++  ( int );
  zxVli  operator-   ( zxVli val );
  zxVli& operator-=  ( zxVli val );
  zxVli& operator--  ( void );
  zxVli  operator--  ( int );
  zxVli  operator*   ( zxVli val );
  zxVli& operator*=  ( zxVli val );
  zxVli  operator/   ( zxVli val );
  zxVli& operator/=  ( zxVli val );
  zxVli  operator%   ( zxVli val );
  zxVli& operator%=  ( zxVli val );
  bool   operator==  ( zxVli val );
  bool   operator!   ( void );
  bool   operator!=  ( zxVli val );
  bool   operator>   ( zxVli val );
  bool   operator>=  ( zxVli val );
  bool   operator<   ( zxVli val );
  bool   operator<=  ( zxVli val );
};
class zxVlu : public zxVli
{
public:
  zxVlu( zxVli val ) : zxVli( val ) { m_isSigned = false; }
};
class zxVls : public zxVli
{
public:
  zxVls( zxVli val ) : zxVli( val ) { m_isSigned = true; }
};
#endif

#endif
