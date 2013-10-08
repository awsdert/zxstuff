#include <zx/textbox.h>
zxEvtCBR zxTEXTBOX__OnChar( zxWINDOW* win, zxEVENT* event )
{
#if ZXMSW
/* TODO: check for application's event handler */
  zxTEXTBOX *tbox = NULL;
  zxTEXT    *text = NULL;
#if 1
  char c = 0;
  WORD vk = LOWORD( event->mswWP );
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
      text->m_len = zxstr.Rem( text->m_text,
        tbox->m_pos - 1u, 1u, text->m_len );
      --tbox->m_pos;
      if ( text->m_len == 0u )
        text->m_len = 1u;
    }
    break;
  default:
    if ( vk < UCHAR_MAX && tbox->m_text.m_len < 20u )
    {
      c = vk & UCHAR_MAX;
      text->m_full = zxstr.Ins( &text->m_text, text->m_full, &c, 1u, tbox->m_pos + 1u );
      text->m_len  = zxstr.Len( text->m_text );
      if ( tbox->m_pos < ( text->m_len - 1u ) )
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
