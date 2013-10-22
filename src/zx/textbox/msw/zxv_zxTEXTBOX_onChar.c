#include <zx/textbox.h>
ZXSYS_EXP zxEvtCBR zxv_zxTEXTBOX_onChar( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL, ins = zxstr.def;
#if ZXMSW
#if 1
  WORD vk = LOWORD( event->m_mswWP );
#endif
  if ( win->m_win != zxWIN_TEXTBOX )
    return zxDefWinEvt;
  tbox = (zxTEXTBOX*)win;
  text = &tbox->m_text;
#if 1
  switch ( vk )
  {
  case VK_BACK:
    if ( tbox->m_pos > 0u )
    {
      zxstr.erase( text, tbox->m_pos - 1, tbox->m_pos );
      --tbox->m_pos;
    }
    break;
  default:
    if ( vk < UCHAR_MAX && zxstr.size( text ) < 5u )
    {
      zxstr.grow( &ins, 1, vk & UCHAR_MAX );
      zxstr.insert( text, &ins, tbox->m_pos + 1 );
      ++tbox->m_pos;
    }
    else
      return zxDefWinEvt;
  }
  if ( !zxtbox._drawText( tbox, true ) )
    return 3;
  return 0;
#else
  text->m_len  = GetWindowTextLength( win->m_wh ) + 1;
  if ( !text->m_text )
    text->m_full = zxstr.New( &text->m_text, zxt(""), 0u, 0u );
  text->m_full = zxstr.Grow( &text->.m_text, text->m_full, text->m_len );
  if ( tbox->m_text.m_text )
    GetWindowText( win->m_wh, text->m_text, text->m_len );
#endif
#endif
  return zxDefWinEvt;
}
