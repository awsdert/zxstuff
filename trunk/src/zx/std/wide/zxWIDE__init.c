#include <zx/std/wide.h>
void zxWIDE__init( zxWIDE *src, wide const *cpy, size_t len )
{
  if ( !len && cpy )
    len = wcslen( cpy );
  zxv._init( &src->m_core, sizeof( wide ), cpy, len, (void**)&src->m_data );
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
}
void zxWIDE__initC( zxWIDE *src, char const *cpy, size_t len )
{
  size_t i  = 0;
  wide *dst = NULL;
  if ( !len && cpy )
    len = strlen( cpy );
  dst = (wide*)mnewa( sizeof( wide ), NULL, len );
  for ( ; i < len; ++i )
    dst[ i ] = cpy[ i ];
  zxv._init( &src->m_core, sizeof( wide ), dst, len, (void**)&src->m_data );
  zxv.grow( &src->m_core, len + 1, NULL );
  zxv.erase( &src->m_core, len, len );
  free( dst );
}
ZXV_DEF__INITCPY( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
