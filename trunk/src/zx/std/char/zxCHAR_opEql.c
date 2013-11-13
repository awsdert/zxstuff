#include <zx/std/char.h>
ZXV_OPEQL( zxCHAR, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src || !cpy ) return src;
  zxv.opEql( &src->m_core, &cpy->m_core );
  src->m_data = (char*)src->m_core.m_data;
  return src;
}
