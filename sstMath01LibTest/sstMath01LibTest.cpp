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

sstMath01dPnt2Cls CircleCalcCenterWithTwoPntsAndRad ( sstMath01dPnt2Cls d2Pnt1, sstMath01dPnt2Cls d2Pnt2, const double dRad);

//=============================================================================
// int main (int argc, char *argv [])
int main ()
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

  {
    sstMath01dPnt2Cls d2Pnt1;  // World coordinate points like UTM, Gauss Krueger or else
    sstMath01dPnt2Cls d2Pnt2;
    sstMath01dPnt2Cls d2PntM;

    d2Pnt1.Set(6.4,1.65);
    d2Pnt2.Set(4.7,5.5);
    double dRad = -2.65;

    d2PntM = CircleCalcCenterWithTwoPntsAndRad( d2Pnt1, d2Pnt2, dRad);
    // d2PntM = d2Pnt1.CircleCalcCenterWithTwoPntsAndRad( d2Pnt2, dRad);
    double dWink;
    double dDist;
    double dLimit = 0.000001;
    d2PntM.Kart_Rel(0, &d2Pnt1, &dWink, &dDist);

    assert (dDist < abs(dRad) + dLimit);
    assert (dDist > abs(dRad) - dLimit);
    d2PntM.Kart_Rel(0, &d2Pnt2, &dWink, &dDist);
    assert (dDist < abs(dRad) + dLimit);
    assert (dDist > abs(dRad) - dLimit);

    iStat = 0;
  }

  {

    unsigned long ulDB_Max = 1000000;  // maximum of unsigned long coordinates
    double dDC_Max = 400.0;           // Maximum of device coodinates

    sstMath01CoorTrnCls oCoorTrn;  // transformation manager

    float fLim = 0.001;


    Pnt1.x =  32538589.0;  // test point 1
    Pnt1.y =   5801400.0;
    Pnt2.x =  32541354.0;  // test point 2
    Pnt2.y =   5804394.0;

    sstMath01Mbr2Cls sWC_MiMa;  // Boundings for world coordinates
    sWC_MiMa.Koor2( 0, Pnt1.x, Pnt1.y);
    sWC_MiMa.Koor2( 0, Pnt2.x, Pnt2.y);

    sstMath01dPnt3Cls dDcPnt1 = Pnt1;
    sstMath01dPnt3Cls dDcPnt2 = Pnt2;

    double dWcDist = Pnt1.Strecke(&Pnt2);  // Calculate Distance in world coordinates

    // calculate Transformations, Device origin should be lower/left
    iStat = oCoorTrn.Calc_All ( 1, sWC_MiMa, ulDB_Max, dDC_Max);

    // Transform points itself to screen coordinates
    iStat = oCoorTrn.Transform_WC_DC(0,&dDcPnt1.x,&dDcPnt1.y);
    iStat = oCoorTrn.Transform_WC_DC(0,&dDcPnt2.x,&dDcPnt2.y);

    // calculate distance on screen
    double dDcDist1 = dDcPnt1.Strecke(&dDcPnt2);

    // calculate screen distance with function
    double dDcDist2 = oCoorTrn.Transform_WC_DC_Dist(dWcDist);

    // had to be identical
    assert(dDcDist2 >= (dDcDist1 - fLim) && dDcDist2 <= (dDcDist1 + fLim));

    // calculate device/screen points
    iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt1, &fDC_Pnt1);
    iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt2, &fDC_Pnt2);

    assert(fDC_Pnt1.x >= (0.0 - fLim) && fDC_Pnt1.x <= (0.0 + fLim));
    assert(fDC_Pnt1.y >= (0.0 - fLim) && fDC_Pnt1.y <= (0.0 + fLim));
    assert(fDC_Pnt2.y >= (dDC_Max - fLim) && fDC_Pnt2.y <= (dDC_Max + fLim));

    // calculate model points
    iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt1, &ulMC_Pnt1);
    iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt2, &ulMC_Pnt2);

    assert(ulMC_Pnt1.x == 0);
    assert(ulMC_Pnt1.y == 0);
    assert(ulMC_Pnt2.y == 1000000);

    // Recalculate world coodinates
    iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt1, &Pnt3);
    assert(Pnt3.x >= (Pnt1.x - fLim) && Pnt3.x <= (Pnt1.x + fLim));
    assert(Pnt3.y >= (Pnt1.y - fLim) && Pnt3.y <= (Pnt1.y + fLim));

    iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt2, &Pnt3);
    assert(Pnt3.x >= (Pnt2.x - fLim) && Pnt3.x <= (Pnt2.x + fLim));
    assert(Pnt3.y >= (Pnt2.y - fLim) && Pnt3.y <= (Pnt2.y + fLim));

  }

  {
    unsigned long ulDB_Max = 1000000;  // maximum of unsigned long coordinates
    double dDC_Max = 15000.0;          // Maximum of device coodinates

    sstMath01CoorTrnCls oCoorTrn;  // transformation manager

    float fLim = 0.001;

    // Testdata are in lower Saxony Germany, UTM Zone 32N Coordinates with 8 Digits, EPSG=4647
    Pnt1.x =  32538589.0;  // test point 1
    Pnt1.y =   5801400.0;
    Pnt2.x =  32541354.0;  // test point 2
    Pnt2.y =   5804394.0;

    sstMath01Mbr2Cls sWC_MiMa;  // Boundings for world coordinates
    sWC_MiMa.Koor2( 0, Pnt1.x, Pnt1.y);
    sWC_MiMa.Koor2( 0, Pnt2.x, Pnt2.y);

    sstMath01dPnt3Cls dDcPnt1 = Pnt1;
    sstMath01dPnt3Cls dDcPnt2 = Pnt2;

    double dWcDist = Pnt1.Strecke(&Pnt2);  // Calculate Distance in world coordinates

    // calculate Transformations, Device origin Zero/Zero should be at center
    // iStat = oCoorTrn.Calc_All2 ( 1, sWC_MiMa, ulDB_Max, dDC_Max);
    iStat = oCoorTrn.Calc_All ( 2, sWC_MiMa, ulDB_Max, dDC_Max);

    // Transform points itself to screen coordinates
    iStat = oCoorTrn.Transform_WC_DC(0,&dDcPnt1.x,&dDcPnt1.y);
    iStat = oCoorTrn.Transform_WC_DC(0,&dDcPnt2.x,&dDcPnt2.y);

    // calculate distance on screen
    double dDcDist1 = dDcPnt1.Strecke(&dDcPnt2);

    // calculate screen distance with function
    double dDcDist2 = oCoorTrn.Transform_WC_DC_Dist(dWcDist);

    // had to be identical
    assert(dDcDist2 >= (dDcDist1 - fLim) && dDcDist2 <= (dDcDist1 + fLim));

    // calculate device/screen points
    iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt1, &fDC_Pnt1);
    iStat = oCoorTrn.Pnt3WC_DC2 ( 0, &Pnt2, &fDC_Pnt2);

    // Point 1 should be at - DC_Max/2 and Point 2 at + DC_Max/2
    double dDC_Max_2 = dDC_Max / 2;
    assert(fDC_Pnt1.y >= (-dDC_Max_2 - fLim) && fDC_Pnt1.y <= (-dDC_Max_2 + fLim));
    // assert(fDC_Pnt2.y >= (+dDC_Max_2 - fLim) && fDC_Pnt2.y <= (+dDC_Max_2 + fLim));

    // calculate model points
    iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt1, &ulMC_Pnt1);
    iStat = oCoorTrn.Pnt3WC_MC ( 0, &Pnt2, &ulMC_Pnt2);

    assert(ulMC_Pnt1.x == 0);
    assert(ulMC_Pnt1.y == 0);
    assert(ulMC_Pnt2.y == 1000000);

    // Recalculate world coodinates
    iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt1, &Pnt3);
    assert(Pnt3.x >= (Pnt1.x - fLim) && Pnt3.x <= (Pnt1.x + fLim));
    assert(Pnt3.y >= (Pnt1.y - fLim) && Pnt3.y <= (Pnt1.y + fLim));

    iStat = oCoorTrn.Pnt3DC_WC2 ( 0, &fDC_Pnt2, &Pnt3);
    assert(Pnt3.x >= (Pnt2.x - fLim) && Pnt3.x <= (Pnt2.x + fLim));
    assert(Pnt3.y >= (Pnt2.y - fLim) && Pnt3.y <= (Pnt2.y + fLim));


  }

  // Test general coordinate transformation functions
  iStat = Test_Trn ( 0);
  assert(iStat==0);


  // Test Mbr-Functions
  iStat = Test_Mbr ( 0);
  assert(iStat==0);

  // Convert Pnt to csv-string with decimal point char and 2 decimal values
  std::string oTestStr = Pnt1.toString();
  assert(oTestStr.compare("32538589.00;5801400.00")==0);

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
int Test_Trn (int iKey)
//-----------------------------------------------------------------------------
{
  int iRet = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  { // First Test with default values
    sstMath01TrnCls oTrn;
    oTrn.SetMov(0,0,0,0);
    oTrn.SetScal(0,1,1,1);
    oTrn.SetRotZ(0,0);
    sstMath01dPnt2Cls oPntIn;
    sstMath01dPnt2Cls oPntOut;

    oTrn.CalcPnt2(0,&oPntIn, &oPntOut);
    assert(oPntOut.getX() == 0.0);
  }
  { // Test with Move values
    sstMath01TrnCls oTrn;
    oTrn.SetMov(0,5,0,0);  // Move 5 in x direction
    oTrn.SetScal(0,1,1,1);
    oTrn.SetRotZ(0,0);
    sstMath01dPnt2Cls oPntIn;
    sstMath01dPnt2Cls oPntOut;

    oTrn.CalcPnt2(0,&oPntIn, &oPntOut);
    assert(oPntOut.getX() == 5.0);
  }
  { // Test with Scal values
    sstMath01TrnCls oTrn;
    oTrn.SetMov(0,0,0,0);
    oTrn.SetScal(0,5,1,1);  // Scal 5 in x direction
    oTrn.SetRotZ(0,0);
    sstMath01dPnt2Cls oPntIn;
    oPntIn.Set(1,1);
    sstMath01dPnt2Cls oPntOut;

    oTrn.CalcPnt2(0,&oPntIn, &oPntOut);
    assert(oPntOut.getX() == 5.0);
  }
  { // Test with Rotation values
    sstMath01TrnCls oTrn;
    oTrn.SetMov(0,0,0,0);
    oTrn.SetScal(0,1,1,1);
    oTrn.SetRotZ(0, dSSTMATH01_PIH);  // Rotate with Pi Half
    sstMath01dPnt2Cls oPntIn;
    oPntIn.Set(5,1);
    sstMath01dPnt2Cls oPntOut;

    oTrn.CalcPnt2(0,&oPntIn, &oPntOut);
    assert(oPntOut.getY() == -5.0);  // Rotates with clock
  }
  { // Test with Rotation values
    sstMath01TrnCls oTrn;
    oTrn.SetMov(0,0,0,0);
    oTrn.SetScal(0,1,1,1);
    oTrn.SetRotZ(0, dSSTMATH01_PIH);  // Rotate with Pi Half
    sstMath01dPnt2Cls oPntIn;
    oPntIn.Set(1,5);
    sstMath01dPnt2Cls oPntOut;

    oTrn.CalcPnt2(0,&oPntIn, &oPntOut);
    assert(oPntOut.getX() == 5.0);  // Rotates with clock
  }

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
sstMath01dPnt2Cls CircleCalcCenterWithTwoPntsAndRad ( sstMath01dPnt2Cls d2Pnt1,
                                                      sstMath01dPnt2Cls d2Pnt2,
                                                      const double dRad)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//----------------------------------------------------------------------------
  sstMath01dPnt2Cls d2PntCenter;  // Result Center point of circle

  // sstMath01dPnt2Cls d2PntLoc1;  // first local point of circle
  sstMath01dPnt2Cls d2PntLoc2;  // second local point of circle
  sstMath01dPnt2Cls d2PntLocM;  // center point in local coordinates

  // Calculate distance and angle from first point to second point
  double dDist = 0.0;
  double dWink1 = 0.0;
  iStat = d2Pnt1.Kart_Rel( 0, &d2Pnt2, &dWink1, &dDist);

  if (dDist <= 0.0) return d2PntCenter;

  // calculate first cathete
  double dKat1 = dDist / 2;
  d2PntLoc2.Set( 0, dKat1);

  // Calculate second cathete
  double dKat2 = 0;
  iStat = d2Pnt1.Pytha_Kath(0, dKat1, abs (dRad), &dKat2);

  // Calculate center point in local coordinates
  if (dRad > 0.0)
    d2PntLocM.Set(  dKat2, dKat1);  // Center is right from Pnt1>Pnt2
  else
    d2PntLocM.Set( -dKat2, dKat1);  // Center is  left from Pnt1>Pnt2

  // calculate angle to center point in local system
  double dWink2 = 0;
  d2PntLocM.Kart_Abs( 0, &dWink2, &dDist);
  dWink2 = dWink2 - dSSTMATH01_PIH;

  // Calculate absolute Angle and norm to TwoPI.
  double dWink = dWink1 + dWink2;
  sstMath01AngCalcCls oAngleManager;
  oAngleManager.Norm8( 0, &dWink);

  // Calculate Center from Circle from first point polar.
  d2Pnt1.Polar_Rel( 0, dWink, abs(dRad), &d2PntCenter);

  // Check Center point
  d2PntCenter.Kart_Rel(0, &d2Pnt1, &dWink, &dDist);
  // assert (dDist == dRad);
  d2PntCenter.Kart_Rel(0, &d2Pnt2, &dWink, &dDist);
  // assert (dDist == dRad);
  // Fatal Errors goes to an assert
  assert(iStat >= 0);

  return d2PntCenter;
}
//============================================================================
