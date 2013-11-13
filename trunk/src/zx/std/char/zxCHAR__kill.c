#include <zx/std/char.h>
ZXV__KILL( zxCHAR, ZXCORE, ZXCORE_CALL )
{
  if ( !src )
    return;
  zxv._kill( &src->m_core );
  src->m_data = NULL;
}
