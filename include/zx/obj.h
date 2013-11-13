#pragma once
#ifndef ZX_OBJ_H
#define ZX_OBJ_H
#include "vli.h"

ZXC_OPEN

enum
{
  zxOBJ_NULL = 0,
  zxOBJ_VECTOR,
  zxOBJ_CHAR,
  zxOBJ_WIDE,
  zxOBJ_VLI,
  zxOBJ_FILE,
  zxOBJ_COUNT
};

typedef void (*opDelVoid)( void* obj, size_t type );

typedef ZXSOBJ( zxOBJ )
{
  size_t gid, type;
  void  *obj;
  opDelVoid del;
} zxOBJ;

ZXV_OBJ( zxOBJS, zxOBJ );
ZXV_DEC( zxOBJS, zxOBJ, ZXCORE, ZXCORE_CALL );
ZXCORE zxOBJS* ZXCORE_CALL zxOBJS_allObjects( void );
ZXCORE void    ZXCORE_CALL zxOBJS_setFocus( zxOBJ );
ZXCORE zxOBJ   ZXCORE_CALL zxOBJS_getFocus( void );
ZXCORE int     ZXCORE_CALL zxOBJS_freeAll( int returnCode );

ZXNSO( obj )
{
  zxOBJ defObj;
  ZXV_NS_DEC( zxOBJS, zxOBJ, ZXCORE_CALL );
  zxOBJS* (ZXCORE_CALL *allObjects)( void );
  void    (ZXCORE_CALL *setFocus)( zxOBJ obj );
  zxOBJ   (ZXCORE_CALL *getFocus)( void );
  int     (ZXCORE_CALL *freeAll)( int returnCode );
} zxn_obj;

static zxn_obj zxobj =
{
  {0},
  ZXV_NS_DEF( zxOBJS, {0} ),
  zxOBJS_allObjects,
  zxOBJS_setFocus,
  zxOBJS_getFocus,
  zxOBJS_freeAll
};

ZXC_SHUT

#endif
