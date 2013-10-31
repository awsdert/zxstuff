#include <zx/tbox.h>
ZXSYS_EXP zxTBOX* zxTBOX_opNew( zxWINDOW *win )
{
  zxTBOX   *tbox = (zxTBOX*)mnew( sizeof( zxTBOX ), NULL );
  zxEVENTS *evts = zxevt.getDefEvents();
  zxEVTPTR ptr;
  size_t i = 0;
  win   = zxwin.opNew( win );
  tbox->m_win   = win;
  win->m_win    = zxWIN_TBOX;
  win->m_winObj = tbox;
  zxstr._init( &tbox->m_text, NULL, 0 );
  tbox->m_pos  = 0;
#if ZXMSW
  tbox->m_font = NULL;
#endif
  for ( ; i < zxEVT_COUNT; ++i )
  {
    ptr.proc = zxtbox.events[ i ];
    if ( ptr.proc )
    {
      ptr.type = (zxEVT)i;
      zxevt.addEvent( evts, ptr );
    }
  }
  return tbox;
}
