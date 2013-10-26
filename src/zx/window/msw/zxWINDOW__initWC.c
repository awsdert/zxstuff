#include <zx/window.h>
ZXSYS_EXP void zxWINDOW__initWC( zxWC *wc )
{
 *wc = zxwin.defWC;
#if ZXMSW
  wc->hInstance     = zxGetThisI();
  wc->hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wc->lpfnWndProc   = zxevt.onEvent;
#if 0
  wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
#endif
#endif
}
