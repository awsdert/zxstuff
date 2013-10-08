#include <zx/std/char.h>
ZXCORE_EXP bool zxv_zxCHAR_cmpNE(
  zxCHAR const *txt,
  zxCHAR const *src )
{
  return !zxc.isEqual( txt, src, NULL );
}