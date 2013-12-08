#pragma once
/* Private to source */
#ifndef ZX__TBOX_H
#define ZX__TBOX_H
#include <zx/tbox.h>
#include "../window/zxwin.h"

zxTBOX*  zxTBOX_opNew( zxWINDOW* win    );
void     zxTBOX_opDel( void*     winObj, size_t type );
bool     zxTBOX__setText(  zxTBOX *tbox );
bool     zxTBOX__drawText( zxTBOX *tbox, bool setCaret );
bool     zxTBOX__setCaret( zxTBOX *tbox );

ZXEVENT( zxTBOX_onEvent );
ZXEVENT( zxTBOX_onInit  );
ZXEVENT( zxTBOX_onKill  );
ZXEVENT( zxTBOX_onCmd   );
ZXEVENT( zxTBOX_onChar  );
ZXEVENT( zxTBOX_onKeyD  );
ZXEVENT( zxTBOX_onKeyU  );
ZXEVENT( zxTBOX_onFocus );
ZXEVENT( zxTBOX_onBlur  );

#endif
