/* Tester.cpp : Defines the entry point for the application. */

#include "zxGui.h"

#if ZXMSW
int WINAPI WinMain(
  HINSTANCE thisI,
  HINSTANCE prevI,
  LPSTR     cmdLine,
  int       showCmd )
{
  return zxapp._main( thisI, prevI, cmdLine, showCmd );
}

#if 0
LRESULT CALLBACK WinProc( zxHwnd wh, UINT msg, WPARAM wp, LPARAM lp )
{
  return zxevt.onEvent( wh, msg, wp, lp );
}
#endif
#else
int main( void ) { return 0; }
#endif
