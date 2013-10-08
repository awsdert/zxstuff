#include <zx/std/vector.h>
void zxv_zxVECTOR__init( zxVECTOR* obj, size_t Tsize, zxuc const *setNew, size_t setCount )
{
  *obj = zxv.def;
  obj->m_Tsize = Tsize;
  zxv.grow( obj, setCount, setNew );
}