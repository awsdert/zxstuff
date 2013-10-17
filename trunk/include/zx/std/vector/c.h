#include "../lib.h"
#include "../math.h"
#include "c_functions.h"

#ifndef ZXVECTOR_C_H
#define ZXVECTOR_C_H

ZXC_OPEN

typedef struct zxv_zxVECTOR_struct
{
  void*   m_data;
  void**  m_ptr;
  bool    m_isFixed;
  size_t  m_Tsize;
  size_t  m_count, m_fullCount;
  size_t  m_size,  m_fullSize;
} zxVECTOR;

#define ZXVECTOR( DATA, PTR, ISFIXED, T, COUNT ) \
  { DATA, PTR, ISFIXED, sizeof( T ), \
  COUNT, COUNT, sizeof( T ) * COUNT, sizeof( T ) * COUNT }

/*
  These are not to be used directly,
  instead use the zxv object to access them
*/
ZXCORE void   zxv_zxVECTOR__init(
  zxVECTOR       *obj,
  size_t         Tsize,
  zxuc     const *src,
  size_t         setCount );

ZXCORE void   zxv_zxVECTOR__kill(         zxVECTOR       *obj );

ZXCORE size_t zxv_zxVECTOR_size(          zxVECTOR const *obj );

ZXCORE size_t zxv_zxVECTOR_max_size(      zxVECTOR const *obj );

ZXCORE void   zxv_zxVECTOR_resize(
  zxVECTOR       *obj,
  size_t   const  setCount,
  zxuc     const *setNew );

ZXCORE size_t zxv_zxVECTOR_capacity(      zxVECTOR const *obj );

ZXCORE bool   zxv_zxVECTOR_empty(         zxVECTOR const *obj );

ZXCORE void   zxv_zxVECTOR_reserve(
  zxVECTOR       *obj,
  size_t          minSize );

ZXCORE void   zxv_zxVECTOR_grow(
  zxVECTOR       *obj,
  size_t          setCount,
  zxuc   const *setNew );

ZXCORE void   zxv_zxVECTOR_shrink(
  zxVECTOR       *obj,
  size_t          setCount );

ZXCORE void   zxv_zxVECTOR_shrink_to_fit( zxVECTOR       *obj );

static void (*zxv_zxVECTOR_assign)(
  zxVECTOR       *obj,
  size_t   const  setCount,
  zxuc     const *setNew ) = zxv_zxVECTOR_resize;

ZXCORE void   zxv_zxVECTOR_append(
  zxVECTOR       *obj,
  zxVECTOR const *src,
  size_t          pos );

ZXCORE bool   zxv_zxVECTOR_push_back(
  zxVECTOR       *obj,
  zxVECTOR const *src );

ZXCORE void   zxv_zxVECTOR_pop_back(      zxVECTOR       *obj );

ZXCORE void   zxv_zxVECTOR_insert(
  zxVECTOR       *obj,
  zxVECTOR const *src,
  size_t         pos );

ZXCORE void   zxv_zxVECTOR_erase(
  zxVECTOR       *obj,
  size_t         first,
  size_t         last );

ZXCORE void   zxv_zxVECTOR_swap(
  zxVECTOR       *obj,
  zxVECTOR       *src );

ZXCORE void   zxv_zxVECTOR_clear(   zxVECTOR       *obj );

ZXCORE void   zxv_zxVECTOR_replace(
  zxVECTOR       *obj,
  zxVECTOR const *src,
  size_t   const at );

ZXCORE void   zxv_zxVECTOR_reverse( zxVECTOR       *obj );

ZXCORE size_t zxv_zxVECTOR_copy(
  zxVECTOR const *obj,
  zxuc           *dst,
  size_t   const dstCount,
  size_t   const from );

ZXCORE zxuc*  zxv_zxVECTOR_at(
  zxVECTOR const *obj,
  size_t   const  i );

ZXCORE bool   zxv_zxVECTOR_isEqual(
  zxVECTOR const *obj,
  zxVECTOR const *src,
  size_t         *i );

