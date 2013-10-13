#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxo_zxWINDOW_byHandle( zxHandle wh )
{
  zxVECTOR *data = zxwin.allWindows();
  zxWINDOW** ary = (zxWINDOW**)data->m_data;
  size_t i = 0;
  for ( ; i < data->m_count; ++i )
  {
    if ( ary[ i ]->m_core->m_hdl == wh )
      return ary[ i ];
  }
  return NULL;
}