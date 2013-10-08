#include <zx/textbox.h>
zxEvtCBR zxTEXTBOX__OnChar( zxWINDOW* win, zxEVENT* event )
{
#if ZXMSW
/* TODO: check for application's event handler */
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL, ins = zxstr.def;
#if 1
  WORD vk = LOWORD( event->m_mswWP );
#endif
  if ( win->m_winType != zxWIN_TEXTBOX )
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
    if ( vk < UCHAR_MAX && zxstr.size( text ) < 20u )
    {
      zxstr.grow( &ins, 1, vk & UCHAR_MAX );
      zxstr.insert( text, &ins, tbox->m_pos + 1 );
      ++tbox->m_pos;
    }
    else
      return zxDefWinEvt;
  }
  if ( !zx_TEXTBOX_DrawText( tbox, true ) )
    return 3;
  return 0;
#else
  text->m_len  = GetWindowTextLength( win->m_hdl ) + 1;
  if ( !text->m_text )
    text->m_full = zxstr.New( &text->m_text, zxt(""), 0u, 0u );
  text->m_full = zxstr.Grow( &text->.m_text, text->m_full, text->m_len );
  if ( tbox->m_text.m_text )
    GetWindowText( win->m_hdl, text->m_text, text->m_len );
  return zxDefWinEvt;
#endif
#else
  return zxDefWinEvt;
#endif
}
