#include <zx/std/char.h>
ZXCORE_EXP void zxCHAR__kill( zxCHAR *src )
{
  if ( !src )
    return;
  zxv._kill( &src->m_core );
  src->m_data = NULL;
}
