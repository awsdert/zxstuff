#include <zx/vli.h>
ZXV__KILL( zxVLI, ZXCORE_EXP )
{
  if ( !src ) return;
  zxv._kill( &src->m_core );
  *src = zxvli.def;
}