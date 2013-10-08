#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_pop_back( zxWIDE *txt )
{
  if ( !txt )
    return;
  zxv.pop_back( &txt->m_data );
}