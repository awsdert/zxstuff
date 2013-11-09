/* USER: AWSDERT; DATE: 07/11/2013; TIME: 18:29 */
#include <zx/std/vector.h>
ZXV_TMPOBJ( zxVECTOR, void*, ZXCORE_EXP )
{
  zxVECTOR tmp = {0};
  tmp.m_data = src;
  tmp.m_count = 1;
  tmp.m_fullCount = 1;
  tmp.m_isFixed = true;
  return tmp;
}