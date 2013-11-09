/* USER: AWSDERT; DATE: 05/11/2013; TIME: 15:17 */
#include <zx/std/vector.h>
ZXV_POP( zxVECTOR, void*, ZXCORE_EXP )
{
  size_t i, j, stop = zxv.size( src ), size;
  zxuc *SRC;
  if ( zxv.empty( src ) ) return; 
  SRC = (zxuc*)src->m_data;
  size = src->m_Tsize;
  if ( first >= stop )
    first = stop - 1;
  if ( last < first )
    last = first;
  else if ( last >= stop )
    last = stop - 1;
   ++last;
  for ( i = first, j = i * size; i < last; )
  {
    if ( mcmp( &SRC[ j ], cmp, size, NULL ) )
    {
      zxv.erase( src, i, i );
      --last;
    }
    else
    {
      ++i;
      j += size;
    }
  }
}