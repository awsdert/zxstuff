#include <zx/std/vector.h>
ZXV_AT( zxVECTOR, void, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src || !src->m_data || i >= src->m_count )
    return NULL;
  return &((zxuc*)src->m_data)[ i * src->m_Tsize ];
}
