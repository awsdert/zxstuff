#pragma once
#ifndef ZX_OBJ_H
#define ZX_OBJ_H
#include "vli.h"

ZXC_OPEN

enum
{
  zxOBJ_NULL = 0,
  zxOBJ_VECTOR,
  zxOBJ_VCHAR,
  zxOBJ_VWIDE,
  zxOBJ_VLI,
  zxOBJ_VOBJ,
  zxOBJ_FILE,
  zxOBJ_COUNT
};

typedef void (*opDelVoid)( void* obj, size_t type );

typedef ZXSOBJ( zxOBJ )
{
  size_t id, type, subType;
  void  *obj;
  opDelVoid del;
} zxOBJ;

ZXV_OBJ( zxvOBJ, zxOBJ );

ZXNSO( obj )
{
  zxOBJ defObj;
  ZXV_NS_DEC( zxvOBJ, zxOBJ, ZXCORE_CALL );
  zxvOBJ* (ZXCORE_CALL *all)( void );
  void    (ZXCORE_CALL *setFocus)( zxOBJ obj );
  bool    (ZXCORE_CALL *hasFocus)( zxOBJ obj );
  zxOBJ   (ZXCORE_CALL *getFocus)( void );
  int     (ZXCORE_CALL *freeAll)( int returnCode );
} zxn_obj;

extern zxn_obj const zxobj;

ZXC_SHUT

#endif
