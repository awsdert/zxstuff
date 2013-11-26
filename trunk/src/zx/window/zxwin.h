#pragma once
#ifndef ZX__WIN_H
#define ZX__WIN_H
#include <zx/window.h>

ZXSYS void       zxWINDOW__initWC(    zxWC     *wc  );
ZXSYS void       zxWINDOW__initWCX(   zxWCX    *wcx );
ZXSYS zxHwnd     zxWINDOW_getHandle(  size_t    wid );
ZXSYS zxWINDOW*  zxWINDOW_getRootWindow( void );
ZXSYS zxHwnd     zxWINDOW_getRootWH( void );
ZXSYS zxWINDOW*  zxWINDOW_getWindow(  size_t    wid );
ZXSYS bool       zxWINDOW_isKnown(    zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_newWindow( zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_delWindow( zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_byHandle(   zxHwnd    wh );
ZXSYS zxuc       zxWINDOW_setCaret(
  zxWINDOW *win, zxui      line, zxui      pos );
ZXSYS bool       zxWINDOW_show(   zxWINDOW* win );
ZXSYS bool       zxWINDOW_hide(   zxWINDOW *win );
ZXSYS bool       zxWINDOW_update( zxWINDOW *win );
ZXSYS zxWCX      zxWINDOW_defWCX( size_t type );

#if ZXMSW
ZXSYS zxuc       zxWINDOW_mswSetText(
  zxWINDOW *win,
  zxTEXT   *txt,
  zxui     line,
  zxui     pos,
  HBRUSH   bg );
#endif

ZXSYS  zxsi       zxWINDOW_osOpNew( zxWINDOW *win );
ZXSYS  zxWINDOW*  zxWINDOW_opNew(    zxWINDOW *win );
ZXSYS  zxWINDOW*  zxWINDOW_opDel(    zxWINDOW *win );
ZXSYS  void       zxWINDOW_setBase(  zxWINDOW *win, zxWINDOW *base );
ZXSYS  void       zxWINDOW_addKid(   zxWINDOW *win, zxWINDOW *kid  );
ZXSYS  void       zxWINDOW_remKid(   zxWINDOW *win, zxWINDOW *kid  );
ZXSYS  zxWINDOW*  zxWINDOW_getKid(   zxWINDOW *win, size_t    i    );
ZXSYS  zxWINDOW*  zxWINDOW_getNext( zxWINDOW *win, bool nextKid );
ZXSYS  zxWINDOW*  zxWINDOW_getPrev( zxWINDOW *win );
/**
  @param returnCode The value you want returned
**/
ZXSYS void       zxWINDOW_setFocus( zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_getFocus( void );
ZXSYS int        zxWINDOW_freeAll( int returnCode );
ZXSYS zxWINDOW*  zxWINDOW_fromPoint( zxPOINT pt, zxus maxDepth );

ZXEVENT( zxWINDOW_onEvent );
ZXEVENT( zxWINDOW_onDestroy );
ZXEVENT( zxWINDOW_onQuit );
ZXEVENT( zxWINDOW_onKeyD );
ZXEVENT( zxWINDOW_onCurLD );

ZXSYS void zx_FreeWC( void );

#endif
