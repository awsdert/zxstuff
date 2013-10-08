#include <zx/vli.h>
ZXCORE_EXP void zxcKill_zxVLI( zxVLI *obj )
{
  if ( obj )
  {
    if ( obj->m_vector.m_data )
      free( obj->m_vector.m_data );
    *obj = zxvli.def;
  }
}