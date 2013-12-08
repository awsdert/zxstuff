/* USER: Lee DATE: 04/11/2013; TIME: 06:30 */
#include <zx/std/lib.h>
ZXCORE bool mcmp(
    void const *src,
    void const *cmp,
    size_t size,
    size_t *I )
{
    zxuc const
        *SRC = (zxuc const*)src,
        *CMP = (zxuc const*)cmp;
    size_t i = size - 1;
    if ( src == cmp )
    {
        if ( I )
            *I = i;
        return true;
    }
    if ( !cmp )
    {
      do
      {
        if ( SRC[ i ] != 0u )
          break;
        --i; --size;
      }
      while ( i < size );
    }
    else
    {
       do
       {
        if ( SRC[ i ] == CMP[ i ] )
          break;
        --i; --size;
       }
       while ( i < size );
    }
    if ( I )
        *I = i;
    if ( size )
        return false;
    return true;
}
