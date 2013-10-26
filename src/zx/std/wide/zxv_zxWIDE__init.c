#include <zx/std/wide.h>
void zxv_zxWIDE__init( zxWIDE *src, wide const *cpy, size_t len )
{
  if ( !len )
    len = wcslen( cpy );
  zxv._init( &src->m_core, sizeof( wide ), cpy, len );
  src->m_core.m_ptr = (void**)&( (*src).m_data );
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
}
void zxv_zxWIDE__initC( zxWIDE *src, char const *cpy, size_t len )
{
  size_t i  = 0;
  wide *dst = NULL;
  if ( !len )
    len = strlen( cpy );
  dst = (wide*)mnewa( sizeof( wide ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = cpy[ i ];
  zxv._init( &src->m_core, sizeof( wide ), dst, len );
  src->m_core.m_ptr = (void**)&( (*src).m_data );
  
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
  free( dst );
}