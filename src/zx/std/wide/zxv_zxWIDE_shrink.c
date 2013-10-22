#include <zx/std/wide.h>
ZXV_SHRINK( zxWIDE, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxv.shrink( &src->m_core, setCount );
  src->m_data = (wide*)src->m_core.m_data;
  src->m_data[ setCount - 1 ] = 0;
}