#include <zx/std/wide.h>
ZXCORE_EXP size_t zxv_zxWIDE_copy( zxWIDE const *txt, wide* dst, size_t const dstLen, size_t const from )
{
  if ( !txt )
    return 0;
  return zxv.copy( &txt->m_data, (zxuc*)dst, dstLen, from );
}