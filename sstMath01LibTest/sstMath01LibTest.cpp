// sstMath01LibTest.cpp    06.01.17  Re.    06.01.17  Re.
//
// Testframe for coordinate transformations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


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

  sstMath01fPnt2Cls fDC_Pnt1;  // Device (screen) coordinates as float
  sstMath01fPnt2Cls fDC_Pnt2;

  sstMath01ulPnt3Cls ulMC_Pnt1;  // model (database) coordinates (unsigned long)
  sstMath01ulPnt3Cls ulMC_Pnt2;

  unsigned long ulDB_Max = 1000000;  // maximum of unsigned long coordinates
  double dDC_Max = 1000.0;           // Maximum of device coodinates

  sstMath01CoorTrnCls oCoorTrn;  // transformation manager

  float fLim = 0.001;

  sstMath01Mbr2Cls sWC_MiMa;  // Boundings for world coordinates
  sWC_MiMa.XI =  5555555.5555;  // lower left
  sWC_MiMa.YI =  4444444.4444;
  sWC_MiMa.XA =  5565555.3333;  // upper right
  sWC_MiMa.YA =  4454444.2222;

  Pnt1.x =  5555555.5555;  // test point 1
  Pnt1.y =  4444444.4444;
  Pnt2.x =  5565555.3333;  // test point 2
  Pnt2.y =  4454444.2222;


  // calculate Transformations
  iStat = oCoorTrn.Calc_All ( 1, sWC_MiMa, ulDB_Max, dDC_Max);

  // calculate device points
  iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt1, &fDC_Pnt1);
  iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt2, &fDC_Pnt2);

  assert(fDC_Pnt1.x >= (0.0 - fLim) && fDC_Pnt1.x <= (0.0 + fLim));
  assert(fDC_Pnt1.y >= (0.0 - fLim) && fDC_Pnt1.y <= (0.0 + fLim));
  assert(fDC_Pnt2.x >= (1000.0 - fLim) && fDC_Pnt2.x <= (1000.0 + fLim));
  assert(fDC_Pnt2.y >= (1000.0 - fLim) && fDC_Pnt2.y <= (1000.0 + fLim));

  // calculate model points
  iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt1, &ulMC_Pnt1);
  iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt2, &ulMC_Pnt2);

  assert(ulMC_Pnt1.x == 0);
  assert(ulMC_Pnt1.y == 0);
  assert(ulMC_Pnt2.x == 1000000);
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

  sstMath01Mbr2Cls sClippWin;
  sstMath01Mbr2Cls sTestMiMa;

  sClippWin.XI = 2.0;
  sClippWin.YI = 2.0;
  sClippWin.XA = 8.0;
  sClippWin.YA = 8.0;

  sTestMiMa.XI = 3.0;
  sTestMiMa.YI = 3.0;
  sTestMiMa.XA = 6.0;
  sTestMiMa.YA = 6.0;

  // Box sTestMiMa is fully inside of sClippWin Box
  iStat = sTestMiMa.Mia_2Box_c(0, &sClippWin);
  assert(iStat==1);

  sstMath01dPnt3Cls Pnt1;
  sstMath01dPnt3Cls Pnt2;
  sstMath01dPnt3Cls Pnt3;

  double Dx = 0.0;
  double Dy = 0.0;

  double MinX = 0.0;
  double MinY = 0.0;

  iStat = 0;

  Pnt1.x =  5555555.5555;
  Pnt1.y =  4444444.4444;
  Pnt2.x =  5565555.3333;
  Pnt2.y =  4454444.2222;
  //  Pnt1.x =  10.0;
  //  Pnt1.y =  10.0;
  //  Pnt2.x =  11.0;
  //  Pnt2.y =  11.0;

  Pnt1.z =  0.0;
  Pnt2.z =  0.0;

  sstMath01Mbr2Cls sWC_MiMa;  // Boundings for word coordinates
  // sstMath01Mbr2Cls sScrMiMa;

  //  sScrMiMa.XI = 0.0;
  //  sScrMiMa.YI = 0.0;
  //  sScrMiMa.XA = 10000.0;
  //  sScrMiMa.YA = 10000.0;

//  KoorTrn_stru sTrnWC_DC;
//  KoorTrn_stru sTrnWC_MC;
//  KoorTrn_stru sTrnMC_DC;
//  KoorTrn_stru sTrnDC_WC;

  // Min-Max initialisieren.
  iStat = sWC_MiMa.Mia_2Ini_c ( 0);

  // Min-Max-Bereich mit D2-Punkt abgleichen.
  iStat = sWC_MiMa.Mia_2Koor_c ( 0, Pnt1.x, Pnt1.y);
  iStat = sWC_MiMa.Mia_2Koor_c ( 0, Pnt2.x, Pnt2.y);

  // Min-Max abfragen.
  iStat = sWC_MiMa.Mia_2Les_c ( 6, &Dx);
  iStat = sWC_MiMa.Mia_2Les_c ( 7, &Dy);

  iStat = sWC_MiMa.Mia_2Les_c ( 0, &MinX);
  iStat = sWC_MiMa.Mia_2Les_c ( 1, &MinY);

  return iRet;
}
//=============================================================================
