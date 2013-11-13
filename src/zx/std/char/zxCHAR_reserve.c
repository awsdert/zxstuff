#include <zx/std/char.h>
ZXV_RESERVE( zxCHAR, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  minSize += sizeof( char );
  zxv.reserve( &src->m_core, minSize );
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( char );
  src->m_data = (char*)src->m_core.m_data;
}
