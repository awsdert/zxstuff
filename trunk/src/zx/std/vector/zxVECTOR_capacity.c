#include <zx/std/vector.h>
ZXV_CAPACITY( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  ZXASSERT( !src ) return 0;
  return src->m_fullSize;
}
