/* USER: AWSDERT; DATE: 09/11/2013; TIME: 08:04 */
#include <zx/vli.h>
ZXV_DEF_SIZE( zxVLI, ZXCORE_EXP )
ZXV_DEF_MAX_SIZE( zxVLI, ZXCORE_EXP )
ZXCORE_EXP size_t zxVLI_bits( zxVLI const *src )
{
  ZXASSERT( !src ) return 0;
  return src->m_bits;
}
ZXCORE_EXP size_t zxVLI_max_bits( zxVLI const *src )
{
  ZXASSERT( !src ) return 0;
  return zxv.capacity( &src->m_core ) * CHAR_BIT;
}
ZXV_DEF_EMPTY( zxVLI, ZXCORE_EXP )