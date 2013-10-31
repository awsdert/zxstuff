#include <zx/std/char.h>
ZXCORE_EXP bool zxCHAR_cmpEQ( zxCHAR const *txt, zxCHAR const *src )
{
  return zxc.isEqual( txt, src, NULL );
}