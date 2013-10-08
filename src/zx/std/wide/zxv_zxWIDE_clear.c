#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE_clear( zxWIDE *txt )
{
  if ( !txt )
    return;
  zxv.clear( &txt->m_data );
  txt->m_text = NULL;
}