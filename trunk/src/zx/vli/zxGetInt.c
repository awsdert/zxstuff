#include <zx/vli.h>
ZXCORE zxus   zxGetUSht(    zxuc* src, size_t size )
{
  zxus val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE zxss   zxGetSSht(    zxuc* src, size_t size )
{
  zxss val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( short ), zxIntEndian() );
  return val;
}
ZXCORE zxul   zxGetULng(    zxuc* src, size_t size )
{
  zxul val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE zxsl   zxGetSLng(    zxuc* src, size_t size )
{
  zxsl val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( long ), zxIntEndian() );
  return val;
}
ZXCORE zxui   zxGetUInt(    zxuc* src, size_t size )
{
  zxui val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
ZXCORE zxsi   zxGetSInt(    zxuc* src, size_t size )
{
  zxsi val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( int ), zxIntEndian() );
  return val;
}
#ifdef ZXILL
ZXCORE zxull   zxGetUIll(    zxuc* src, size_t size )
{
  zxull val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
ZXCORE zxsll   zxGetSIll(    zxuc* src, size_t size )
{
  zxsll val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXILL ), zxIntEndian() );
  return val;
}
#endif
ZXCORE zxum   zxGetUMax(    zxuc* src, size_t size )
{
  zxum val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE zxsm   zxGetSMax(    zxuc* src, size_t size )
{
  zxsm val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( ZXIMAX ), zxIntEndian() );
  return val;
}
ZXCORE size_t   zxGetSize_t(  zxuc* src, size_t size )
{
  size_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
ZXCORE ssize_t  zxGetSSize_t( zxuc* src, size_t size )
{
  ssize_t val = 0;
  zxcopy( src, size, zxENDIAN_BIG, (zxuc*)&val, sizeof( size_t ), zxIntEndian() );
  return val;
}
