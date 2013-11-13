#include <zx/std/char.h>
ZXV_SHRINK( zxCHAR, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  zxv.shrink( &src->m_core, setCount );
  src->m_data = (char*)src->m_core.m_data;
  src->m_data[ setCount - 1 ] = 0;
}
