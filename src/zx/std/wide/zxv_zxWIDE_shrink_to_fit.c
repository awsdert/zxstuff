#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_shrink_to_fit( zxWIDE *txt )
{
  if ( !txt )
    return;
  zxv.shrink_to_fit( &txt->m_data );
}