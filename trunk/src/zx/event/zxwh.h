#pragma once
#ifndef ZX__WH_H
#define ZX__WH_H
#include <zx/event.h>

ZXV_DEC( zxvWH, zxWH, ZXSYS, ZXSYS_CALL );
ZXSYS zxvWH* ZXSYS_CALL zxvWH_all( void );
ZXSYS zxWH*  ZXSYS_CALL zxvWH_byHwnd( zxHwnd wh );
ZXSYS zxWH*  ZXSYS_CALL zxvWH_byId( size_t wid );

#endif
