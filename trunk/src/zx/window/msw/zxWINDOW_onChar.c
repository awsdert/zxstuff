#include <zx/window.h>
#if ZXMSW
zxEvtCBR zxWINDOW_onChar( zxEVENT* event )
{
  return zxDefWinEvt;
}
#endif
