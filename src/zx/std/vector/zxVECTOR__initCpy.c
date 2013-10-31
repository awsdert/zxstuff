#include <zx/std/vector.h>
ZXV__INITCPY( zxVECTOR, ZXCORE_EXP )
{
  *src = *cpy;
  src->m_data = mnew( src->m_fullSize, cpy->m_data );
}