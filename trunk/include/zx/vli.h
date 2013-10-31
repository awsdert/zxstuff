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
  zxVECTOR m_core;
  zxuc    *m_data;
  size_t   m_lastByte;
  size_t   m_bits;
  zxuc     m_lastBit;
  bool     m_isSigned;
} zxVLI;
/* Behaves as constructor would and assumes object has not been used already */
ZXCORE void   zxVLI__init(  zxVLI *src, zxsm value );
ZXCORE void   zxVLI__initU( zxVLI *src, zxum value );
ZXV__INITCPY( zxVLI, ZXCORE );
ZXV__KILL(    zxVLI, ZXCORE );
/* Sizing */
ZXV_SIZE( zxVLI, ZXCORE );
ZXV__SIZE( zxVLI, ZXCORE, zxVLI_bits );
ZXV_MAX_SIZE( zxVLI, ZXCORE );
ZXV__MAX_SIZE( zxVLI, ZXCORE, zxVLI_max_bits );
ZXCORE void   zxVLI_resize(  zxVLI *src, size_t setSize );
ZXCORE void   zxVLI_resizeb( zxVLI *src, size_t setSize );
ZXV_EMPTY(    zxVLI, ZXCORE );
ZXV_RESERVE(  zxVLI, ZXCORE );
ZXCORE void   zxVLI_grow(    zxVLI *src, size_t setSize );
ZXCORE void   zxVLI_growb(   zxVLI *src, size_t setBits );
ZXCORE void   zxVLI_shrink(  zxVLI *src, size_t setSize );
ZXCORE void   zxVLI_shrinkb( zxVLI *src, size_t setSize );
ZXV_SHRINK_TO_FIT( zxVLI,       ZXCORE );
ZXV_ERASE(         zxVLI,       ZXCORE );
ZXCORE void zxVLI_eraseb( zxVLI *src,
  size_t firstBit, size_t lastBit );
