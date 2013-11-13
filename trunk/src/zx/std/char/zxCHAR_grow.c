#include <zx/std/char.h>
ZXV_GROW( zxCHAR, char, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  zxv.grow( &src->m_core, setCount + 1, (zxuc*)&setNew );
  zxv.grow( &src->m_core, setCount, NULL );
  src->m_data = (char*)src->m_core.m_data;
}
