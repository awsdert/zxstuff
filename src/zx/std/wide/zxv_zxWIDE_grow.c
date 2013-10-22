#include <zx/std/wide.h>
ZXV_GROW( zxWIDE, wide, ZXCORE_EXP )
{
  ZXASSERT( !src ) return;
  zxv.grow( &src->m_core, setCount + 1, (zxuc*)&setNew );
  zxv.grow( &src->m_core, setCount, NULL );
  src->m_data = (wide*)src->m_core.m_data;
}

