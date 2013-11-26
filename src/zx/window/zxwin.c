#include "zxwin.h"
zxn_win const zxwin =
{
  {0}, {-1}, {0},
  zxWINDOW_defWCX,
  zxWINDOW_osOpNew,
#if ZXMSW
  {0},
#endif
  zxWINDOW__initWC,
  zxWINDOW__initWCX,
  zxWINDOW_getHandle,
  zxWINDOW_getRootWindow,
  zxWINDOW_getRootWH,
  zxWINDOW_getWindow,
  zxWINDOW_isKnown,
  zxWINDOW_byHandle,
  zxWINDOW_setBase,
  zxWINDOW_setBase,
  zxWINDOW_addKid,
  zxWINDOW_remKid,
  zxWINDOW_getKid,
  zxWINDOW_addKid,
  zxWINDOW_remKid,
  zxWINDOW_getKid,
  zxWINDOW_getNext,
  zxWINDOW_getPrev,
  zxWINDOW_opNew,
  zxWINDOW_opDel,
  zxWINDOW_setFocus,
  zxWINDOW_getFocus,
  zxWINDOW_freeAll,
  zxWINDOW_show,
  zxWINDOW_hide,
  zxWINDOW_update,
  zxWINDOW_fromPoint
};
