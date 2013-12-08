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

#if ZXMSW
/* This speeds things up as well as saves space */
typedef RECT  zxRECT;
#else
typedef zxRECT_struct
{
  zxsl left, top, righ, bottom;
} zxRECT;
#endif

typedef struct zxWINDOW_struct
{
  zxui      m_base, m_wid, m_oid;
  zxvUI     m_kids;
  bool      m_class;
  zxOBJ     m_wObj, m_uObj;
  zxul      m_style, m_stylex;
  bool      m_delKids;
  zxsi      m_x, m_y, m_w, m_h;
  zxTEXT    m_txt;
  zxWIN     m_win;
  /* System Specfic */
  zxWCX    *m_wcx;
  zxCOLOR   m_bgc;
  zxRECT    m_wRect, m_cRect;
  bool      m_mutex;
} zxWINDOW;

ZXSYS zxInstance zxGetPrevI( void );
ZXSYS zxInstance zxGetThisI( void );


ZXNSO( win )
{
  zxWINDOW  def;
  zxRECT    defRECT;
  zxWC      defWC;
  zxWCX     (*defWCX)( size_t type );
  zxsi       (*osOpNew)(  zxWINDOW  *win );
#if ZXMSW
  ATOM      mswATOMX[ zxWIN_COUNT ];
#endif
  void       (*_initWC)(    zxWC     *wc  );
  void       (*_initWCX)(   zxWCX    *wcx );
  zxHwnd     (*getHandle)(  zxui      wid );
  zxWINDOW*  (*getRootWindow)(  void );
  zxHwnd     (*getRootWH)( void );
  zxWINDOW*  (*getWindow)(  zxui      wid );
  bool       (*isKnown)(    zxWINDOW* win );
  zxWINDOW*  (*byHandle)(   zxHwnd    wh );
  void       (*setBase)(    zxWINDOW *win, zxWINDOW *base );
  void       (*setParent)(  zxWINDOW *win, zxWINDOW *base );
  void       (*addKid)(     zxWINDOW *win, zxWINDOW *base );
  void       (*remKid)(     zxWINDOW *win, zxWINDOW *base );
  zxWINDOW*  (*getKid)(     zxWINDOW *win, zxui      i    );
  void       (*addChild)(   zxWINDOW *win, zxWINDOW *base );
  void       (*remChild)(   zxWINDOW *win, zxWINDOW *base );
  zxWINDOW*  (*getChild)(   zxWINDOW *win, zxui      i    );
  zxWINDOW*  (*getNext)( zxWINDOW *win, bool nextKid );
  zxWINDOW*  (*getPrev)( zxWINDOW *win );
  zxWINDOW*  (*opNew)(      zxWINDOW *win );
  zxWINDOW*  (*opDel)(      zxWINDOW* win );
  void       (*setFocus)( zxWINDOW* win );
  zxWINDOW * (*getFocus)( void );
  int        (*freeAll)( int returnCode );
  bool       (*show)(   zxWINDOW *win );
  bool       (*hide)(   zxWINDOW *win );
  bool       (*update)( zxWINDOW *win );
  zxWINDOW*  (*fromPoint)( zxPOINT pt, zxus maxDepth );
} zxn_win;

extern zxn_win const zxwin;

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
  static zxWindow*  getWindow( size_t wid )
  {
    zxWINDOW* win = zxwin.getWindow( wid );
    if ( !win || !win->m_class )
      return NULL;
    return (zxWindow*)win;
  }
};
#endif

#endif
