#include <zx/window.h>
#if ZXMSW
zxEvtCBR zxv_zxWINDOW_onChar( zxEVENT* event )
{
  zxWINDOW* win;
  size_t i = 0, stop = 0;
  zxEVTPTR ptr;
  zxEvtCBR cbr = 0;
  if ( !event->m_ptrType && event->m_ptr )
  {
    win = (zxWINDOW*)event->m_ptr;
    stop = zxevt.size( &win->m_events );
    for ( ; i < stop; ++i )
    {
      ptr = win->m_events.m_data[ i ];
      if ( ptr.type == zxEVT_CHAR )
        cbr = ptr.event( event );
      if ( cbr != 0 )
        return cbr;
      if ( event->m_stopEvent )
        return 0;
    }
    if ( i == stop )
      return 0;
  }
  return zxDefWinEvt;
}
#endif
