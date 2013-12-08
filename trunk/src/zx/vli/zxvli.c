#include "zxvli.h"

zxn_vli const zxvli =
{
  zxVLI__init,    zxVLI__initU, {0},
  zxVLI__initCpy, zxVLI__kill,
  zxVLI_size,     zxVLI_bits,
  zxVLI_max_size, zxVLI_max_bits,
  zxVLI_resize,   zxVLI_resizeb,
  zxVLI_empty,    zxVLI_reserve,
  zxVLI_grow,     zxVLI_growb,
  zxVLI_shrink,   zxVLI_shrinkb,
  zxVLI_shrink_to_fit,
  zxVLI_resize,   zxVLI_resizeb,
  zxVLI_erase,    zxVLI_eraseb,
  zxVLI_swap,     zxVLI_clear,
  zxVLI_reverse,  zxVLI_copy,
  zxVLI_at,       zxVLI_opEql,

  zxVLI_opAdd,    zxVLI_opAnd,
  zxVLI_opDiv,    zxVLI_opMul,
  zxVLI_opMvl,    zxVLI_opMvr,
  zxVLI_opNot,    zxVLI_opOr,
  zxVLI_opSub,    zxVLI_opXor,

  zxVLI_cpyAdd,   zxVLI_cpyAnd,
  zxVLI_cpyDiv,   zxVLI_cpyMul,
  zxVLI_cpyMvl,   zxVLI_cpyMvr,
  zxVLI_cpyNot,   zxVLI_cpyOr,
  zxVLI_cpySub,   zxVLI_cpyXor,

  zxVLI_isNeg,    zxVLI_isEqual,
  zxVLI_cmpEQ,    zxVLI_cmpNE,
  zxVLI_cmpMT,    zxVLI_cmpME,
  zxVLI_cmpLT,    zxVLI_cmpLE
};
