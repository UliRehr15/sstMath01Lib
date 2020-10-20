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
// sstMath01Angle.cpp    27.01.20  Re.    24.05.19  Re.
//
// Funktionen rund um den Winkel als solchen.
// Datei existiert auch in Bibiothek sstlib.
//
// 20.12.01: Funktion -Wnk_Mat2Geo_c- neu. UR
// 06.07.09: Header CADTYP entfernt.  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <string>

#include <sstMath01Lib.h>

#include "sstMath01LibInt.h"

sstMath01AngCalcCls::sstMath01AngCalcCls()
{

}
//=============================================================================
int sstMath01AngCalcCls::Norm4 ( int    Key,
                                 float *Wink)
//.............................................................................

{
  int iret;

//.............................................................................
  if (Key < 0 || Key > 2) return -1;
  iret = 0;
  // istat = 0;

  switch  (Key)
  {
    case 0:
      // Radiant
      // Konstante dSSTMATH01_ZWPI ist in sstMath01Lib.h definiert.
      while (*Wink < 0)
       *Wink = *Wink + (float) dSSTMATH01_ZWPI;

      while (*Wink  >= dSSTMATH01_ZWPI)
       *Wink = *Wink - (float) dSSTMATH01_ZWPI;

      break;
    case 1:
      // Gon
      while (*Wink < 0)
       *Wink = *Wink + (float) 400.0;

      while (*Wink  >= 400.0)
       *Wink = *Wink - (float) 400.0;

      break;
    case 2:
      // Grad
      while (*Wink < 0)
       *Wink = *Wink + (float) 360.0;

      while (*Wink  >= 360.0)
       *Wink = *Wink - (float) 360.0;

      break;
    default:
      // Fehler
      break;
  }
  return iret;

}
//=============================================================================
int sstMath01AngCalcCls::Norm8 ( int     Key,
                                 double *Wink)
//.............................................................................

{
  int iret;
  // Cint2 istat;

//.............................................................................
  if (Key < 0 || Key > 2) return -1;
  iret = 0;
  // istat = 0;

  switch  (Key)
  {
    case 0:
      // Radiant
      // Konstante dSSTMATH01_ZWPI ist in sstMath01Lib.h definiert.
      while (*Wink < 0)
       *Wink = *Wink + dSSTMATH01_ZWPI;

      while (*Wink  >= dSSTMATH01_ZWPI)
       *Wink = *Wink - dSSTMATH01_ZWPI;

      break;
    case 1:
      // Gon
      while (*Wink < 0)
       *Wink = *Wink + 400.0;

      while (*Wink  >= 400.0)
       *Wink = *Wink - 400.0;

      break;
    case 2:
      // Grad
      while (*Wink < 0)
       *Wink = *Wink + 360.0;

      while (*Wink  >= 360.0)
       *Wink = *Wink - 360.0;

      break;
    default:
      // Fehler
      break;
  }
  return iret;

}
//=============================================================================
//$DA
//$TOPIC Wnk_Math2Geod_c
int sstMath01AngCalcCls::Mat2Geo ( int   Key,   // v  -> Vorerst immer 0
                      double  MWnk,  //    -> Mathematischer Winkel
                      double *GWnk)  //   <-  Geodätischer Winkel
                           //
                           //   <- Rückgabe Funktion
                           //      0 = OK
                           //     <0 = allgemeiner Fehler
