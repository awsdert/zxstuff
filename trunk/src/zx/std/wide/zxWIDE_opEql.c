#include <zx/std/wide.h>
ZXV_OPEQL( zxWIDE, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src || !cpy )
    return src;
  zxv.opEql( &src->m_core, &cpy->m_core );
  src->m_data = (wide*)src->m_core.m_data;
  return src;
}
