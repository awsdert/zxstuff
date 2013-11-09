/* USER: AWSDERT; DATE: 07/11/2013; TIME: 18:21 */
#include <zx/obj.h>
zxOBJS zx_l_allObjects = {0};
ZXSYS_EXP zxOBJS* zxOBJS_allObjects( void )
{
  return &zx_l_allObjects;
}