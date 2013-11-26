#pragma once
#ifndef ZX__EVT_H
#define ZX__EVT_H
#include <zx/event.h>

ZXC_OPEN

ZXV_DEC( zxvEVT, zxEVT, ZXSYS, ZXSYS_CALL );
ZXSYS ZXEVENT( zxEVENT_onCurLD   );
ZXSYS ZXEVENT( zxEVENT_onFocus   );

ZXC_SHUT

#endif
