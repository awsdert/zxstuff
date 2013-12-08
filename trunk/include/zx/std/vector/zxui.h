#pragma once
#ifndef ZXV_UI_H
#define ZXV_UI_H
#include "cpp.h"

ZXC_OPEN

ZXV_OBJ( zxvUI, zxui );
ZXV_DEC( zxvUI, zxui, ZXCORE, ZXCORE_CALL );


ZXNSO( v_ui )
{
  ZXV_NS_DEC( zxvUI, zxui, ZXCORE_CALL );
} zxn_v_ui;

extern zxn_v_ui const zxv_ui;

ZXC_SHUT

#endif
