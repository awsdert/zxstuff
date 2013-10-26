#include <zx/window.h>
ZXSYS_EXP void zxWINDOW__initWCX( zxWCX *wcx )
{
  *wcx = zxwin.defWCX;
#if ZXMSW
  wcx->hInstance     = zxGetThisI();
  wcx->cbSize        = sizeof(zxWCX);
  wcx->hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wcx->lpfnWndProc   = zxevt.onEvent;
#if 0
  wcx->hCursor       = LoadCursor(NULL, IDC_ARROW);
#endif
#endif
}
