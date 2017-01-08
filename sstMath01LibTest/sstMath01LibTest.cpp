// sstMath01LibTest.cpp    06.01.17  Re.    06.01.17  Re.
//
// Testframe for coordinate transformations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#include <sstMath01Lib.h>

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
