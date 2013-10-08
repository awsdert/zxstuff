#include <zx/window.h>
ZXSYS_EXP zxuint zx_ResizeWindows( zxuint newCount )
{
  zxuint i = zxGetWindowCount();
  size_t oSize = sizeof( zxWINDOW* ), aSize;
  zxWINDOW** windows = zxGetAllWindows();
  if ( oSize * newCount > SIZE_MAX )
    return i;
  aSize = oSize * newCount;
  if ( newCount > i )
  {
    if ( !windows )
      windows = (zxWINDOW**)malloc( aSize );
    else
      windows = (zxWINDOW**)realloc( windows, aSize );
  }
  for ( ; i < newCount; ++i )
    windows[ i ] = NULL;
  zx_SetWindowCount( newCount );
  zx_SetAllWindows( windows );
  return newCount;
}