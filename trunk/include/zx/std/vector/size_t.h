#pragma once
#include "cpp.h"

#ifndef ZXV_SIZE_H
#define ZXV_SIZE_H

ZXV_DEC( zxvSIZE, size_t );
ZXV_DEC_2ND( zxvSIZE, size_t, ZXCORE );


ZXNSO( v_size )
{
  ZXV_DEC_BODY( zxvSIZE, size_t );
} zxn_v_size;

static zxn_v_size const zxv_size =
{
  ZXV_DEF_BODY( zxvSIZE, {0} )
};

#endif