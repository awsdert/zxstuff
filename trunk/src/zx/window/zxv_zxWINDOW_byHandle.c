#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxv_zxWINDOW_byHandle( zxHwnd wh )
{
  zxVECTOR *data = zxwin.allWindows();
  zxWINDOW** ary = (zxWINDOW**)data->m_data;
  size_t i = 0;
  for ( ; i < data->m_count; ++i )
  {
    if ( ary[ i ]->m_wh == wh )
      return ary[ i ];
  }
  return NULL;
}