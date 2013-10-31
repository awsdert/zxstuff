#include <zx/vli.h>
ZXCORE_EXP zxus   zxGetUSht(    zxuc* src, size_t size )
{
  zxus val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxss   zxGetSSht(    zxuc* src, size_t size )
{
  zxss val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxul   zxGetULng(    zxuc* src, size_t size )
{
  zxul val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsl   zxGetSLng(    zxuc* src, size_t size )
{
  zxsl val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxui   zxGetUInt(    zxuc* src, size_t size )
{
  zxui val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsi   zxGetSInt(    zxuc* src, size_t size )
{
  zxsi val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
#ifdef ZXILL
ZXCORE_EXP zxull   zxGetUIll(    zxuc* src, size_t size )
{
  zxull val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsll   zxGetSIll(    zxuc* src, size_t size )
{
  zxsll val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
#endif
ZXCORE_EXP zxum   zxGetUMax(    zxuc* src, size_t size )
{
  zxum val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE_EXP zxsm   zxGetSMax(    zxuc* src, size_t size )
{
  zxsm val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE_EXP size_t   zxGetSize_t(  zxuc* src, size_t size )
{
  size_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
ZXCORE_EXP ssize_t  zxGetSSize_t( zxuc* src, size_t size )
{
  ssize_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