ZXCORE bool   zxv_zxVECTOR_cmpEQ(   zxVECTOR const *obj, zxVECTOR const *cmp );
ZXCORE bool   zxv_zxVECTOR_cmpNE(   zxVECTOR const *obj, zxVECTOR const *cmp );

ZXCORE zxVECTOR*   zxv_zxVECTOR_cpyEql(   zxVECTOR       *obj,
                                          zxVECTOR const *src );
ZXCORE zxVECTOR*   zxv_zxVECTOR_opAdd(    zxVECTOR       *obj,
                                          zxVECTOR const *src );
static zxVECTOR* (*zxv_zxVECTOR_opMvl)(
  zxVECTOR       *obj,
  zxVECTOR const *src ) = zxv_zxVECTOR_opAdd;

#define ZXV_DEC_1ST( NAME ) typedef struct zxv_##NAME##_struct

/* TODO: finish defining ZXV_DEC_2ND macro */
#define ZXV_DEC_2ND( NAME, T, DLL ) \
  DLL void   zxv_##NAME##__init(         NAME         *obj, \
                                         T      const *src, \
                                         size_t       srcCount ); \
  DLL void   zxv_##NAME##__kill(         NAME         *obj ); \
  ZXV_SIZE(          NAME,    DLL ); \
  ZXV_MAX_SIZE(      NAME,    DLL ); \
  ZXV_RESIZE(        NAME, T, DLL ); \
  ZXV_CAPACITY(      NAME,    DLL ); \
  ZXV_EMPTY(         NAME,    DLL ); \
  ZXV_RESERVE(       NAME,    DLL ); \
  ZXV_GROW(          NAME, T, DLL ); \
  ZXV_SHRINK(        NAME,    DLL ); \
  ZXV_SHRINK_TO_FIT( NAME, T, DLL ); \
  ZXV__ASSIGN(       NAME, T, static, \
    (*zxv_##NAME##_assign) ) = zxv_##NAME##_resize; \
  ZXV_APPEND(        NAME,    DLL ); \
  ZXV_PUSH_BACK(     NAME,    DLL ); \
  ZXV_POP_BACK(      NAME,    DLL ); \
  ZXV_INSERT(        NAME,    DLL ); \
  DLL void   zxv_##NAME##_erase(         NAME         *obj, \
                                         size_t       first, \
                                         size_t       last ); \
  DLL void   zxv_##NAME##_swap(          NAME         *obj, \
                                         NAME         *src ); \
  DLL void   zxv_##NAME##_clear(         NAME         *obj ); \
  DLL void   zxv_##NAME##_reverse(       NAME         *obj ); \
  DLL size_t zxv_##NAME##_copy(          NAME   const *obj, \
                                         T            *dst, \
                                         size_t const dstCount, \
                                         size_t const from ); \
  ZXV_AT(            NAME, T, DLL ); \
  DLL bool   zxv_##NAME##_isEqual(       NAME   const *obj, \
                                         NAME   const *src, \
                                         size_t       *i ); \
  DLL NAME*  zxv_##NAME##_cpyEql(        NAME         *obj, \
                                         NAME   const *src ); \
  ZXV_OPADD(         NAME,    DLL ); \
  ZXV__OPMVL(        NAME,    static, \
    (*zxv_##NAME##_opMvl) ) = zxv_##NAME##_opAdd; \
  DLL bool   zxv_##NAME##_cmpEQ(         NAME   const *obj, \
                                         NAME   const *src ); \
  DLL bool   zxv_##NAME##_cmpNE(         NAME   const *obj, \
                                         NAME   const *src );

