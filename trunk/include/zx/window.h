#include "std/text.h"
#include "app.h"
#include "window/msw.h"

#ifndef ZX_WINDOW_H
#define ZX_WINDOW_H

ZXC_OPEN

ZXV_DEC_1ST( zxWINDOW )
{
  struct zxv_zxWINDOW_struct
    *m_base;
  size_t   m_wid;
  zxWIN    m_win;
  zxVECTOR m_kids;
  zxul     m_style, m_stylex;
  bool     m_delKids;
  zxsi     m_x, m_y, m_w, m_h;
  zxTEXT   m_title;
  /* System Specfic */
  zxWC     *m_wc;
  zxWCX    *m_wcx;
  zxHwnd   m_wh;
  zxEVENTS m_events;
  zxEvtPtr m_defEvts[ zxEVT_COUNT ];
} zxWINDOW;

ZXV_DEC_2ND( zxWINDOW, zxWINDOW*, ZXSYS );

ZXSYS zxInstance
  zxGetPrevI( void );
ZXSYS zxInstance
  zxGetThisI( void );
ZXSYS void
  zxv_zxWINDOW__initWC(
    zxWC     *wc  );
ZXSYS void
  zxv_zxWINDOW__initWCX(
    zxWCX    *wcx );
ZXSYS zxHwnd
  zxv_zxWINDOW_getHandle(
    size_t   wid );
ZXSYS zxWINDOW*
  zxv_zxWINDOW_getWindow(
    size_t   wid );
ZXSYS zxVECTOR*
  zxv_zxWINDOW_allWindows(
    void );
ZXSYS zxWINDOW*
  zxv_zxWINDOW_byHandle(
    zxHwnd wh );
ZXSYS zxuc
  zxv_zxWINDOW_setCaret(
    zxWINDOW *win,
    int      line,
    int      pos );
#if ZXMSW
ZXSYS zxui
  zxv_zxWINDOW_mswSetText(
    zxWINDOW *win,
    zxTEXT   *txt,
    int      line,
    int      pos,
    HBRUSH   bg );
#endif

#define ZXNEW_zxWINDOW( PTR ) ZXNEW( PTR, zxWINDOW, zxwin.def )

ZXSYS zxsi zx_mswNewWindow( zxWINDOW *kid );

ZXSYS zxWINDOW*  zxv_zxWINDOW_opNew( void );
ZXSYS zxWINDOW*  zxv_zxWINDOW_opDel( zxWINDOW *win );
ZXSYS void       zxv_zxWINDOW_setBase( zxWINDOW *win, zxWINDOW *base );
/**
  @param returnCode The value you want returned
**/
ZXSYS int  zxFreeWindows( int returnCode );

ZXSYS void zx_FreeWC( void );

typedef struct zxn_win_struct
{
  void      (*_initWC)(  zxWC  *wc  );
  void      (*_initWCX)( zxWCX *wcx );
  ZXV_DEC_BODY( zxWINDOW, zxWINDOW* );
  zxEvtPtr  defEvents[ zxEVT_COUNT ];
  zxWC      WC[  zxWIN_COUNT ];
  zxWCX     WCX[ zxWIN_COUNT ];
#if ZXMSW
  ATOM      mswATOM[  zxWIN_COUNT ];
  ATOM      mswATOMX[ zxWIN_COUNT ];
#endif
  zxHwnd    (*getHandle)(
    size_t    wid );
  zxWINDOW* (*getWindow)(
    size_t    wid );
  zxVECTOR* (*allWindows)( void );
  zxWINDOW* (*byHandle)(
    zxHwnd    wh );
  void      (*setBase)(
    zxWINDOW *win,
    zxWINDOW *base );
  zxWINDOW* (*opNew)( void );
  zxWINDOW* (*opDel)(
    zxWINDOW* win );
} zxn_win;

static zxn_win zxwin =
{
  zxv_zxWINDOW__initWC,
  zxv_zxWINDOW__initWCX,
  {0},
  ZXV_DEF_BODY( zxWINDOW ),
  {0}, {0}, {0},
#if ZXMSW
  {0}, {0},
#endif
  zxv_zxWINDOW_getHandle,
  zxv_zxWINDOW_getWindow,
  zxv_zxWINDOW_allWindows,
  zxv_zxWINDOW_byHandle,
  zxv_zxWINDOW_setBase,
  zxv_zxWINDOW_opNew,
  zxv_zxWINDOW_opDel
};

ZXC_SHUT

#if ZXCPP
class ZXSYS zxWindow : public zxWINDOW
{
public:
  zxWindow( void )
  {
    zxv_zxWINDOW__init( this, NULL, 0 );
  }
  zxWindow( zxWINDOW** kids, size_t count )
  {
    zxv_zxWINDOW__init( this, kids, count );
  }
  ~zxWindow( void )
  {
    zxv_zxWINDOW__kill( this );
  }
};
#endif

#endif
