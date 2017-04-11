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
// sstMath01Pnt1.cpp    30.12.16  Re.    30.12.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "sstMath01Lib.h"

#include "sstMath01LibInt.h"



sstMath01dPnt2Cls::sstMath01dPnt2Cls()
{
  this->x = 0.0;
  this->y = 0.0;
}
sstMath01dPnt3Cls::sstMath01dPnt3Cls()
{
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
}
sstMath01fPnt2Cls::sstMath01fPnt2Cls()
{
  this->x = 0.0;
  this->y = 0.0;
}
sstMath01iPnt2Cls::sstMath01iPnt2Cls()
{
  this->x = 0;
  this->y = 0;
}
sstMath01ulPnt3Cls::sstMath01ulPnt3Cls()
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
}
