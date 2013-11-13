#include <zx/tbox.h>
ZXSYS zxsl zxTBOX_onChar( zxEVENT* event )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_obj.gid );
  zxTBOX *tbox = NULL;
  zxTEXT    *text = NULL, ins = zxstr.def;
#if ZXMSW
  WORD vk = LOWORD( event->m_mswWP );
  event->m_stopEvent = true;
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  tbox = (zxTBOX*)win;
  text = win->m_txt;
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
    if ( vk < UCHAR_MAX )
    {
      zxstr.grow( &ins, 1, vk & UCHAR_MAX );
      zxstr.insert( text, &ins, tbox->m_pos + 1 );
      ++tbox->m_pos;
    }
  }
  if ( !zxtbox._setCaret( tbox ) )
    return 3;
  return 0;
#else
  text->m_len  = GetWindowTextLength( win->m_wh ) + 1;
  if ( !text->m_text )
    text->m_full = zxstr.New( &text->m_text, zxt(""), 0u, 0u );
  text->m_full = zxstr.Grow( &text->.m_text, text->m_full, text->m_len );
  if ( tbox->m_text.m_text )
    GetWindowText( win->m_wh, text->m_text, text->m_len );
  return 0;
#endif
#endif
}
