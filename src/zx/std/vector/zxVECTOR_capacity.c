#include <zx/std/vector.h>
ZXV_CAPACITY( zxVECTOR, ZXCORE_EXP )
{
  ZXASSERT( !src ) return 0;
  return src->m_fullSize;
}