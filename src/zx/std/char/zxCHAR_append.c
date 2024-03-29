#include <zx/std/char.h>
ZXV_APPEND( zxCHAR, ZXCORE, ZXCORE_CALL )
{
  if ( !src || !cpy || !cpy->m_core.m_data )
    return;
  --src->m_core.m_count;
  zxv.append( &src->m_core, &cpy->m_core, pos );
  src->m_data[ src->m_core.m_count - 1 ] = 0u;
}
