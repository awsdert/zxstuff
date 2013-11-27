#pragma once
#ifndef ZX__OBJ_H
#define ZX__OBJ_H
#include <zx/obj.h>

ZXV_DEC( zxvOBJ, zxOBJ,, ZXCORE_CALL );
zxvOBJ* ZXCORE_CALL zxvOBJ_all( void );
void    ZXCORE_CALL zxvOBJ_setFocus( zxOBJ obj );
bool    ZXCORE_CALL zxvOBJ_hasFocus( zxOBJ obj );
zxOBJ   ZXCORE_CALL zxvOBJ_getFocus( void );
int     ZXCORE_CALL zxvOBJ_freeAll( int returnCode );
size_t  ZXCORE_CALL zxvOBJ_getNewId( void );

#endif
