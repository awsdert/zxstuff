#include <zx/window.h>
ZXSYS zxHwnd zxWINDOW_getHandle( size_t wid )
{
  zxWH *wh = zxwh.at( zxwh.all(), wid );
  if ( wh )
    return wh->wh;
  return NULL;
}
