/**********************************************************************
 *
 * sstMath01Lib - cpp math and geometry function library for sst (Version 1)
 * Hosted on github
 *
 * Copyright (C) 2016 Uli Rehr
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/
// sstMath01Lib.cpp    30.12.16  Re.    30.12.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>

#include "sstMath01Lib.h"

#include "sstMath01LibInt.h"

//=============================================================================
double sstMath01Mbr2Cls::getXI() const
{
    return XI;
}
//=============================================================================
double sstMath01Mbr2Cls::getYI() const
{
    return YI;
}
//=============================================================================
double sstMath01Mbr2Cls::getXA() const
{
    return XA;
}
//=============================================================================
double sstMath01Mbr2Cls::getYA() const
{
    return YA;
}
//=============================================================================
std::string sstMath01Mbr2Cls::toString() const
{
  sstStr01Cls oStrCnvt;
  std::string oMimaStr;
  // Set number of decimal values for formatting double/float
  oStrCnvt.setUiDec( 2);
  // Set decimal type decimal point
  oStrCnvt.setDecType ( 1);
  oStrCnvt.Csv_Dbl_2String(0,this->getXI(),&oMimaStr);
  oStrCnvt.Csv_Dbl_2String(0,this->getYI(),&oMimaStr);
  oStrCnvt.Csv_Dbl_2String(0,this->getXA(),&oMimaStr);
  oStrCnvt.Csv_Dbl_2String(0,this->getYA(),&oMimaStr);
  return oMimaStr;
}
//=============================================================================
