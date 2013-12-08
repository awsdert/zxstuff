#pragma once
#ifndef ZXVLI_H
#define ZXVLI_H
#include "std/math.h"
#include "std/text.h"
#include "endian.h"

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

#define ZXVLI___OP( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src, zxVLI const *val )
#define ZXVLI__OP( FUN ) \
  ZXVLI___OP( ZXCORE_CALL zxVLI_op##FUN, ZXCORE )
#define ZXVLI___CPY( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src, zxVLI const *val, zxVLI *dst )
#define ZXVLI__CPY( FUN ) \
  ZXVLI___CPY( ZXCORE_CALL zxVLI_cpy##FUN, ZXCORE )

#define ZXVLI__OPDIV( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src, zxVLI const *val, zxVLI *remainder )
#define ZXVLI__CPYDIV( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src, zxVLI const *val, zxVLI *remainder, zxVLI *dst )
#define ZXVLI___OPMV( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI* src, size_t bits )
#define ZXVLI__OPMV( DIR ) \
  ZXVLI___OPMV( ZXCORE_CALL zxVLI_opMv##DIR, ZXCORE )

#define ZXVLI___CPYMV( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI* src, size_t bits, zxVLI *dst )
#define ZXVLI__CPYMV( DIR ) \
  ZXVLI___CPYMV( ZXCORE_CALL zxVLI_cpyMv##DIR, ZXCORE )
#define ZXVLI__OPNOT( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src )
#define ZXVLI__CPYNOT( FUN, DLL ) \
  DLL zxVLI* FUN( zxVLI *src, zxVLI *dst )

#define ZXVLI_PTR__OP(  FUN ) ZXVLI___OP(  (ZXCORE_CALL *op##FUN), )
#define ZXVLI_PTR__CPY( FUN ) ZXVLI___CPY( (ZXCORE_CALL *cpy##FUN), )
#define ZXVLI_PTR__OPMV( DIR ) \
  ZXVLI___OPMV(  (ZXCORE_CALL *opMv##DIR),  )
#define ZXVLI_PTR__CPYMV( DIR ) \
  ZXVLI___CPYMV( (ZXCORE_CALL *cpyMv##DIR), )

#define ZXVLI_OPEQL ZXVLI__OP( Eql )
#define ZXVLI_OPADD ZXVLI__OP( Add )
#define ZXVLI_OPAND ZXVLI__OP( And )
#define ZXVLI_OPDIV ZXVLI__OPDIV( ZXCORE_CALL zxVLI_opDiv, ZXCORE )
#define ZXVLI_OPMUL ZXVLI__OP( Mul )
#define ZXVLI_OPMVL ZXVLI__OPMV( l )
#define ZXVLI_OPMVR ZXVLI__OPMV( r )
#define ZXVLI_OPNOT ZXVLI__OPNOT( ZXCORE_CALL zxVLI_opNot, ZXCORE )
#define ZXVLI_OPOR  ZXVLI__OP( Or )
#define ZXVLI_OPSUB ZXVLI__OP( Sub )
#define ZXVLI_OPXOR ZXVLI__OP( Xor )

#define ZXVLI_CPYADD ZXVLI__CPY( Add )
#define ZXVLI_CPYAND ZXVLI__CPY( And )
#define ZXVLI_CPYDIV ZXVLI__CPYDIV( ZXCORE_CALL zxVLI_cpyDiv, ZXCORE )
#define ZXVLI_CPYMUL ZXVLI__CPY( Mul )
#define ZXVLI_CPYMVL ZXVLI__CPYMV( l )
#define ZXVLI_CPYMVR ZXVLI__CPYMV( r )
#define ZXVLI_CPYNOT ZXVLI__CPYNOT( ZXCORE_CALL zxVLI_cpyNot, ZXCORE )
#define ZXVLI_CPYOR  ZXVLI__CPY( Or )
#define ZXVLI_CPYSUB ZXVLI__CPY( Sub )
#define ZXVLI_CPYXOR ZXVLI__CPY( Xor )

#define ZXVLI___CMP( FUN, DLL ) \
  DLL bool FUN( zxVLI const *src, zxVLI const *val )
#define ZXVLI__CMP( FUN ) \
  ZXVLI___CMP( ZXCORE_CALL zxVLI_cmp##FUN, ZXCORE )
#define ZXVLI_PTR__CMP( FUN ) \
  ZXVLI___CMP( (ZXCORE_CALL *cmp##FUN), )

#define ZXVLI_CMPEQ ZXVLI__CMP( EQ )
#define ZXVLI_CMPNE ZXVLI__CMP( NE )
#define ZXVLI_CMPMT ZXVLI__CMP( MT )
#define ZXVLI_CMPME ZXVLI__CMP( ME )
#define ZXVLI_CMPLT ZXVLI__CMP( LT )
#define ZXVLI_CMPLE ZXVLI__CMP( LE )

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

ZXNSO( vli )
{
  void (ZXCORE_CALL *_init)(  zxVLI *src, zxim value );
  void (ZXCORE_CALL *_initU)( zxVLI *src, zxum value );
  zxVLI const def;
  ZXV___INITCPY(      zxVLI,,       (ZXCORE_CALL *_initCpy)      );
  ZXV___KILL(         zxVLI,,       (ZXCORE_CALL *_kill)         );
  zxui   (ZXCORE_CALL *size)(       zxVLI const *src );
  size_t (ZXCORE_CALL *bits)(       zxVLI const *src );
  zxui   (ZXCORE_CALL *max_size)(   zxVLI const *src );
  size_t (ZXCORE_CALL *max_bits)(   zxVLI const *src );
  void   (ZXCORE_CALL *resize)(     zxVLI *src, zxui   size );
  void   (ZXCORE_CALL *resizeb)(    zxVLI *src, size_t bits );
  ZXV__EMPTY(         zxVLI,,       (ZXCORE_CALL *empty)         );
  ZXV__RESERVE(       zxVLI,,       (ZXCORE_CALL *reserve)       );
  void (ZXCORE_CALL *grow)(       zxVLI *src, zxui   size );
  void (ZXCORE_CALL *growb)(      zxVLI *src, size_t bits );
  void (ZXCORE_CALL *shrink)(     zxVLI *src, zxui   size );
  void (ZXCORE_CALL *shrinkb)(    zxVLI *src, size_t bits );
  ZXV__SHRINK_TO_FIT( zxVLI,,       (ZXCORE_CALL *shrink_to_fit) );
  void (ZXCORE_CALL *assign)(     zxVLI *src, zxui   size );
  void (ZXCORE_CALL *assignb)(    zxVLI *src, size_t bits );
  ZXV__ERASE(         zxVLI,,       (ZXCORE_CALL *erase)         );
  void (ZXCORE_CALL *eraseb)(     zxVLI *src,
    size_t firstBIt, size_t lastBit );
  ZXV__SWAP(          zxVLI,,       (ZXCORE_CALL *swap)          );
  ZXV__CLEAR(         zxVLI,,       (ZXCORE_CALL *clear)         );
  ZXV__REVERSE(       zxVLI,,       (ZXCORE_CALL *reverse)       );
  ZXV__COPY(          zxVLI, zxuc,, (ZXCORE_CALL *copy)          );
  ZXV__AT(            zxVLI, zxuc,, (ZXCORE_CALL *at)            );
  ZXVLI_PTR__OP( Eql );
  ZXVLI_PTR__OP( Add ); ZXVLI_PTR__OP( And );
  ZXVLI__OPDIV( (ZXCORE_CALL *opDiv), );
  ZXVLI_PTR__OP( Mul );
  ZXVLI_PTR__OPMV( l ); ZXVLI_PTR__OPMV( r );
  ZXVLI__OPNOT( (ZXCORE_CALL *opNot), );
  ZXVLI_PTR__OP( Or );
  ZXVLI_PTR__OP( Sub ); ZXVLI_PTR__OP( Xor );


  ZXVLI_PTR__CPY( Add ); ZXVLI_PTR__CPY( And );
  ZXVLI__CPYDIV( (ZXCORE_CALL *cpyDiv), );
  ZXVLI_PTR__CPY( Mul );
  ZXVLI_PTR__CPYMV( l ); ZXVLI_PTR__CPYMV( r );
  ZXVLI__CPYNOT( (ZXCORE_CALL *cpyNot), );
  ZXVLI_PTR__CPY( Or );
  ZXVLI_PTR__CPY( Sub ); ZXVLI_PTR__CPY( Xor );
  zxuc (*isNeg)( zxVLI const *src );
  /* i will be 0, SIZE_MAX or first non-equal byte from end */
  ZXV__ISEQUAL(       zxVLI,,       (*isEqual)       );
  ZXVLI_PTR__CMP( EQ ); ZXVLI_PTR__CMP( NE );
  ZXVLI_PTR__CMP( MT ); ZXVLI_PTR__CMP( ME );
  ZXVLI_PTR__CMP( LT ); ZXVLI_PTR__CMP( LE );
} zxn_vli;

extern zxn_vli const zxvli;

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
  zxVli& operator=   ( zxVli val ) { zxvli.opEql( this, &val );     }
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
