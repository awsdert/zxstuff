#pragma once
#ifndef zxPROC_H
#include "std/text.h"
#if ZXMSW
#include <tlhelp32.h>
#endif

ZXC_OPEN

#if ZXMSW
typedef DWORD  zxPID;
typedef HANDLE zxPH;
typedef PROCESSENTRY32 zxPE32;
#define ZXCB CALLBACK
#else
typedef ZXVP   HWND;
typedef zxul   LPARAM;
typedef zxul   DWORD;
typedef zxul   zxPID;
typedef ZXVP   zxPH;
typedef struct { int ignored; } zxPE32;
#define ZXCB
#endif

typedef struct zxPROC_struct
{
  zxPE32 m_pe32;
  zxPH   m_ph;
  zxTEXT m_name;
} zxPROC;
typedef struct zx___PID_struct { zxPID pid; zxui err; zxui done; } zx___PID;
ZXSYS BOOL ZXCB zx___enumWindowsIsVisible( HWND hw, LPARAM lp );
ZXSYS bool zxo_zxPROC__init(     zxPROC *proc, zxTEXT const *name );
ZXSYS void zxo_zxPROC__kill(     zxPROC *proc );
ZXSYS zxui zxo_zxPROC_enumAll(   zxPROC **plist,
                                 bool   onlyVisible );
ZXSYS zxui zxo_zxPROC_getPE32_c( zxPE32* pe32, zxCHAR const *name );
ZXSYS zxui zxo_zxPROC_getPE32_w( zxPE32* pe32, zxWIDE const *name );
ZXSYS bool zxo_zxPROC_getPE32Id( zxPE32* pe32, zxPID pid );
ZXSYS zxui zxo_zxPROC_newPH_c( zxPH *ph,
                               zxul access,
                               BOOL inherit,
                               zxCHAR const *name );
ZXSYS zxui zxo_zxPROC_newPH_w( zxPH *ph,
                               zxul access,
                               BOOL inherit,
                               zxWIDE const *name );
ZXSYS zxui zxo_zxPROC_newPHId( zxPH *ph,
                               zxul access,
                               BOOL inherit,
                               zxPID pid );
ZXSYS bool zxo_zxPROC_isVisible( zxPID const pid, zxui *errorCode );

typedef struct zxn_zxPROC_struct
{
  zxPROC const def;
  bool (*_init)(     zxPROC *proc, zxTEXT const *text );
  void (*_kill)(     zxPROC *proc );
  zxui (*enumAll)(   zxPROC **plist, bool onlyVisible );
  zxui (*getPE32_c)( zxPE32* pe32, zxCHAR const *name );
  zxui (*getPE32_w)( zxPE32* pe32, zxWIDE const *name );
  bool (*getPE32Id)( zxPE32* pe32, zxPID pid );
  zxui (*newPH_c)(   zxPH* ph, DWORD access, BOOL inherit, zxCHAR const *name );
  zxui (*newPH_w)(   zxPH* ph, DWORD access, BOOL inherit, zxWIDE const *name );
  zxui (*newPHId)(   zxPH* ph, DWORD access, BOOL inherit, zxPID pid );
  bool (*isVisible)( zxPID const pid, zxui *errorCode );
} zxn_zxPROC;

static zxn_zxPROC zxproc = {
  {0},
  zxo_zxPROC__init,
  zxo_zxPROC__kill,
  zxo_zxPROC_enumAll,
  zxo_zxPROC_getPE32_c,
  zxo_zxPROC_getPE32_w,
  zxo_zxPROC_getPE32Id,
  zxo_zxPROC_newPH_c,
  zxo_zxPROC_newPH_w,
  zxo_zxPROC_newPHId,
  zxo_zxPROC_isVisible
};

ZXC_SHUT

#if ZXCPP

class zxProc : public zxPROC
{
public:
  zxProc( void )
    { zxproc._init( this, NULL ); }
  zxProc( zxText txt )
    { zxproc._init( this, &txt ); }
  ~zxProc( void )
    { zxproc._kill( this ); }
  zxui getPE32( zxWide name = "" )
    { return zxproc.getPE32_w( &m_pe32, &name ); }
  zxui getPE32( zxPE32 *pe32, zxWide name = "" )
    { return zxproc.getPE32_w( pe32, &name ); }
  zxui newPH( zxPH *ph, DWORD access, BOOL inherit, zxWide name )
    { return zxproc.newPH_w( ph, access, inherit, &name ); }
  zxui newPH( zxPH *ph, DWORD access, BOOL inherit, zxPID pid )
    { return zxproc.newPHId( ph, access, inherit, pid ); }
  bool isVisible( zxui *errorCode = NULL )
    { return zxproc.isVisible( m_pe32.th32ProcessID, errorCode ); }
};

#endif

#define zxPROC_H
#endif