//
//  Erstellt: 20.12.01   UR
//  Geändert: 20.12.01   UR
//
//$KAT Basics
//$KT  Mathematisch definierten Winkel in Geodätischen transformieren
//
// Mathematisch: Dreht gegen die Uhr, Null ist in Ost
// Geodätisch:   Dreht mit der Uhr, Null ist in Nord
//
//$DE
//.............................................................................
{
  double loc_pi;     // Konstande PI, wie in Mathem definiert
  double loc_pih;    // Abgeleitet PI/Halbe
  double loc_2pi;    // Abgeleitet 2PI
  int iStat;
//.............................................................................
  if (Key != 0) return -1;
  iStat = 0;

  loc_pi =  dSSTMATH01_PI;   // Define aus Mathem
  loc_pih = loc_pi / 2.0;
  loc_2pi = loc_pi * 2.0;

  *GWnk = MWnk;
  *GWnk = loc_2pi - *GWnk;   // Drehrichtung ändern
  *GWnk = *GWnk +  loc_pih;  // Alle Winkel um PI-Halbe bewegen

  // Richtungswinkel (Double) in den Bereich 0 bis 2PI normieren
  iStat = this->Norm8 ( 0, GWnk);

  return iStat;
}
//=============================================================================
/**
* @brief Die Lage eines Winkels zu einem Bezugwinkel ermitteln
*
* Winkel liegt entweder rechts (0) oder links (1).
*
* Changed: 16.02.09  Re.
*
* @ingroup mathem
*
* @param iKey:   [in] For the moment 0
* @param dWink1: [in] Bezugswinkel
* @param dWink2: [in] Winkel für Lageermittlung
*
* @return Errorstate
*
* @retval   = 1: Links
* @retval   = 0: Rechts
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 16.02.09
*/
//-----------------------------------------------------------------------------
int sstMath01AngCalcCls::FindPosition (int iKey, double dWink1, double dWink2)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dWink2 = dWink2 - dWink1;

  // Richtungswinkel (Double) in den Bereich 0 bis 2PI normieren.
  iStat = this->Norm8 ( 0, &dWink2);

  if (dWink2 >= 0.0 && dWink2 < dSSTMATH01_PI)
  {
    iStat = 1;
  }

  return iStat;
}
//=============================================================================
/**
* @brief Winkeldifferenz berechnen
*
* Die Winkeldifferenz ist immer zwischen -Pi und PI.
* Positiv: Winkel dreht gegen die Uhr, links.
* Negativ: Winkel dreht mit Uhr, rechts.
*
* Changed: 26.01.10  Re.
*
* @ingroup mathem
*
* @param iKey:      [in]  For the moment 0
* @param dWink1:    [in]  Winkel 1
* @param dWink2:    [in]  Winkel 2
* @param dWinkDiff: [out] Winkeldifferenz
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 26.01.10
*/
//-----------------------------------------------------------------------------
int sstMath01AngCalcCls::AngleDiff (int iKey, double dWink1, double dWink2, double *dWinkDiff)
//-----------------------------------------------------------------------------
{
  int iLage = 0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iLage = this->FindPosition ( 0, dWink1, dWink2);

  if (iLage == 1)
  {
    // Winkel liegt links
    if(dWink1 > dWink2) dWink2 = dWink2 + dSSTMATH01_ZWPI;
    *dWinkDiff = dWink2 - dWink1;
  }
  else
  {
    // Winkel liegt rechts
    if(dWink2 > dWink1) dWink1 = dWink1 + dSSTMATH01_ZWPI;
    *dWinkDiff = dWink1 - dWink2;
  }

  // Richtungswinkel (Double) in den Bereich 0 bis 2PI normieren.
  iStat = this->Norm8 ( 0, dWinkDiff);

  // Winkel in den Bereich -PI/+PI schieben
  if (*dWinkDiff > dSSTMATH01_PI)
  {
    *dWinkDiff = *dWinkDiff - dSSTMATH01_PI;
  }

  // Winkel negativ oder positiv
  if (iLage == 0) *dWinkDiff = *dWinkDiff * -1.0;

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
/**
* @brief Zwei Richtungswinkel mitteln
*
* More Comment
*
* Changed: 26.01.10  Re.
*
* @ingroup mathem
*
* @param iKey: [in]    For the moment 0
* @param dWink1: [in]  Winkel 1
* @param dWink2: [in]  Winkel 2
* @param dWink3: [out] Gemittelter Winkel
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author Re.
*
* @date 26.01.10
*/
//-----------------------------------------------------------------------------
int sstMath01AngCalcCls::AngleMiddle (int iKey, double dWink1, double dWink2, double *dWink3)
//-----------------------------------------------------------------------------
{
  double dWinkDiff=0.0;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  iStat = this->AngleDiff ( 0, dWink1, dWink2, &dWinkDiff);

  // Den halben Winkel berechnen
  dWinkDiff = dWinkDiff / 2.0;

  *dWink3 = dWink1 + dWinkDiff;

  // Richtungswinkel (Double) in den Bereich 0 bis 2PI normieren.
  iStat = this->Norm8 ( 0, dWink3);

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01AngCalcCls::ArcInside (int iKey, double dWnk1, double dWnk2, double dWnkTest)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // all angles are RAD and turn counter clock wise

  // Richtungswinkel (Double) in den Bereich 0 bis 2PI normieren.
  iStat = this->Norm8 ( 0, &dWnk1);
  iStat = this->Norm8 ( 0, &dWnk2);
  iStat = this->Norm8 ( 0, &dWnkTest);

  if (dWnk1 == dWnk2) return 1;  // Circle

  if (dWnk1 > dWnk2)
  {
    dWnk2 = dWnk2 + dSSTMATH01_ZWPI;
    dWnkTest = dWnkTest + dSSTMATH01_ZWPI;
  }

  if (dWnkTest > dWnk1 && dWnkTest < dWnk2) return 1;

  return iStat;
}
//=============================================================================
