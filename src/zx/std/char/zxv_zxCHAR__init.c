#include <zx/std/text.h>
void zxv_zxCHAR__init( zxCHAR *txt, char const *src, size_t len )
{
  if ( !len )
    len = zxc.len( src );
  zxv._init( &txt->m_data, sizeof( char ), (zxuc*)src, len );
  txt->m_text = (char*)txt->m_data.m_data;
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
}
void zxv_zxCHAR__initW( zxCHAR *txt, wide const *src, size_t len )
{
  size_t i  = 0;
  char *dst = NULL;
  if ( !len )
    len = zxw.len( src );
  dst = (char*)mnewa( sizeof( char ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = src[ i ] & UCHAR_MAX;
  zxv._init( &txt->m_data, sizeof( char ), (zxuc*)dst, len );
  free( dst );
  txt->m_text = (char*)txt->m_data.m_data;
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( char );
}