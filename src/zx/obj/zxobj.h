#pragma once
#ifndef ZX__OBJ_H
#define ZX__OBJ_H
#include <zx/obj.h>

ZXV_DEC( zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL );
ZXCORE zxvOBJ* ZXCORE_CALL zxvOBJ_all( void );
ZXCORE void    ZXCORE_CALL zxvOBJ_setFocus( zxOBJ obj );
ZXCORE bool    ZXCORE_CALL zxvOBJ_hasFocus( zxOBJ obj );
ZXCORE zxOBJ   ZXCORE_CALL zxvOBJ_getFocus( void );
ZXCORE int     ZXCORE_CALL zxvOBJ_freeAll( int returnCode );

#endif
