#include "c.h"

#ifndef ZXVECTOR_OBJ_H
#define ZXVECTOR_OBJ_H

ZXC_OPEN

/*
  Since c89/90 does not provide namespaces we provide an alternative instead
  This makes it simpler to program because the IDE can find the
  list of functions more easily and the developer only has to remember the
  name of the struct namespace he needs.
*/

ZXV_DEC_1ST( zxVECTOR )
{
  void*   m_data;
  void**  m_ptr;
  bool    m_isFixed;
  size_t  m_Tsize;
  size_t  m_count, m_fullCount;
  size_t  m_size,  m_fullSize;
} zxVECTOR;

ZXCORE void   zxv_zxVECTOR__init(
  zxVECTOR       *src,
  size_t         Tsize,
  zxuc     const *cpy,
  size_t         count );
ZXV__DEC_2ND( zxVECTOR, zxuc*, zxuc, ZXCORE );

ZXNSO( v )
{
  void (*_init)(
    zxVECTOR   *src, size_t Tsize,
    void const *cpy, size_t count );
  ZXV__DEC_BODY( zxVECTOR, zxuc*, zxuc );
} zxn_v;

static const zxn_v zxv = { ZXV_DEF_BODY( zxVECTOR, {0} ) };

/* refer to wide.h for full example of macros in use */

ZXC_SHUT

#endif