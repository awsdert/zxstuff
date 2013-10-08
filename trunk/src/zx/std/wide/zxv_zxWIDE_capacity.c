#include <zx/std/wide.h>
ZXCORE_EXP size_t zxv_zxWIDE_capacity( zxWIDE const *txt )
{
  if ( !txt )
    return 0;
  return zxv.capacity( &txt->m_data );
}