#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxv_zxWINDOW_getWindow( size_t id )
{
  zxVECTOR* data = zxwin.allWindows();
  zxWINDOW** ary = (zxWINDOW**)data->m_data;
  if ( id < data->m_count )
    return ary[ id ];
  return NULL;
}