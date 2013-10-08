#include <zx/vli.h>
ZXCORE_EXP void zxcInit_zxVLI( zxVLI *obj )
{
  if ( obj )
    *obj = zxvli.def;
}