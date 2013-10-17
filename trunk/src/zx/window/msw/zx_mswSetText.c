#include <zx/textbox.h>
#if ZXMSW
ZXSYS_EXP zxui zx_mswSetText(
  HWND wh,
  zxTEXT* text,
  int line,
  int pos,
  HBRUSH bg )
{
  RECT cRect = {0}, rect = {0};
  POINT pt;
  TEXTMETRIC tm;
  HDC  dc = GetDC( NULL );
  if ( !dc )
    return 0u;
  GetWindowRect( wh, &rect );
  GetClientRect( wh, &cRect );
  pt.x = ( rect.right - rect.left ) - cRect.right;
  pt.y = ( rect.bottom - rect.top ) - cRect.bottom;
  rect.left   += pt.x;
  rect.right  -= pt.x;
  rect.top    += pt.y;
  rect.bottom -= pt.y;
  GetTextMetrics( dc, &tm );
  SetCaretPos( ( pos * tm.tmAveCharWidth ) - ( pt.x >> 1 ),
    ( line * tm.tmHeight ) + ( pt.y >> 1 ) );
  FillRect( dc, &rect, bg );
  DrawText( dc, text->m_text, text->m_data.m_count, &rect,
    DT_LEFT | DT_SINGLELINE | DT_END_ELLIPSIS | DT_VCENTER );
  ReleaseDC( NULL, dc );
  return 1u;
}
#endif
