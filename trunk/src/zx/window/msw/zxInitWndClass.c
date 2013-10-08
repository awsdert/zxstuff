#include <zx/window.h>
#if ZXMSW
void zxInitWndClass( zxWndClass *wc )
{
  wc->style         = 0u;
  wc->hInstance     = zxGetThisI();
  wc->lpszMenuName  = NULL;
  wc->lpszClassName = NULL;
  wc->lpfnWndProc   = zx_mswEvent;
  wc->cbClsExtra    = 0;
  wc->cbWndExtra    = 0;
  wc->hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc->hIcon         = NULL;
}
#endif
