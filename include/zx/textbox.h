#include "window.h"
#ifndef zxTEXTBOX_H
#define zxTEXTBOX_H

ZXC_OPEN
typedef struct zxTEXTBOX_struct
{
  zxWINDOW m_win;
  zxTEXT   m_text;
  zxuint   m_pos;
#if ZXMSW
  HFONT    m_font;
#endif
} zxTEXTBOX;

ZXSYS zxTEXTBOX* zxNewTEXTBOX( void );
ZXSYS bool zx_TEXTBOX_DrawText( zxTEXTBOX *tbox, bool setCaret );
ZXSYS ZXEVENT( zxv_zxTEXTBOX_onChar  );
ZXSYS ZXEVENT( zxv_zxTEXTBOX_onKeyD  );
ZXSYS ZXEVENT( zxv_zxTEXTBOX_onKeyU  );
ZXSYS ZXEVENT( zxv_zxTEXTBOX_onFocus );
ZXSYS ZXEVENT( zxv_zxTEXTBOX_onBlur  );

ZXC_SHUT

#endif
