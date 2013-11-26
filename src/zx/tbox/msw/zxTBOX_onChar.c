#include "../zxtbox.h"
ZXEVENT( zxTBOX_onChar )
{
  zxWINDOW  *win  = zxwin.getWindow( event->m_wid );
  zxTBOX    *tbox = NULL;
  zxTEXT    *text = NULL, ins = zxstr.def;
#if ZXMSW
  SHORT scancode = VkKeyScanW( LOWORD( event->m_wp ) );
  CHAR vk = LOBYTE( scancode ), xk = HIBYTE( scancode );
  if ( win->m_win != zxWIN_TBOX )
    return 0;
  event->m_stopEvent = true;
  tbox = (zxTBOX*)win->m_wObj.obj;
  text = &win->m_txt;
#if 1
  switch ( vk )
  {
  case VK_SHIFT:
  case VK_CONTROL:
  case VK_ESCAPE:
    return 0;
  case VK_BACK:
    if ( tbox->m_fc != tbox->m_lc )
      zxstr.erase( text, tbox->m_fc, tbox->m_lc );
    else if ( tbox->m_fc > 0u )
    {
      zxstr.erase( text, tbox->m_fc - 1, tbox->m_fc - 1 );
      --tbox->m_fc;
    }
    tbox->m_lc = tbox->m_fc;
    break;
  default:
    zxstr.grow( &ins, 1, vk );
    zxstr.insert( text, &ins, tbox->m_fc + 1 );
    ++tbox->m_fc;
    tbox->m_lc = tbox->m_fc;
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
  return 0;
#endif
#endif
}
