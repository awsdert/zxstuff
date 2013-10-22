#include <zx/window.h>
ZXSYS_EXP void zxv_zxWINDOW__initWCX( zxWCX *wc )
{
#if ZXMSW
  wc->style         = 0u;
  wc->hInstance     = zxGetThisI();
  wc->lpszMenuName  = NULL;
  wc->lpszClassName = NULL;
  wc->lpfnWndProc   = zxroot_onEvent;
  wc->cbClsExtra    = 0;
  wc->cbWndExtra    = 0;
  wc->cbSize        = sizeof(WNDCLASSEX);
  wc->hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc->hIcon         = NULL;
  wc->hIconSm       = NULL;
#endif
}
