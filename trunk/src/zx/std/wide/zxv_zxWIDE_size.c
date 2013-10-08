#include <zx/std/wide.h>
ZXCORE_EXP size_t zxv_zxWIDE_size( zxWIDE const *txt )
{
  if ( !txt )
    return 0;
  return zxv.size( &txt->m_data );
}