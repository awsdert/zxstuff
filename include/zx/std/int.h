#pragma once
#include "../limits.h"
#if ZXCPP
#include <cstdint>
#elif ZXC >= 99
#include <stdint.h>
#endif

#ifndef ZXSTD_INT_H
#define ZXSTD_INT_H

#ifdef ZXILL

#endif


#if ZXCHAR_BITS == 8
#define ZXI8 char
#endif

#if ZXSHRT_BITS == 16
#define ZXI16 short
#endif

#if ZXLONG_BITS == 32
#define ZXI32 long
#elif ZXINT_BITS == 32
#define ZXI32 int
#endif

#if ZXILL_BITS == 64
#define ZXI64 ZXILL
#elif ZXINT_BITS == 64
#define ZXI64 int
#endif

#endif

/* This helps bypass compile issues when conforming to ansi c89/c90 */
#ifndef _STDINT
#define _STDINT

#ifdef ZXI8
typedef   signed ZXI8   int8_t;
typedef unsigned ZXI8  uint8_t;
typedef   signed ZXI8   int_least8_t;
typedef unsigned ZXI8  uint_least8_t;
typedef   signed ZXI8   int_fast8_t;
typedef unsigned ZXI8  uint_fast8_t;
#define INT8_MIN  -0X80
#define INT8_MAX   0X7F
#define UINT8_MAX  0xFFU
#endif

#ifdef ZXI16
typedef   signed ZXI16  int16_t;
typedef unsigned ZXI16 uint16_t;
typedef   signed ZXI16  int_least16_t;
typedef unsigned ZXI16 uint_least16_t;
#ifdef ZX32
typedef   signed ZXI32  int_fast16_t;
typedef unsigned ZXI32 uint_fast16_t;
#else
typedef   signed ZXI16  int_fast16_t;
typedef unsigned ZXI16 uint_fast16_t;
#endif
#define INT16_MIN -0X8000
#define INT16_MAX  0X7FFF
#define UINT16_MAX 0xFFFFU
#endif

#ifdef ZXI32
typedef   signed ZXI32  int32_t;
typedef unsigned ZXI32 uint32_t;
typedef   signed ZXI32  int_least32_t;
typedef unsigned ZXI32 uint_least32_t;
typedef   signed ZXI32  int_fast32_t;
typedef unsigned ZXI32 uint_fast32_t;
#define INT32_MIN -0X80000000
#define INT32_MAX  0X7FFFFFFF
#define UINT32_MAX 0xFFFFFFFFU
#endif

#ifdef ZXI64
typedef   signed ZXI64  int64_t;
typedef unsigned ZXI64 uint64_t;
typedef   signed ZXI64  int_least64_t;
typedef unsigned ZXI64 uint_least64_t;
typedef   signed ZXI64  int_fast64_t;
typedef unsigned ZXI64 uint_fast64_t;
#define INT64_MIN -0X8000000000000000LL
#define INT64_MAX  0X7FFFFFFFFFFFFFFFLL
#define UINT64_MAX 0xFFFFFFFFFFFFFFFFULL
#endif

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED

#if ZXMSW == 64
typedef __int64 intptr_t;
#elif ZXMSW == 32
typedef _W64 int intptr_t;
#else
typedef int intptr_t;
#endif

#endif

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED

#if ZXMSW == 64
typedef __int64 uintptr_t;
#elif ZXMSW == 32
typedef _W64 int uintptr_t;
#else
typedef int intptr_t;
#endif

#endif

#endif
