#include <zx/vli.h>
/* operator/= */
ZXCORE_EXP zxVLI* zxc_zxVLI_opDiv( zxVLI *src, zxVLI const *val, zxVLI *remainder )
{
  size_t i = 0, pi = 0, I = 0, end = val->m_bits;
  zxuchr bitl = 1u << (CHAR_BIT - 1), bit = bitl;
  zxVLI quo = *src, dst = zxvli.def, cpy = *src, rem = *src;
  if ( remainder )
  {
    dst = *remainder;
    memset( dst.m_vector.m_data, 0, dst.m_vector.m_size );
  }
  if ( !src )
    return NULL;
  /* division by 0 should skip to result of 0 */
  if ( zxvli.cmpEQ( val, NULL ) )
  {
    if ( remainder )
      *remainder = dst;
    memset( src->m_vector.m_data, 0, src->m_vector.m_size );
    return src;
  }
  dst = *src;
  if ( remainder )
  {
    dst.m_vector.m_data = remainder->m_vector.m_data;
    zxv.grow( &dst.m_vector, src->m_vector.m_size, NULL );
    *remainder = dst;
  }
  else
    dst.m_vector.m_data = (zxuchr*)malloc( src->m_vector.m_size );
  quo.m_vector.m_data = (zxuchr*)malloc( src->m_vector.m_size );
  cpy.m_vector.m_data = (zxuchr*)malloc( src->m_vector.m_size );
  rem.m_vector.m_data = (zxuchr*)malloc( src->m_vector.m_size );
  if ( src->m_bits < end )
    end = src->m_bits;
  for ( I = 0; I < src->m_vector.m_size; ++I )
  {
    quo.m_vector.m_data[ I ] = 0u;
    dst.m_vector.m_data[ I ] = 0u;
  }
  pi = src->m_bits;
  i  = pi - 1;
  I  = 0;
  /* since i is unsigned it can never be < 0 so we instead stop once pi has caught up with i if src hasn't already gone below value */
  for ( ; i != pi && zxvli.cmpME( src, val ); --i, --pi )
  {
    zxvli.opMvl( &quo, 1 );
    zxvli.opMvl( &dst, 1 );
    rem.m_vector.m_data[ I ] |= bit;
    if ( src->m_vector.m_data[ I ] & bit )
      dst.m_vector.m_data[ 0 ] |= 1u;
    if ( zxvli.cmpME( &dst, val ) )
    {
      zxvli.opSub( &dst, val );
      quo.m_vector.m_data[ 0 ] |= 1u;
      memcpy( cpy.m_vector.m_data, dst.m_vector.m_data, src->m_vector.m_size );
      zxvli.opMvl( &cpy, i );
      zxvli.opXor( src, &rem );
      zxvli.opOr(  src, &cpy );
    }
    bit >>= 1;
    if ( !bit )
    {
      --I;
      bit = bitl;
    }
  }
  if ( pi != 0 )
  {
    /* TODO: need way to handle division by number larger than src

      My untested theory is to multuply src by 2 until it is >= val
      counting the number of times a multiplication is carried out,
      then subtract val from src, then append 1 to quo before finaly
      dividing quo by 2 the same number of times as counted during
      multiplication
    */
  }
  memcpy( src->m_vector.m_data, dst.m_vector.m_data, src->m_vector.m_size );
  free( quo.m_vector.m_data );
  /* ensure no there is not a memory leak */
  if ( !remainder )
    free( dst.m_vector.m_data );
  free( cpy.m_vector.m_data );
  free( rem.m_vector.m_data );
  return src;
}
/* operator/ */
ZXCORE_EXP zxVLI* zxc_zxVLI_cpyDiv( zxVLI *dst, zxVLI const *src, zxVLI const *val, zxVLI *remainder )
{
  if ( dst )
  {
    zxvli.cpyEql( dst, src );
    zxvli.opDiv( dst, val, remainder );
  }
  return dst;
}
