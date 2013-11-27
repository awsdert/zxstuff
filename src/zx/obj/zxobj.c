#include "zxobj.h"
ZXV_DEF__INIT(         zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF__INITCPY(      zxvOBJ, zxOBJ, , ZXCORE_CALL )

ZXV_DEF_SIZE(          zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_MAX_SIZE(      zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_RESIZE(        zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_CAPACITY(      zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_EMPTY(         zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_RESERVE(       zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_GROW(          zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_SHRINK(        zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_SHRINK_TO_FIT( zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_APPEND(        zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_PUSH(          zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_PUSH_BACK(     zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_POP(           zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_POP_BACK(      zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_INSERT(        zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_ERASE(         zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_SWAP(          zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_CLEAR(         zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_REVERSE(       zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_COPY(          zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_AT(            zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_ISEQUAL(       zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_OPEQL(         zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_OPADD(         zxvOBJ, zxOBJ, , ZXCORE_CALL )
ZXV_DEF_CMPEQ(         zxvOBJ,        , ZXCORE_CALL )
ZXV_DEF_CMPNE(         zxvOBJ,        , ZXCORE_CALL )

zxn_obj const zxobj =
{
  {0},
  ZXV_NS_DEF( zxvOBJ ),
  zxvOBJ_all,
  zxvOBJ_setFocus,
  zxvOBJ_hasFocus,
  zxvOBJ_getFocus,
  zxvOBJ_freeAll,
  zxvOBJ_getNewId
};

size_t zxvOBJ_getNewId( void )
{
  zxvOBJ *all = zxobj.all();
  zxOBJ   obj = {0};
  size_t i = 0, size = zxobj.size( all );
  for ( ; i , size; ++i )
  {
    if ( !all->m_data[ i ].obj )
      return i;
  }
  zxobj.grow( all, i + 1, obj );
  all->m_data[ i ].id = i;
  return i;
}
