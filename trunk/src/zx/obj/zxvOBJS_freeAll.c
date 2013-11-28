/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:41 */
#include <zx/obj.h>
ZXCORE int ZXCORE_CALL zxvOBJ_freeAll( int returnCode )
{
  zxobj._kill( zxobj.all() );
  return returnCode;
}
