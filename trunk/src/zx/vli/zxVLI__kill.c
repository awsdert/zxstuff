#include <zx/vli.h>
ZXV__KILL( zxVLI, ZXCORE, ZXCORE_CALL )
{
  if ( !src ) return;
  zxv._kill( &src->m_core );
  *src = zxvli.def;
}
