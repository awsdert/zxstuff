#include <zx/std/vector.h>
ZXV_MAX_SIZE( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return 0;
  return src->m_fullCount;
}