/* This is intended for namespaces / namespace replacements (struct) */
/* TODO: finish defining ZXV_DEC_BODY macro */
#define ZXV_DEC_BODY( NAME, T ) \
  NAME const def; \
  void   (*_init)(         NAME         *obj, \
                           T      const *src, \
                           size_t       srcCount ); \
  void   (*_kill)(         NAME         *obj ); \
  ZXV__SIZE(          NAME,,    (*size)          ); \
  ZXV__MAX_SIZE(      NAME,,    (*max_size)      ); \
  ZXV__RESIZE(        NAME, T,, (*resize)        ); \
  ZXV__CAPACITY(      NAME,,    (*capacity)      ); \
  ZXV__EMPTY(         NAME,,    (*empty)         ); \
  ZXV__RESERVE(       NAME,,    (*reserve)       ); \
  ZXV__GROW(          NAME, T,, (*grow)          ); \
  ZXV__SHRINK(        NAME,,    (*shrink)        ); \
  ZXV__SHRINK_TO_FIT( NAME,,    (*shrink_to_fit) ); \
  ZXV__ASSIGN(        NAME, T,, (*assign)        ); \
  ZXV__APPEND(        NAME,,    (*append)        ); \
  ZXV__PUSH_BACK(     NAME,,    (*push_back)     ); \
  ZXV__POP_BACK(      NAME,,    (*pop_back)      ); \
  ZXV__INSERT(        NAME,,    (*insert)        ); \
  void   (*erase)(         NAME         *obj, \
                           size_t        first, \
                           size_t        last ); \
  void   (*swap)(          NAME         *obj, \
                           NAME         *src ); \
  void   (*clear)(         NAME         *obj ); \
  void   (*reverse)(       NAME         *obj ); \
  size_t (*copy)(          NAME   const *obj, \
                           T            *dst, \
                           size_t const  desCount, \
                           size_t const  from ); \
  ZXV__AT(           NAME,T,,   (*at)          ); \
  bool    (*isEqual)(      NAME   const *obj, \
                           NAME   const *src, \
                           size_t       *i ); \
  NAME*   (*cpyEql)(       NAME         *obj, \
                           NAME   const *src ); \
  ZXV__OPADD(        NAME,,     (*opAdd)       ); \
  ZXV__OPMVL(        NAME,,     (*opMvl)       ); \
  bool    (*cmpEQ)(        NAME   const *obj, \
                           NAME   const *cmp ); \
  bool    (*cmpNE)(        NAME   const *obj, \
                           NAME   const *cmp )

/* We won't set def here, we'll let the developer do that */

#define ZXV_DEF_BODY( NAME ) \
  zxv_##NAME##__init, \
  zxv_##NAME##__kill, \
  zxv_##NAME##_size, \
  zxv_##NAME##_max_size, \
  zxv_##NAME##_resize, \
  zxv_##NAME##_capacity, \
  zxv_##NAME##_empty, \
  zxv_##NAME##_reserve, \
  zxv_##NAME##_grow, \
  zxv_##NAME##_shrink, \
  zxv_##NAME##_shrink_to_fit, \
  zxv_##NAME##_resize, \
  zxv_##NAME##_append, \
  zxv_##NAME##_push_back, \
  zxv_##NAME##_pop_back, \
  zxv_##NAME##_insert, \
  zxv_##NAME##_erase, \
  zxv_##NAME##_swap, \
  zxv_##NAME##_clear, \
  zxv_##NAME##_reverse, \
  zxv_##NAME##_copy, \
  zxv_##NAME##_at, \
  zxv_##NAME##_isEqual, \
  zxv_##NAME##_cpyEql, \
  zxv_##NAME##_opAdd, \
  zxv_##NAME##_opAdd, \
  zxv_##NAME##_cmpEQ, \
  zxv_##NAME##_cmpNE
/**/

#define ZXV_DEF_GROW( NAME, T, PARAM, EXP ) \
  EXP void zxv_##NAME##_grow( \
    NAME *obj, \
    size_t const setCount, \
    T const setNew ) \
  { \
    ZXASSERT( !obj ) \
      return; \
    zxv.grow( &obj->##PARAM, setCount, (zxuc*)setNew ); \
  }
#define ZXV_DEF_SHRINK( NAME, PARAM, EXP ) \
  EXP void zxv_##NAME##_shrink( NAME *obj, size_t const setCount ) \
  { \
    ZXASSERT( !obj ) \
      return; \
    zxv.shrink( &obj->##PARAM, setCount );
  }
#define ZXV_DEF_AT( NAME, T, PARAM, EXP ) \
  EXP T* zxv_##NAME##_at( NAME *obj, size_t const i ) \
  { \
    ZXASSERT( !obj ) \
      return NULL; \
    return (T*)zxv.at( &obj->##PARAM, i ); \
  }
ZXC_SHUT

#endif