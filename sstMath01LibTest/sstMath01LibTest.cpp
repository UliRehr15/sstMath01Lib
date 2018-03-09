// sstMath01LibTest.cpp    06.01.17  Re.    06.01.17  Re.
//
// Testframe for coordinate transformations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>
#include <sstMath01Lib.h>

#include "sstMath01LibTest.h"

//=============================================================================
int main (int argc, char *argv [])
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------

  sstMath01dPnt3Cls Pnt1;  // World coordinate points like UTM, Gauss Krueger or else
  sstMath01dPnt3Cls Pnt2;
  sstMath01dPnt3Cls Pnt3;

  sstMath01fPnt2Cls fDC_Pnt1;  // 2D Device (screen) coordinates as float
  sstMath01fPnt2Cls fDC_Pnt2;

  sstMath01ulPnt3Cls ulMC_Pnt1;  // model (database) coordinates (unsigned long)
  sstMath01ulPnt3Cls ulMC_Pnt2;

  unsigned long ulDB_Max = 1000000;  // maximum of unsigned long coordinates
  // double dDC_Max = 1000.0;           // Maximum of device coodinates
  double dDC_Max = 400.0;           // Maximum of device coodinates

  sstMath01CoorTrnCls oCoorTrn;  // transformation manager

  float fLim = 0.001;

  sstMath01Mbr2Cls sWC_MiMa;  // Boundings for world coordinates
  sWC_MiMa.Koor2(0,32538589.0,5801400.0);
  sWC_MiMa.Koor2(0,32541354.0,5804394.0);

  Pnt1.x =  32538589.0;  // test point 1
  Pnt1.y =   5801400.0;
  Pnt2.x =  32541354.0;  // test point 2
  Pnt2.y =   5804394.0;


  // calculate Transformations
  iStat = oCoorTrn.Calc_All ( 1, sWC_MiMa, ulDB_Max, dDC_Max);

  // calculate device points
  iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt1, &fDC_Pnt1);
  iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt2, &fDC_Pnt2);

  assert(fDC_Pnt1.x >= (0.0 - fLim) && fDC_Pnt1.x <= (0.0 + fLim));
  assert(fDC_Pnt1.y >= (0.0 - fLim) && fDC_Pnt1.y <= (0.0 + fLim));
  // assert(fDC_Pnt2.x >= (dDC_Max - fLim) && fDC_Pnt2.x <= (dDC_Max + fLim));
  assert(fDC_Pnt2.y >= (dDC_Max - fLim) && fDC_Pnt2.y <= (dDC_Max + fLim));

  // calculate model points
  iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt1, &ulMC_Pnt1);
  iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt2, &ulMC_Pnt2);

  assert(ulMC_Pnt1.x == 0);
  assert(ulMC_Pnt1.y == 0);
  // assert(ulMC_Pnt2.x == 1000000);
  assert(ulMC_Pnt2.y == 1000000);

  // Recalculate world coodinates
  iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt1, &Pnt3);
  assert(Pnt3.x >= (Pnt1.x - fLim) && Pnt3.x <= (Pnt1.x + fLim));
  assert(Pnt3.y >= (Pnt1.y - fLim) && Pnt3.y <= (Pnt1.y + fLim));

  iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt2, &Pnt3);
  assert(Pnt3.x >= (Pnt2.x - fLim) && Pnt3.x <= (Pnt2.x + fLim));
  assert(Pnt3.y >= (Pnt2.y - fLim) && Pnt3.y <= (Pnt2.y + fLim));

  iStat = Test_Mbr ( 0);
  assert(iStat==0);

  // Fatal Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert(0);
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int Test_Mbr (int iKey)
//-----------------------------------------------------------------------------
{
  if ( iKey != 0) return -1;
  //-----------------------------------------------------------------------------
  int iRet  = 0;
  int iStat = 0;

  sstMath01Mbr2Cls oClippWin;
  sstMath01Mbr2Cls oTestMiMa;

  oClippWin.Koor2(0,2.0,2.0);
  oClippWin.Koor2(0,8.0,8.0);

  oTestMiMa.Koor2(0,3.0,3.0);
  oTestMiMa.Koor2(0,6.0,6.0);

  // MBR sTestMiMa is fully inside of sClippWin MBR
  iStat = oTestMiMa.Box2(0, &oClippWin);
  assert(iStat==1);

  // Get MBR as csv string (XI;YI;XA;YA)
  std::string oMimaStr = oTestMiMa.toString();
  assert(oMimaStr == "3.00;3.00;6.00;6.00");

  sstMath01dPnt3Cls Pnt1;
  sstMath01dPnt3Cls Pnt2;

  double Dx = 0.0;
  double Dy = 0.0;

  double MinX = 0.0;
  double MinY = 0.0;

  iStat = 0;

  Pnt1.x =  5555555.5555;
  Pnt1.y =  4444444.4444;
  Pnt2.x =  5565555.3333;
  Pnt2.y =  4454444.2222;

  Pnt1.z =  0.0;
  Pnt2.z =  0.0;

  sstMath01Mbr2Cls sWC_MiMa;  // Boundings for word coordinates

  // Min-Max initialisieren.
  iStat = sWC_MiMa.Ini2 ( 0);

  // Min-Max-Bereich mit D2-Punkt abgleichen.
  iStat = sWC_MiMa.Koor2 ( 0, Pnt1.x, Pnt1.y);
  iStat = sWC_MiMa.Koor2 ( 0, Pnt2.x, Pnt2.y);

  // Min-Max abfragen.
  iStat = sWC_MiMa.Les2 ( 6, &Dx);
  iStat = sWC_MiMa.Les2 ( 7, &Dy);

  iStat = sWC_MiMa.Les2 ( 0, &MinX);
  iStat = sWC_MiMa.Les2 ( 1, &MinY);

  return iRet;
}
//=============================================================================
