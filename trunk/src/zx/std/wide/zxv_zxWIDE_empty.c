#include <zx/std/wide.h>
ZXCORE_EXP bool zxv_zxWIDE_empty( zxWIDE const *txt )
{
  if ( !txt )
    return true;
  return zxv.empty( &txt->m_data );
}