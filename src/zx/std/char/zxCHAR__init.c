#include <zx/std/text.h>
ZXV__INIT( zxCHAR, char, ZXCORE, ZXCORE_CALL )
{
  if ( !count && cpy )
    count = strlen( cpy ) & ZXUINT_MAX;
  zxv._init( &src->m_core, sizeof( char ), cpy, count, (void**)&src->m_data );
  zxv.grow( &src->m_core, count + 1, NULL );
  zxv.erase( &src->m_core, -1, -1 );
}
ZXV___INIT( zxCHAR, wide, ZXCORE, ZXCORE_CALL zxCHAR__initW )
{
  zxui i  = 0;
  char *dst = NULL;
  if ( !count && cpy )
    count = wcslen( cpy ) & ZXUINT_MAX;
  dst = (char*)mnewa( sizeof( char ), NULL, count );
  for ( ; i < count; ++i )
    dst[ i ] = cpy[ i ] & UCHAR_MAX;
  zxv._init( &src->m_core, sizeof( char ), dst, count, (void**)&src->m_data );
  zxv.grow( &src->m_core, count + 1, NULL );
  zxv.erase( &src->m_core, -1, -1 );
  free( dst );
}
ZXV_DEF__INITCPY( zxCHAR, char, ZXCORE, ZXCORE_CALL )
