#pragma once
#include "vli.h"

#ifndef ZX_OBJ_H
#define ZX_OBJ_H

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
ZXV_DEC( zxOBJS, zxOBJ, ZXCORE );
ZXCORE void    zxOBJS_setFocus( zxOBJ );
ZXCORE zxOBJ   zxOBJS_getFocus( void );
ZXCORE zxOBJS* zxOBJS_allObjects( void );
ZXCORE int     zxOBJS_freeAll( int returnCode );

ZXNSO( obj )
{
  zxOBJ defObj;
  ZXV_NS_DEC( zxOBJS, zxOBJ );
  zxOBJS* (*allObjects)( void );
  void    (*setFocus)( zxOBJ obj );
  zxOBJ   (*getFocus)( void );
  int     (*freeAll)( int returnCode );
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