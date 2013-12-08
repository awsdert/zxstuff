#include <zx/std/wide.h>
ZXV__INIT( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
{
  if ( !count && cpy )
    count = wcslen( cpy ) & ZXUINT_MAX;
  zxv._init( &src->m_core, sizeof( wide ), cpy, count, (void**)&src->m_data );
  zxv.grow( &src->m_core, count + 1, NULL );
  zxv.erase( &src->m_core, -1, -1 );
}
ZXV___INIT( zxWIDE, char, ZXCORE, ZXCORE_CALL zxWIDE__initC )
{
  zxui i  = 0;
  wide *dst = NULL;
  if ( !count && cpy )
    count = strlen( cpy ) & ZXUINT_MAX;
  dst = (wide*)mnewa( sizeof( wide ), NULL, count );
  for ( ; i < count; ++i )
    dst[ i ] = cpy[ i ];
  zxv._init( &src->m_core, sizeof( wide ), dst, count, (void**)&src->m_data );
  zxv.grow( &src->m_core, count + 1, NULL );
  zxv.erase( &src->m_core, -1, -1 );
  free( dst );
}
ZXV_DEF__INITCPY( zxWIDE, wide, ZXCORE, ZXCORE_CALL )
