#include <zx/std/text.h>
void zxCHAR__init( zxCHAR *src, char const *cpy, size_t len )
{
  if ( !len && cpy )
    len = strlen( cpy );
  zxv._init( &src->m_core, sizeof( char ), (zxuc*)cpy, len );
  src->m_core.m_ptr = (void**)&( src->m_data );
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
}
void zxCHAR__initW( zxCHAR *src, wide const *cpy, size_t len )
{
  size_t i  = 0;
  char *dst = NULL;
  if ( !len && cpy )
    len = wcslen( cpy );
  dst = (char*)mnewa( sizeof( char ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = cpy[ i ] & UCHAR_MAX;
  zxv._init( &src->m_core, sizeof( char ), dst, len );
  src->m_core.m_ptr = (void**)&( src->m_data );
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
  free( dst );
}
ZXV_DEF__INITCPY( zxCHAR, char, ZXCORE, ZXCORE_CALL )
