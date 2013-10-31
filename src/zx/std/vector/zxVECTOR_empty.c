#include <zx/std/vector.h>
ZXV_EMPTY( zxVECTOR, ZXCORE_EXP )
{
  return ( src && src->m_data && src->m_size );
}