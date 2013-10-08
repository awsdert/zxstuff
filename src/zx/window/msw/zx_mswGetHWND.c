#include <zx/window.h>
ZXSYS_EXP zxWINDOW* zxGetWindowH( zxHandle hdl )
{
  zxuint i = 0u, count = zxGetWindowCount();
  zxWINDOW** windows = zxGetAllWindows();
  if ( windows == NULL )
    return NULL;
  for ( ; i < count; ++i )
  {
    if ( windows[ i ]->m_hdl == hdl )
      return windows[ i ];
  }
  return NULL;
}
