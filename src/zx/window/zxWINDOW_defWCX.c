#include "zxwin.h"
ZXSYS zxWCX zxWINDOW_defWCX( size_t type )
{
  zxWCX wcx = {0};
#if ZXMSW
  wcx.hInstance     = zxGetThisI();
  wcx.cbSize        = sizeof(zxWCX);
  wcx.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wcx.lpszClassName = WC_STATIC;
  wcx.lpfnWndProc   = zxevt.onEvent;
  switch ( type )
  {
  case zxWIN_TBOX:
    wcx.lpszClassName = WC_EDIT;
    wcx.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
  }
#endif
  return wcx;
}
