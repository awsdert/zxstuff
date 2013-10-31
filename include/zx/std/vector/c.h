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

/* TODO: finish defining ZXV_DEC_2ND macro */
#define ZXV__DEC_2ND( NAME, T, T2, DLL ) \
  ZXV__INITCPY(      NAME,     DLL ); \
  ZXV__KILL(         NAME,     DLL ); \
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
    (*NAME##_assign) ) = NAME##_resize; \
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
  ZXV_CPYEQL(        NAME,     DLL ); \
  ZXV_OPADD(         NAME,     DLL ); \
  ZXV__OPMVL(        NAME,    static, \
    (*NAME##_opMvl) ) = NAME##_opAdd; \
  ZXV_CMPEQ(         NAME,     DLL ); \
  ZXV_CMPNE(         NAME,     DLL )

#define ZXV_DEC_2ND( NAME, T, DLL ) \
  ZXV__INIT(         NAME, T, DLL ); \
  ZXV__DEC_2ND(   NAME, T, T, DLL )

/* This is intended for namespaces / namespace replacements (struct) */
/* TODO: finish defining ZXV_DEC_BODY macro */
#define ZXV__DEC_BODY( NAME, T, T2 ) \
  NAME const def; \
  ZXV___INITCPY(      NAME,,      (*_initCpy)      ); \
  ZXV___KILL(         NAME,,      (*_kill)         ); \
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
  ZXV__CPYEQL(        NAME,,      (*cpyEql)        ); \
  ZXV__OPADD(         NAME,,      (*opAdd)         ); \
  ZXV__OPMVL(         NAME,,      (*opMvl)         ); \
  ZXV__CMP(           NAME,,      (*cmpEQ)         ); \
  ZXV__CMP(           NAME,,      (*cmpNE)         )

#define ZXV_DEC_BODY( NAME, T ) \
  ZXV___INIT(         NAME, T,,   (*_init)         ); \
  ZXV__DEC_BODY(   NAME, T, T )

/* We won't set def here, we'll let the developer do that */

#define ZXV_DEF_BODY( NAME, DEFAULT ) \
  NAME##__init, DEFAULT, \
  NAME##__initCpy, \
  NAME##__kill, \
  NAME##_size, \
  NAME##_max_size, \
  NAME##_resize, \
  NAME##_capacity, \
  NAME##_empty, \
  NAME##_reserve, \
  NAME##_grow, \
  NAME##_shrink, \
  NAME##_shrink_to_fit, \
  NAME##_resize, \
  NAME##_append, \
  NAME##_push_back, \
  NAME##_pop_back, \
  NAME##_insert, \
  NAME##_erase, \
  NAME##_swap, \
  NAME##_clear, \
  NAME##_reverse, \
  NAME##_copy, \
  NAME##_at, \
  NAME##_isEqual, \
  NAME##_cpyEql, \
  NAME##_opAdd, \
  NAME##_opAdd, \
  NAME##_cmpEQ, \
  NAME##_cmpNE
/**/


ZXC_SHUT

#endif