ZXV_SWAP(          zxVLI,       ZXCORE );
ZXV_CLEAR(         zxVLI,       ZXCORE );
ZXV_COPY(          zxVLI, zxuc, ZXCORE );
ZXV_REVERSE(       zxVLI,       ZXCORE );
ZXV_AT(            zxVLI, zxuc, ZXCORE );
/* Returns src */
ZXCORE zxVLI* zxVLI_opEql(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opAdd(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opAnd(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opDiv(   zxVLI *src, zxVLI  const *val, zxVLI *remainder  );
ZXCORE zxVLI* zxVLI_opMul(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opMvl(   zxVLI *src, size_t        bits );
ZXCORE zxVLI* zxVLI_opMvr(   zxVLI *src, size_t        bits );
ZXCORE zxVLI* zxVLI_opNot(   zxVLI *src  );
ZXCORE zxVLI* zxVLI_opOr(    zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opSub(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_opXor(   zxVLI *src, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpyEql(  zxVLI *src, zxVLI  const *cpy  );
ZXCORE zxVLI* zxVLI_cpyAdd(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpyAnd(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpyDiv(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val, zxVLI *remainder  );
ZXCORE zxVLI* zxVLI_cpyMul(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpyMvl(  zxVLI *src, zxVLI  const *cpy, size_t        bits );
ZXCORE zxVLI* zxVLI_cpyMvr(  zxVLI *src, zxVLI  const *cpy, size_t        bits );
ZXCORE zxVLI* zxVLI_cpyNot(  zxVLI *src, zxVLI  const *cpy  );
ZXCORE zxVLI* zxVLI_cpyOr(   zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpySub(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
ZXCORE zxVLI* zxVLI_cpyXor(  zxVLI *src, zxVLI  const *cpy, zxVLI  const *val  );
/* Returns the max for the last byte if not zero */
ZXCORE zxuc zxVLI_isNeg( zxVLI const *src );
ZXV_ISEQUAL( zxVLI, ZXCORE );
ZXV_CMPEQ( zxVLI, ZXCORE );
ZXV_CMPNE( zxVLI, ZXCORE );
ZXV__CMP( zxVLI, ZXCORE, zxVLI_cmpMT );
ZXV__CMP( zxVLI, ZXCORE, zxVLI_cmpME );
ZXV__CMP( zxVLI, ZXCORE, zxVLI_cmpLT );
ZXV__CMP( zxVLI, ZXCORE, zxVLI_cmpLE );

ZXCORE zxus   zxGetUSht(    zxuc* src, size_t size );
ZXCORE zxss   zxGetSSht(    zxuc* src, size_t size );
ZXCORE zxul   zxGetULng(    zxuc* src, size_t size );
ZXCORE zxsl   zxGetSLng(    zxuc* src, size_t size );
ZXCORE zxui   zxGetUInt(    zxuc* src, size_t size );
ZXCORE zxsi   zxGetSInt(    zxuc* src, size_t size );
#ifdef ZXILL
ZXCORE zxull   zxGetUIll(    zxuc* src, size_t size );
ZXCORE zxsll   zxGetSIll(    zxuc* src, size_t size );
#endif
ZXCORE zxum   zxGetUMax(    zxuc* src, size_t size );
ZXCORE zxsm   zxGetSMax(    zxuc* src, size_t size );
ZXCORE size_t   zxGetSize_t(  zxuc* src, size_t size );
ZXCORE ssize_t  zxGetSSize_t( zxuc* src, size_t size );

typedef struct zx___vli
{
  void (*_init)(  zxVLI *src, zxim value );
  void (*_initU)( zxVLI *src, zxum value );
  zxVLI const def;
  ZXV___INITCPY(      zxVLI,,       (*_initCpy)      );
  ZXV___KILL(         zxVLI,,       (*_kill)         );
  ZXV__SIZE(          zxVLI,,       (*size)          );
  ZXV__SIZE(          zxVLI,,       (*bits)          );
  ZXV__MAX_SIZE(      zxVLI,,       (*max_size)      );
  ZXV__MAX_SIZE(      zxVLI,,       (*max_bits)      );
  void (*resize)(     zxVLI *src, size_t setSize );
  void (*resizeb)(    zxVLI *src, size_t setBits );
  ZXV__EMPTY(         zxVLI,,       (*empty)         );
  ZXV__RESERVE(       zxVLI,,       (*reserve)       );
  void (*grow)(       zxVLI *src, size_t setSize );
  void (*growb)(      zxVLI *src, size_t setBits );
  void (*shrink)(     zxVLI *src, size_t setSize );
  void (*shrinkb)(    zxVLI *src, size_t setBits );
  ZXV__SHRINK_TO_FIT( zxVLI,,       (*shrink_to_fit) );
  void (*assign)(     zxVLI *src, size_t setSize );
  void (*assignb)(    zxVLI *src, size_t setBits );
  ZXV__ERASE(         zxVLI,,       (*erase)         );
  void (*eraseb)(     zxVLI *src,
    size_t firstBIt, size_t lastBit );
  ZXV__SWAP(          zxVLI,,       (*swap)          );
  ZXV__CLEAR(         zxVLI,,       (*clear)         );
  ZXV__REVERSE(       zxVLI,,       (*reverse)       );
  ZXV__COPY(          zxVLI, zxuc,, (*copy)          );
  ZXV__AT(            zxVLI, zxuc,, (*at)            );
  ZXV__OPADD(         zxVLI,,       (*opAdd)         );
  zxVLI* (*opMvl)(    zxVLI       *src, size_t        bits );
  zxVLI* (*opAnd)(    zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opDiv)(    zxVLI       *src, zxVLI  const *val, zxVLI *remainder  );
  zxVLI* (*opMul)(    zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opMvr)(    zxVLI       *src, size_t        bits );
  zxVLI* (*opNot)(    zxVLI       *src );
  zxVLI* (*opOr)(     zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opSub)(    zxVLI       *src, zxVLI  const *val  );
  zxVLI* (*opXor)(    zxVLI       *src, zxVLI  const *val  );
  ZXV__CPYEQL(        zxVLI,,       (*cpyEql)        );
  zxVLI* (*cpyAdd)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxVLI* (*cpyAnd)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxVLI* (*cpyDiv)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val, zxVLI *remainder  );
  zxVLI* (*cpyMul)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxVLI* (*cpyMvl)(   zxVLI       *src, zxVLI  const *cpy, size_t        bits );
  zxVLI* (*cpyMvr)(   zxVLI       *src, zxVLI  const *cpy, size_t        bits );
  zxVLI* (*cpyNot)(   zxVLI       *src, zxVLI  const *cpy );
  zxVLI* (*cpyOr)(    zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxVLI* (*cpySub)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxVLI* (*cpyXor)(   zxVLI       *src, zxVLI  const *cpy, zxVLI  const *val  );
  zxuc (*isNeg)( zxVLI const *src );
  /* i will be 0, SIZE_MAX or first non-equal byte from end */
  ZXV__ISEQUAL(       zxVLI,,       (*isEqual)       );
  ZXV__CMP(           zxVLI,,       (*cmpEQ)         );
  ZXV__CMP(           zxVLI,,       (*cmpNE)         );
  ZXV__CMP(           zxVLI,,       (*cmpMT)         );
  ZXV__CMP(           zxVLI,,       (*cmpME)         );
  ZXV__CMP(           zxVLI,,       (*cmpLT)         );
  ZXV__CMP(           zxVLI,,       (*cmpLE)         );
} zx__vli;

static zx__vli const zxvli =
{
  zxVLI__init,    zxVLI__initU, {0},
  zxVLI__initCpy, zxVLI__kill,
  zxVLI_size,     zxVLI_bits,
  zxVLI_max_size, zxVLI_max_bits,
  zxVLI_resize,   zxVLI_resizeb,
  zxVLI_empty,    zxVLI_reserve,
  zxVLI_grow,     zxVLI_growb,
  zxVLI_shrink,   zxVLI_shrinkb,
  zxVLI_shrink_to_fit,
  zxVLI_resize,   zxVLI_resizeb,
  zxVLI_erase,    zxVLI_eraseb,
  zxVLI_swap,     zxVLI_clear,
  zxVLI_reverse,  zxVLI_copy,
  zxVLI_at,
  zxVLI_opAdd,    zxVLI_opMvl,
  zxVLI_opAnd,    zxVLI_opDiv,
  zxVLI_opMul,    zxVLI_opMvr,
  zxVLI_opNot,    zxVLI_opOr,
  zxVLI_opSub,    zxVLI_opXor,
  zxVLI_cpyEql,
  zxVLI_cpyAdd,   zxVLI_cpyAnd,
  zxVLI_cpyDiv,   zxVLI_cpyMul,
  zxVLI_cpyMvl,   zxVLI_cpyMvr,
  zxVLI_cpyNot,   zxVLI_cpyOr,
  zxVLI_cpySub,   zxVLI_cpyXor,
  zxVLI_isNeg,    zxVLI_isEqual,
  zxVLI_cmpEQ,    zxVLI_cmpNE,
  zxVLI_cmpMT,    zxVLI_cmpME,
  zxVLI_cmpLT,    zxVLI_cmpLE
};

ZXC_SHUT

#if ZXCPP
class zxVli : public zxVLI
{
public:
  zxVli( void );
  zxVli( char        val );
  zxVli( zxuc const  val );
  zxVli( zxsc const  val );
  zxVli( zxus const  val );
  zxVli( zxss const  val );
  zxVli( zxul const  val );
  zxVli( zxsl const  val );
  zxVli( zxui const  val );
  zxVli( zxsi const  val );
#ifdef ZXILL
  zxVli( zxull const  val );
  zxVli( zxsll const  val );
#endif
  zxVli( zxVLI  const *val )       { zxvli._initCpy( this, val );    }
  zxVli( zxVli  const &val )       { zxvli._initCpy( this, &val );   }
  ~zxVli( void )                   { zxvli._kill( this );            }
  size_t size( void )              { return zxvli.size( this );      }
  size_t bits( void )              { return zxvli.bits( this );      }
  size_t max_size( void )          { return zxvli.max_size( this );  }
  size_t max_bits( void )          { return zxvli.max_bits( this );  }
  void resize(  size_t setSize )   { zxvli.resize( this, setSize );  }
  void resizeb( size_t setBits )   { zxvli.resizeb( this, setBits ); }
  zxVli& operator=   ( zxVli val ) { zxvli.cpyEql( this, &val );     }
  zxVli  operator~   ( void )
  {
    zxVli cpy( this );
    zxvli.opNot( &cpy );
    return cpy;
  }
  zxVli  operator&   ( zxVli val )
  {
    zxVli cpy( this );
    zxvli.opAnd( &cpy, &val );
    return cpy;
  }
  zxVli& operator&=  ( zxVli val )
  {
    zxvli.opAnd( this, &val );
    return *this;
  }
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
  bool   operator==  ( zxVli val ) { return  zxvli.isEqual( this, &val, NULL ); }
  bool   operator!   ( void )      { return  zxvli.isEqual( this, NULL, NULL ); }
  bool   operator!=  ( zxVli val ) { return !zxvli.isEqual( this, &val, NULL ); }
  bool   operator>   ( zxVli val ) { return  zxvli.cmpMT( this, &val );         }
  bool   operator>=  ( zxVli val ) { return  zxvli.cmpME( this, &val );         }
  bool   operator<   ( zxVli val ) { return  zxvli.cmpLT( this, &val );         }
  bool   operator<=  ( zxVli val ) { return  zxvli.cmpLE( this, &val );         }
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
