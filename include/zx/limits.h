#pragma once
#include "limits/all.h"
#include "limits/char.h"
#include "limits/short.h"
#include "limits/long.h"
#include "limits/ill.h"
#include "limits/int.h"
#include "limits/imax.h"
#include "limits/size_t.h"
#include "limits/bool.h"
#include "std/arch.h"

#ifndef ZXLIMITS_H
#define ZXLIMITS_H

static          int     const zxCHAR_BITS  = ZXCHAR_BITS;
static unsigned char    const zxCHAR_LAST  = ZXLL( 1u ) << ( ZXCHAR_BITS - 1 );
static          int     const zxSHORT_BITS = ZXSHRT_BITS;
static unsigned short   const zxSHORT_LAST = ZXLL( 1u ) << ( ZXSHRT_BITS - 1 );
static          int     const zxLONG_BITS  = ZXLONG_BITS;
static unsigned long    const zxLONG_LAST  = ZXLL( 1u ) << ( ZXLONG_BITS - 1 );
static          int     const zxINT_BITS   = ZXINT_BITS;
static unsigned int     const zxINT_LAST   = ZXLL( 1u ) << ( ZXINT_BITS  - 1 );
static          int     const zxIMAX_BITS  = ZXIMAX_BITS;
static unsigned ZXIMAX  const zxIMAX_LAST  = ZXLL( 1u ) << ( ZXIMAX_BITS - 1 );
static          int     const zxSIZE_BITS  = ZXSIZE_BITS;
static          size_t  const zxSIZE_LAST  = ZXLL( 1u ) << ( ZXSIZE_BITS - 1 );
#ifdef ZXUILL_MAX
static          int     const zxILL_BITS   = ZXILL_BITS;
static unsigned ZXIMAX  const zxILL_LAST   = ZXLL( 1u ) << ( ZXILL_BITS  - 1 );
#endif

#endif
