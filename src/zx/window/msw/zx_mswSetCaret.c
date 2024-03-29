#include <zx/window.h>
#if ZXMSW
zxui zx_mswSetCaret( HWND wh, int line, int pos )
{
  RECT cRect = {0}, rect = {0};
  POINT pt;
  HDC  dc = NULL;
  TEXTMETRIC tm;
  if ( !GetWindowRect( wh, &rect ) )
    return 0u;
  if ( !GetClientRect( wh, &cRect ) )
    return 0u;
  pt.x = ( rect.right - rect.left ) - cRect.right;
  pt.y = ( rect.bottom - rect.top ) - cRect.bottom;
  rect.left   += pt.x;
  rect.right  -= pt.x;
  rect.top    += pt.y;
  rect.bottom -= pt.y;
  dc = GetDC( NULL );
  if ( !dc )
    return 0u;
  GetTextMetrics( dc, &tm );
  line *= tm.tmHeight;
  pos  *= tm.tmAveCharWidth;
  line += rect.top;
  pos  += rect.left;
  SetCaretPos( pos, line );
  return 1u;
}
#endif
