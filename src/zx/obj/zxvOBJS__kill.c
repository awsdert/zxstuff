/* USER: AWSDERT; DATE: 09/11/2013; TIME: 07:43 */
#include <zx/obj.h>
ZXV__KILL( zxvOBJ, ZXCORE, ZXCORE_CALL )
{
  size_t i = 0, stop = zxobj.size( src );
  zxOBJ obj;
  ZXASSERT( !src ) return;
  if ( !stop ) return;
  do
  {
    obj = src->m_data[ i ];
    if ( obj.del )
      obj.del( obj.obj, obj.type );
    else if ( obj.obj )
      free( obj.obj );
    ++i;
  }
  while ( i <stop );
  zxv._kill( &src->m_core );
}
