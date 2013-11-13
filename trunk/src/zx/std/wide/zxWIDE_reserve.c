#include <zx/std/wide.h>
ZXV_RESERVE( zxWIDE, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return;
  minSize += sizeof( wide );
  zxv.reserve( &src->m_core, minSize );
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( wide );
  src->m_data = (wide*)src->m_core.m_data;
}
