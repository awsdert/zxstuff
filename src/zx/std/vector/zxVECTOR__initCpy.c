#include <zx/std/vector.h>
ZXV__INITCPY( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  *src = *cpy;
  src->m_data = mnew( src->m_fullSize, cpy->m_data );
}
