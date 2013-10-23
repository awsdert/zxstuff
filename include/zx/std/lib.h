#pragma once
#include "../limits.h"
#if ZXCPP
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#ifndef ZXSTDLIB
#define ZXSTDLIB
ZXC_OPEN

#define ZXNEW( PTR, NAME, COPY ) \
  PTR = (NAME*)malloc( sizeof( NAME ) ); *PTR = *(NAME*)COPY
#define ZXDEL( PTR ) \
  free( PTR ); PTR = NULL
ZXCORE void*
  mnew(
    size_t const Tsize,
    void*  const cpy );
ZXCORE void*
  mnewa(
    size_t const Tsize,
    void*  const cpy,
    size_t setCount );
ZXCORE void*
  mrenew(
    void*  dst,
    size_t count,
    size_t const Tsize,
    void*  const cpy,
    size_t setCount );
ZXCORE void*
  mdel( void* ptr );
ZXCORE void
  mcpy(
    void       *dst,
    void const *cpy,
    size_t const size );
ZXCORE void
  mset(
    void*  ptr,
    zxuc   const val,
    size_t const size );
ZXC_SHUT
#endif
