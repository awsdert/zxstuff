#pragma once
/* Private to source */
#ifndef ZX__TBOX_H
#define ZX__TBOX_H
#include <zx/tbox.h>
#include "../window/zxwin.h"

ZXSYS zxTBOX*  zxTBOX_opNew( zxWINDOW* win    );
ZXSYS void     zxTBOX_opDel( void*     winObj, size_t type );
ZXSYS bool     zxTBOX__drawText( zxTBOX *tbox, bool setCaret );
ZXSYS bool     zxTBOX__setCaret( zxTBOX *tbox );

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
