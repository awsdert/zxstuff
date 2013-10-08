#include <zx/std/wide.h>
ZXCORE_EXP void zxv_zxWIDE__kill( zxWIDE *txt )
{
  if ( !txt )
    return;
  zxv._kill( &txt->m_data );
  txt->m_text = NULL;
}
