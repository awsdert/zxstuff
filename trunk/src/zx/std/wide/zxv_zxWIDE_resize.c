#include <zx/std/wide.h>
ZXV_RESIZE( zxWIDE, wide, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxv.resize( &src->m_core, setCount + 1, (zxuc*)&setNew );
  zxv.resize( &src->m_core, setCount, NULL );
  src->m_data = (wide*)src->m_core.m_data;
  src->m_data[ setCount ] = 0;
}