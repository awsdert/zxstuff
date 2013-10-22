#include <zx/std/text.h>
void zxv_zxWIDE__init( zxWIDE *src, wide const *cpy, size_t len )
{
  if ( !len )
    len = zxw.len( cpy );
  zxv._init( &src->m_core, sizeof( wide ), cpy, len );
  src->m_data = (wide*)src->m_core.m_data;
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( wide );
}
void zxv_zxWIDE__initC( zxWIDE *src, char const *cpy, size_t len )
{
  size_t i  = 0;
  wide *dst = NULL;
  if ( !len )
    len = zxc.len( cpy );
  dst = (wide*)mnewa( sizeof( wide ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = cpy[ i ] & UCHAR_MAX;
  zxv._init( &src->m_core, sizeof( wide ), (zxuc*)dst, len );
  free( dst );
  src->m_data = (wide*)src->m_core.m_data;
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( wide );
}