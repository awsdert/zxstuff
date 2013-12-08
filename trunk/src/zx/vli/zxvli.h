#pragma once
#ifndef ZX__VLI_H
#define ZX__VLI_H
#include <zx/vli.h>

/* Behaves as constructor would and assumes object has not been used already */
ZXCORE void   zxVLI__init(  zxVLI *src, zxsm value );
ZXCORE void   zxVLI__initU( zxVLI *src, zxum value );
ZXV__INITCPY( zxVLI, ZXCORE, ZXCORE_CALL );
ZXV__KILL(    zxVLI, ZXCORE, ZXCORE_CALL );
/* Sizing */
ZXV_SIZE( zxVLI, ZXCORE, ZXCORE_CALL );
ZXV_MAX_SIZE( zxVLI, ZXCORE, ZXCORE_CALL );
ZXCORE void   ZXCORE_CALL zxVLI_resize(   zxVLI *src, zxui   size );
ZXCORE void   ZXCORE_CALL zxVLI_grow(     zxVLI *src, zxui   size );
ZXCORE void   ZXCORE_CALL zxVLI_shrink(   zxVLI *src, zxui   size );
ZXCORE size_t ZXCORE_CALL zxVLI_bits(     zxVLI const *src );
ZXCORE size_t ZXCORE_CALL zxVLI_max_bits( zxVLI const *src );
ZXCORE void   ZXCORE_CALL zxVLI_resizeb(  zxVLI *src, size_t bits );
ZXCORE void   ZXCORE_CALL zxVLI_growb(    zxVLI *src, size_t bits );
ZXCORE void   ZXCORE_CALL zxVLI_shrinkb(  zxVLI *src, size_t bits );
ZXV_EMPTY(    zxVLI, ZXCORE, ZXCORE_CALL );
ZXV_RESERVE(  zxVLI, ZXCORE, ZXCORE_CALL );
ZXV_SHRINK_TO_FIT( zxVLI,       ZXCORE, ZXCORE_CALL );
ZXV_ERASE(         zxVLI,       ZXCORE, ZXCORE_CALL );
ZXCORE void   ZXCORE_CALL zxVLI_eraseb( zxVLI *src,
  size_t firstBit, size_t lastBit );
ZXV_SWAP(          zxVLI,       ZXCORE, ZXCORE_CALL );
ZXV_CLEAR(         zxVLI,       ZXCORE, ZXCORE_CALL );
ZXV_COPY(          zxVLI, zxuc, ZXCORE, ZXCORE_CALL );
ZXV_REVERSE(       zxVLI,       ZXCORE, ZXCORE_CALL );
ZXV_AT(            zxVLI, zxuc, ZXCORE, ZXCORE_CALL );
/* Returns src */

ZXVLI_OPEQL;

ZXVLI_OPADD;  ZXVLI_OPAND;
ZXVLI_OPDIV;  ZXVLI_OPMUL;
ZXVLI_OPMVL;  ZXVLI_OPMVR;
ZXVLI_OPNOT;  ZXVLI_OPOR;
ZXVLI_OPSUB;  ZXVLI_OPXOR;

ZXVLI_CPYADD; ZXVLI_CPYAND;
ZXVLI_CPYDIV; ZXVLI_CPYMUL;
ZXVLI_CPYMVL; ZXVLI_CPYMVR;
ZXVLI_CPYNOT; ZXVLI_CPYOR;
ZXVLI_CPYSUB; ZXVLI_CPYXOR;

ZXVLI_CMPEQ;  ZXVLI_CMPNE;
ZXVLI_CMPMT;  ZXVLI_CMPME;
ZXVLI_CMPLT;  ZXVLI_CMPLE;

/* Returns the max for the last byte if not zero */
ZXCORE zxuc ZXCORE_CALL zxVLI_isNeg( zxVLI const *src );
ZXV_ISEQUAL( zxVLI, ZXCORE, ZXCORE_CALL );

#endif
