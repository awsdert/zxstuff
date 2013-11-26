#include "zxobj.h"
ZXV_DEF__INIT(         zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF__INITCPY(      zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )

ZXV_DEF_SIZE(          zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_MAX_SIZE(      zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_RESIZE(        zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_CAPACITY(      zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_EMPTY(         zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_RESERVE(       zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_GROW(          zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_SHRINK(        zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_SHRINK_TO_FIT( zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_APPEND(        zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_PUSH(          zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_PUSH_BACK(     zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_POP(           zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_POP_BACK(      zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_INSERT(        zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_ERASE(         zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_SWAP(          zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_CLEAR(         zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_REVERSE(       zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_COPY(          zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_AT(            zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_ISEQUAL(       zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_OPEQL(         zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_OPADD(         zxvOBJ, zxOBJ, ZXCORE, ZXCORE_CALL )
ZXV_DEF_CMPEQ(         zxvOBJ,        ZXCORE, ZXCORE_CALL )
ZXV_DEF_CMPNE(         zxvOBJ,        ZXCORE, ZXCORE_CALL )

zxn_obj const zxobj =
{
  {0},
  ZXV_NS_DEF( zxvOBJ ),
  zxvOBJ_all,
  zxvOBJ_setFocus,
  zxvOBJ_hasFocus,
  zxvOBJ_getFocus,
  zxvOBJ_freeAll
};
