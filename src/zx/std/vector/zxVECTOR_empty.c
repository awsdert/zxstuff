#include <zx/std/vector.h>
ZXV_EMPTY( zxVECTOR, ZXCORE, ZXCORE_CALL )
{
  return ( src && src->m_data && src->m_size );
}
