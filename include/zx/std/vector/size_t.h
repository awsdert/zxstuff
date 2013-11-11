#include "cpp.h"

#pragma once
#ifndef ZXV_SIZE_H
#define ZXV_SIZE_H

ZXV_OBJ( zxvSIZE, size_t );
ZXV_DEC( zxvSIZE, size_t, ZXCORE );


ZXNSO( v_size )
{
  ZXV_NS_DEC( zxvSIZE, size_t );
} zxn_v_size;

static zxn_v_size const zxv_size =
{
  ZXV_NS_DEF( zxvSIZE, {0} )
};

#endif
