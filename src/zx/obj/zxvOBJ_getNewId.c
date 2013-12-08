#include "zxobj.h"
zxui ZXCORE_CALL zxvOBJ_getNewId( void )
{
  zxvOBJ *all = zxobj.all();
  zxOBJ   obj = {0};
  zxui i = 0, size = zxobj.size( all );
  if ( !size )
    goto zxvOBJ_getNewId_return;
  do
  {
    if ( !all->m_data[ i ].obj )
      return i;
    ++i;
  }
  while ( i < size );
zxvOBJ_getNewId_return:
  zxobj.grow( all, i + 1, obj );
  all->m_data[ i ].id = i;
  return i;
}
