#pragma once
#ifndef ZXV_SIZE_H
#define ZXV_SIZE_H
#include "cpp.h"

ZXC_OPEN
ZXV_OBJ( zxvSIZE, size_t );
ZXV_DEC( zxvSIZE, size_t, ZXCORE, ZXCORE_CALL );


ZXNSO( v_size )
{
  ZXV_NS_DEC( zxvSIZE, size_t, ZXCORE_CALL );
} zxn_v_size;

static zxn_v_size const zxv_size =
{
  ZXV_NS_DEF( zxvSIZE, {0} )
};

ZXC_SHUT

#endif
