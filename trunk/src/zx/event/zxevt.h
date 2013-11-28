#pragma once
#ifndef ZX__EVT_H
#define ZX__EVT_H
#include <zx/event.h>

ZXC_OPEN

ZXV_DEC( zxvEVT, zxEVT, ZXSYS, ZXSYS_CALL );
ZXEVENT( zxEVENT_onCurLD   );
ZXEVENT( zxEVENT_onFocus   );
ZXEVENT( zxEVENT_onEvent   );

ZXC_SHUT

#endif
