/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:41 */
#include <zx/obj.h>
ZXCORE_EXP int zxOBJS_freeAll( int returnCode )
{
  zxobj._kill( zxobj.allObjects() );
  return returnCode;
}