#pragma once
#ifndef ZX_WINDOW_H
#define ZX_WINDOW_H
#include "window/msw.h"

ZXC_OPEN

enum
{
  zxOBJ_SYS_WIN = zxOBJ_COUNT + 1,
  zxOBJ_SYS_PROC,
  zxOBJ_SYS_COUNT
};

typedef struct zxWINDOW_struct
{
  size_t    m_base;
  zxvSIZE   m_kids;
  bool      m_class;
  zxOBJ     m_obj, m_wObj, m_uObj;
  zxul      m_style, m_stylex;
  bool      m_delKids;
  zxsi      m_x, m_y, m_w, m_h;
  zxTEXT   *m_txt;
  zxWIN     m_win;
  /* System Specfic */
  zxWCX    *m_wcx;
  zxHwnd    m_wh;
  zxEVENTS  m_events;
} zxWINDOW;

ZXV_OBJ( zxWINDOWS, zxWINDOW* );
ZXV_DEC( zxWINDOWS, zxWINDOW*, ZXSYS, ZXSYS_CALL );

ZXNSO( _win )
{
  ZXV_NS_DEC( zxWINDOWS, zxWINDOW*, ZXSYS_CALL );
} zxn__win;

static zxn__win const zx_win =
{
  ZXV_NS_DEF( zxWINDOWS, {0} )
};

ZXSYS zxInstance zxGetPrevI( void );
ZXSYS zxInstance zxGetThisI( void );
ZXSYS void       zxWINDOW__initWC(    zxWC     *wc  );
ZXSYS void       zxWINDOW__initWCX(   zxWCX    *wcx );
ZXSYS zxHwnd     zxWINDOW_getHandle(  size_t    wid );
ZXSYS zxWINDOW*  zxWINDOW_getRootWindow( void );
ZXSYS zxHwnd     zxWINDOW_getRootWH( void );
ZXSYS zxWINDOW*  zxWINDOW_getWindow(  size_t    wid );
ZXSYS bool       zxWINDOW_isKnown(    zxWINDOW* win );
ZXSYS zxWINDOWS* zxWINDOW_allWindows( void );
ZXSYS zxWINDOW*  zxWINDOW_newWindow( zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_delWindow( zxWINDOW* win );
ZXSYS zxWINDOW*  zxWINDOW_byHandle(   zxHwnd    wh );
ZXSYS zxuc       zxWINDOW_setCaret(
  zxWINDOW *win, zxui      line, zxui      pos );

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
/* Added for completeness */
static void
  (*zxWINDOW_setParent)(             zxWINDOW *win, zxWINDOW *parent ) = zxWINDOW_setBase;
static void
  (*zxWINDOW_addChild)(              zxWINDOW *win, zxWINDOW *child ) = zxWINDOW_addKid;
static void
  (*zxWINDOW_remChild)(              zxWINDOW *win, zxWINDOW *child ) = zxWINDOW_remKid;
static zxWINDOW*
  (*zxWINDOW_getChild)(   zxWINDOW *win, size_t    i    ) = zxWINDOW_getKid;
/**
  @param returnCode The value you want returned
**/
ZXSYS void       zxWINDOW_setFocus( zxWINDOW* win );
ZXSYS zxWINDOW * zxWINDOW_getFocus( void );
ZXSYS int        zxWINDOW_freeAll( int returnCode );

ZXSYS void zx_FreeWC( void );

ZXNSO( win )
{
  zxWINDOW  def;
  zxWC      defWC;
  zxWCX     WCX[ zxWIN_COUNT ], defWCX;
  zxsi       (*osOpNew)(  zxWINDOW  *win );
#if ZXMSW
  ATOM      mswATOMX[ zxWIN_COUNT ];
#endif
  void       (*_initWC)(    zxWC     *wc  );
  void       (*_initWCX)(   zxWCX    *wcx );
  zxHwnd     (*getHandle)(  size_t    wid );
  zxWINDOW*  (*getRootWindow)(  void );
  zxHwnd     (*getRootWH)( void );
  zxWINDOW*  (*getWindow)(  size_t    wid );
  bool       (*isKnown)(    zxWINDOW* win );
  zxWINDOWS* (*allWindows)( void );
  zxWINDOW*  (*byHandle)(   zxHwnd    wh );
  void       (*setBase)(    zxWINDOW *win, zxWINDOW *base );
  void       (*setParent)(  zxWINDOW *win, zxWINDOW *base );
  void       (*addKid)(     zxWINDOW *win, zxWINDOW *base );
  void       (*remKid)(     zxWINDOW *win, zxWINDOW *base );
  zxWINDOW*  (*getKid)(     zxWINDOW *win, size_t    i    );
  void       (*addChild)(   zxWINDOW *win, zxWINDOW *base );
  void       (*remChild)(   zxWINDOW *win, zxWINDOW *base );
  zxWINDOW*  (*getChild)(   zxWINDOW *win, size_t    i    );
  zxWINDOW*  (*getNext)( zxWINDOW *win, bool nextKid );
  zxWINDOW*  (*getPrev)( zxWINDOW *win );
  zxWINDOW*  (*opNew)(      zxWINDOW *win );
  zxWINDOW*  (*opDel)(      zxWINDOW* win );
  void       (*setFocus)( zxWINDOW* win );
  zxWINDOW * (*getFocus)( void );
  int        (*freeAll)( int returnCode );
} zxn_win;

static zxn_win zxwin =
{
  {0}, {0}, {0}, {0},
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
  zxWINDOW_allWindows,
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
  zxWINDOW_freeAll
};

ZXC_SHUT

#if ZXCPP
class ZXSYS zxWindow : public zxWINDOW
{
private:
  void _init( zxWINDOW* base, size_t *kids, size_t count )
  {
    zxwin.opNew( this );
    m_win = zxWIN_CPP_NULL;
    zxwin.setBase( this, base );
    zxv_size._init( &m_kids, kids, count );
  }
public:
  zxWindow( void )
    { _init( NULL, NULL, 0 ); }
  zxWindow( size_t* kids, size_t count )
    { _init( NULL, kids, count ); }
  zxWindow( zxWINDOW* base )
    { _init( base, NULL, 0 ); }
  zxWindow( zxWINDOW* base, size_t *kids, size_t count )
    { _init( base, kids, count ); }
  ~zxWindow( void )
    { zxwin.opDel( this ); }
  void      setBase( zxWINDOW* base )
    { zxwin.setBase( this, base ); }
  void      setParent( zxWINDOW* parent )
    { setBase( parent ); }
  zxWindow* getBase( void )
  {
    zxWINDOW* base = zxwin.getWindow( m_base );
    if ( !base || base->m_win < zxWIN_CPP_NULL )
      return NULL;
    return (zxWindow*)base;
  }
  zxWindow* getParent( void )
    { return getBase(); }
  zxWindow* getKid( size_t i )
  {
    zxWINDOW* kid = zxwin.getKid( this, i );
    if ( !kid || kid->m_win < zxWIN_CPP_NULL )
      return NULL;
    return (zxWindow*)win;
  }
  zxWindow* getChild( size_t i )
    { return getKid( i ); }
  static zxWINDOWS* allWindows( void ) { return zxwin.allWindows(); }
  static zxWindow*  getWindow( size_t wid )
  {
    zxWINDOW* win = zxwin.getWindow( wid );
    if ( !win || win->m_win < zxWIN_CPP_NULL )
      return NULL;
    return (zxWindow*)win;
  }
};
#endif

#endif
