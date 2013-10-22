#pragma once
#include "../lib.h"
#include "../math.h"
#include "def_fun.h"

#ifndef ZXVECTOR_C_H
#define ZXVECTOR_C_H

ZXC_OPEN

#define ZXVECTOR( DATA, PTR, ISFIXED, T, COUNT ) \
  { DATA, PTR, ISFIXED, sizeof( T ), \
  COUNT, COUNT, sizeof( T ) * COUNT, sizeof( T ) * COUNT }

#define ZXV_DEC_1ST( NAME ) typedef struct zxv_##NAME##_struct

/* TODO: finish defining ZXV_DEC_2ND macro */
#define ZXV__DEC_2ND( NAME, T, T2, DLL ) \
  DLL void   zxv_##NAME##__kill(         NAME         *obj ); \
  ZXV_SIZE(          NAME,     DLL ); \
  ZXV_MAX_SIZE(      NAME,     DLL ); \
  ZXV_RESIZE(        NAME, T,  DLL ); \
  ZXV_CAPACITY(      NAME,     DLL ); \
  ZXV_EMPTY(         NAME,     DLL ); \
  ZXV_RESERVE(       NAME,     DLL ); \
  ZXV_GROW(          NAME, T,  DLL ); \
  ZXV_SHRINK(        NAME,     DLL ); \
  ZXV_SHRINK_TO_FIT( NAME,     DLL ); \
  ZXV__ASSIGN(       NAME, T, static, \
    (*zxv_##NAME##_assign) ) = zxv_##NAME##_resize; \
  ZXV_APPEND(        NAME,     DLL ); \
  ZXV_PUSH_BACK(     NAME,     DLL ); \
  ZXV_POP_BACK(      NAME,     DLL ); \
  ZXV_INSERT(        NAME,     DLL ); \
  ZXV_ERASE(         NAME,     DLL ); \
  ZXV_SWAP(          NAME,     DLL ); \
  ZXV_CLEAR(         NAME,     DLL ); \
  ZXV_REVERSE(       NAME,     DLL ); \
  ZXV_COPY(          NAME, T2, DLL ); \
  ZXV_AT(            NAME, T2, DLL ); \
  ZXV_ISEQUAL(       NAME,     DLL ); \
  DLL NAME*  zxv_##NAME##_cpyEql(        NAME         *obj, \
                                         NAME   const *src ); \
  ZXV_OPADD(         NAME,     DLL ); \
  ZXV__OPMVL(        NAME,    static, \
    (*zxv_##NAME##_opMvl) ) = zxv_##NAME##_opAdd; \
  ZXV_CMPEQ(         NAME,     DLL ); \
  ZXV_CMPNE(         NAME,     DLL )

#define ZXV_DEC_2ND( NAME, T, DLL ) \
  DLL void   zxv_##NAME##__init(         NAME         *obj, \
                                         T      const *src, \
                                         size_t       srcCount ); \
  ZXV__DEC_2ND( NAME, T, T, DLL )

/* This is intended for namespaces / namespace replacements (struct) */
/* TODO: finish defining ZXV_DEC_BODY macro */
#define ZXV__DEC_BODY( NAME, T, T2 ) \
  NAME const def; \
  void   (*_kill)(         NAME         *obj ); \
  ZXV__SIZE(          NAME,,      (*size)          ); \
  ZXV__MAX_SIZE(      NAME,,      (*max_size)      ); \
  ZXV__RESIZE(        NAME, T,,   (*resize)        ); \
  ZXV__CAPACITY(      NAME,,      (*capacity)      ); \
  ZXV__EMPTY(         NAME,,      (*empty)         ); \
  ZXV__RESERVE(       NAME,,      (*reserve)       ); \
  ZXV__GROW(          NAME, T,,   (*grow)          ); \
  ZXV__SHRINK(        NAME,,      (*shrink)        ); \
  ZXV__SHRINK_TO_FIT( NAME,,      (*shrink_to_fit) ); \
  ZXV__ASSIGN(        NAME, T,,   (*assign)        ); \
  ZXV__APPEND(        NAME,,      (*append)        ); \
  ZXV__PUSH_BACK(     NAME,,      (*push_back)     ); \
  ZXV__POP_BACK(      NAME,,      (*pop_back)      ); \
  ZXV__INSERT(        NAME,,      (*insert)        ); \
  ZXV__ERASE(         NAME,,      (*erase)         ); \
  ZXV__SWAP(          NAME,,      (*swap)          ); \
  ZXV__CLEAR(         NAME,,      (*clear)         ); \
  ZXV__REVERSE(       NAME,,      (*reverse)       ); \
  ZXV__COPY(          NAME, T2,,  (*copy)          ); \
  ZXV__AT(            NAME, T2,,  (*at)            ); \
  ZXV__ISEQUAL(       NAME,,      (*isEqual)       ); \
  NAME*   (*cpyEql)(       NAME         *obj, \
                           NAME   const *src ); \
  ZXV__OPADD(        NAME,,       (*opAdd)         ); \
  ZXV__OPMVL(        NAME,,       (*opMvl)         ); \
  ZXV__CMP(          NAME,,       (*cmpEQ)         ); \
  ZXV__CMP(          NAME,,       (*cmpNE)         )

#define ZXV_DEC_BODY( NAME, T ) \
  void   (*_init)(    NAME *src, \
                      T const *cpy, \
                      size_t count ); \
  ZXV__DEC_BODY( NAME, T, T )

/* We won't set def here, we'll let the developer do that */

#define ZXV_DEF_BODY( NAME, DEFAULT ) \
  zxv_##NAME##__init, DEFAULT, \
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


ZXC_SHUT

#endif