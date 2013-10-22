#include <zx/std/text.h>
void zxv_zxCHAR__init( zxCHAR *src, char const *cpy, size_t len )
{
  if ( !len )
    len = zxc.len( cpy );
  zxv._init( &src->m_core, sizeof( char ), (zxuc*)cpy, len );
  src->m_data = (char*)src->m_core.m_data;
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( char );
}
void zxv_zxCHAR__initW( zxCHAR *src, wide const *cpy, size_t len )
{
  size_t i  = 0;
  char *dst = NULL;
  if ( !len )
    len = zxw.len( cpy );
  dst = (char*)mnewa( sizeof( char ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = cpy[ i ] & UCHAR_MAX;
  zxv._init( &src->m_core, sizeof( char ), (zxuc*)dst, len );
  free( dst );
  src->m_data = (char*)src->m_core.m_data;
  --src->m_core.m_count;
  src->m_core.m_size -= sizeof( char );
}