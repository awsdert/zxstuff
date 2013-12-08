#pragma once
#ifndef ZX__WH_H
#define ZX__WH_H
#include <zx/event.h>

ZXV_DEC( zxvWH, zxWH,, ZXSYS_CALL );
zxvWH* ZXSYS_CALL zxvWH_all( void );
zxWH*  ZXSYS_CALL zxvWH_byHwnd( zxHwnd wh );
zxWH*  ZXSYS_CALL zxvWH_byId( zxui wid );

#endif
