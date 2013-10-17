#include <zx/std/text.h>
void zxv_zxWIDE__init( zxWIDE *txt, wide const *src, size_t len )
{
  if ( !len )
    len = zxw.len( src );
  zxv._init( &txt->m_data, sizeof( wide ), (zxuc*)src, len );
  txt->m_text = (wide*)txt->m_data.m_data;
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( wide );
}
void zxv_zxWIDE__initC( zxWIDE *txt, char const *src, size_t len )
{
  size_t i  = 0;
  wide *dst = NULL;
  if ( !len )
    len = zxc.len( src );
  dst = (wide*)mnewa( sizeof( wide ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = src[ i ] & UCHAR_MAX;
  zxv._init( &txt->m_data, sizeof( wide ), (zxuc*)dst, len );
  free( dst );
  txt->m_text = (wide*)txt->m_data.m_data;
  --txt->m_data.m_count;
  txt->m_data.m_size -= sizeof( wide );
}