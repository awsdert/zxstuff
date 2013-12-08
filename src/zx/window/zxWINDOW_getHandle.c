#include <zx/window.h>
ZXSYS zxHwnd zxWINDOW_getHandle( zxui wid )
{
  zxWH *wh = zxwh.at( zxwh.all(), wid );
  if ( wh )
    return wh->wh;
  return NULL;
}
