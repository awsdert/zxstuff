#include <zx/std/char.h>
ZXV_RESIZE( zxCHAR, char, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  zxv.resize( &src->m_core, setCount + 1, (zxuc*)&setNew );
  zxv.resize( &src->m_core, setCount, NULL );
  src->m_data = (char*)src->m_core.m_data;
  src->m_data[ setCount ] = 0;
}
