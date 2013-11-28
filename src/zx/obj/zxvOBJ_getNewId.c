#include "zxobj.h"
size_t ZXCORE_CALL zxvOBJ_getNewId( void )
{
  zxvOBJ *all = zxobj.all();
  zxOBJ   obj = {0};
  size_t i = 0, size = zxobj.size( all );
  for ( ; i < size; ++i )
  {
    if ( !all->m_data[ i ].obj )
      return i;
  }
  zxobj.grow( all, i + 1, obj );
  all->m_data[ i ].id = i;
  return i;
}
