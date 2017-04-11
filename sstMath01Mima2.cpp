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
// sstMath01Mima2.cpp   11.04.17  Re.   11.04.17 Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include <string>

#include "sstStr01Lib.h"
#include "sstMath01Lib.h"

#include "sstMath01LibInt.h"

//=============================================================================
sstMath01Mbr2Cls::sstMath01Mbr2Cls()
{
  this->XA = 0.0;
  this->XI = 0.0;
  this->YA = 0.0;
  this->YI = 0.0;
}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Ini_c( int      key)
//.............................................................................
{
  if (key) return -10;   // Fehler : Key ungleich null
//.............................................................................
  this->XI = +dSSTSTR01_UNDEF_DOUBLE;   // dSSTSTR01_UNDEF_DOUBLE wird in "$UNDEF.H" definiert
  this->YI = +dSSTSTR01_UNDEF_DOUBLE;   // Ist i.a. 1.0E+300
  this->XA = -dSSTSTR01_UNDEF_DOUBLE;
  this->YA = -dSSTSTR01_UNDEF_DOUBLE;
  return 0;              // Rückgabe immer 0: alles OK !!
}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2IniPkt_c( int      Key,    // v  -> Key vorerst immer 0
                   double   X1,     // v  -> x Punkt 1
                   double   Y1)     // v  -> y Punkt 1
//.............................................................................
{
  if (Key !=0) return -10;   // Fehler : Key ungleich null
//.............................................................................

  this->XI = X1;
  this->YI = Y1;
  this->XA = X1;
  this->YA = Y1;

  return 0;              // Rückgabe immer 0: alles OK !!
}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2IniLin_c( int      key,    // v  -> Key vorerst immer 0
                   double   X1,     // v  -> x Punkt 1
                   double   Y1,     // v  -> y Punkt 1
                   double   X2,     // v  -> x Punkt 2
                   double   Y2)     // v  -> y Punkt 2
//.............................................................................
{
  if (key !=0) return -10;   // Fehler : Key ungleich null
//.............................................................................
  if (X2 >= X1)
  {
    this->XA = X2;
    this->XI = X1;
  }
  else
  {
    this->XA = X1;
    this->XI = X2;
  }

  if (Y2 >= Y1)
  {
    this->YA = Y2;
    this->YI = Y1;
  }
  else
  {
    this->YA = Y1;
    this->YI = Y2;
  }
  return 0;              // Rückgabe immer 0: alles OK !!
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2OK_c( int      key)
//.............................................................................
{
  if (key != 0) return -1;            // Falscher key, Programmabbruch !!

  if (this->XI ==  dSSTSTR01_UNDEF_DOUBLE) return 1;
  if (this->XA == -dSSTSTR01_UNDEF_DOUBLE) return 1;
  if (this->YI ==  dSSTSTR01_UNDEF_DOUBLE) return 1;
  if (this->YA == -dSSTSTR01_UNDEF_DOUBLE) return 1;
  return 0;
}

//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Koor_c( int      key,    // v -> key vorerst immer 0
                 double   X,      // v -> Prüfwert: Punkt-X
                 double   Y)      // v -> Prüfwert: Punkt-Y
//.............................................................................
{
  int ret;                     // Rückgabestatus
//.............................................................................
  if (key) return -10;           // Falscher key, Programmabbruch !!
//.............................................................................
  ret = 0;                       // Voreinstellung 0
//.............................................................................
  if (X  < this->XI)
  {
    this->XI = X;    // Punkt liegt rechts dem Kasten
    ret = 1;
  }
  if( X  > this->XA)
  {
    this->XA = X;    // Punkt liegt links dem Kasten
    ret = 1;
  }
  if (Y  < this->YI)
  {
    this->YI = Y;     // Punkt liegt vor dem Kasten
    ret =  ret + 2;
  }
  if( Y  > this->YA)
  {
    this->YA = Y;    // Punkt liegt hinter dem Kasten
    ret =  ret + 2;
  }
  return (ret);
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Pkt_c( int         Key,    // v -> Key vorerst immer 0
                sstMath01dPnt2Cls *Pkt)    //   -> Prüfwert: D2-Punkt
//.............................................................................
{
  int iRet;                     // Rückgabestatus
//.............................................................................
  if (Key) return -10;            // Falscher key, Programmabbruch !!
//.............................................................................
  iRet = 0;                       // Voreinstellung 0

  // Min-Max mit Koordinaten abgleichen
  iRet = this->Mia_2Koor_c ( Key,  Pkt->x,  Pkt->y);

  return (iRet);
}
//-----------------------------------------------------------------------------
//int Mia_2Lin_c( int         Key,    // v -> Key vorerst immer 0
//                sstMath01Mbr2Cls    *Mima,   //  <-> Min-Max-Werte
//                D2Lin_stru *Lin)    //   -> Prüfwert: D2-Linie
////.............................................................................
//{
//  int ii;                       // Rückgabestatus
//  int iRet;                     // Rückgabestatus
////.............................................................................
//  if (Key) return -10;            // Falscher key, Programmabbruch !!
////.............................................................................
//  iRet = 0;                       // Voreinstellung 0

//  for ( ii=1; ii<=2; ii++)
//  {
//    // Min-Max mit Koordinaten abgleichen
//    iRet = Mia_2Koor_c ( Key, Mima,  Lin->Pkt[ii-1].x,  Lin->Pkt[ii-1].y);
//  }

//  return (iRet);
//}
////-----------------------------------------------------------------------------
//int Mia_2Tri_c( int         Key,    // v -> Key vorerst immer 0
//                sstMath01Mbr2Cls    *Mima,   //  <-> Min-Max-Werte
//                D2Tri_stru *Tri)    //   -> Prüfwert: D2-Dreieck
////.............................................................................
//{
//  int ii;                       // Rückgabestatus
//  int iRet;                     // Rückgabestatus
////.............................................................................
//  if (Key) return -10;            // Falscher key, Programmabbruch !!
////.............................................................................
//  iRet = 0;                       // Voreinstellung 0

//  for ( ii=1; ii<=3; ii++)
//  {
//    // Min-Max mit Koordinaten abgleichen
//    iRet = Mia_2Koor_c ( Key, Mima,  Tri->Pkt[ii-1].x,  Tri->Pkt[ii-1].y);
//  }

//  return (iRet);
//}
////-----------------------------------------------------------------------------
//int Mia_2Quad_c( int       Key,    // v -> Key vorerst immer 0
//                 sstMath01Mbr2Cls    *Mima,   //  <-> Min-Max-Werte
//                 D2Box_stru *Box)    //   -> Prüfwert: D2-Viereck
////.............................................................................
//{
//  int ii;                       // Rückgabestatus
//  int iRet;                     // Rückgabestatus
////.............................................................................
//  if (Key) return -10;            // Falscher key, Programmabbruch !!
////.............................................................................
//  iRet = 0;                       // Voreinstellung 0

//  for ( ii=1; ii<=4; ii++)
//  {
//    // Min-Max mit Koordinaten abgleichen
//    iRet = Mia_2Koor_c ( Key, Mima, Box->Pkt[ii-1].x, Box->Pkt[ii-1].y);
//  }

//  return (iRet);
//}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Pruef_c( int      key,    // v -> Key vorerst immmer 0
                  double   X,      // v -> Prüfwert: Punkt-X
                  double   Y)      // v -> Prüfwert: Punkt-Y
//.............................................................................
{ 
  int ret;                 // Rückgabewert
//
  if (key) return -10;       // Unzulässiger Key
//.............................................................................
  ret = this->Mia_2OK_c(0);
  if (ret)
  { //.....................Test:   Feld z.T. auáerhalb der Dimensionen
    return -1;
  }
//.............................................................................
  ret = 0;
  if (X  < this->XI)
  {
    ret = 1;     // Punkt liegt vor dem Kasten
  }
  else if( X  > this->XA)
  {
    ret = 1;     // Punkt liegt hinter dem Kasten
  }
  if (Y  < this->YI)
  {
     ret = ret +2;     // Punkt liegt unter dem Kasten
  }
  else if( Y  > this->YA)
  {
     ret = ret +2;     // Punkt liegt über dem Kasten
  }
  return ret;
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2PruefT_c( int    Key,    // v  -> Key vorerst immmer 0
                   double   X,      // v  -> Prüfwert: Punkt-X
                   double   Y,      // v  -> Prüfwert: Punkt-Y
                   double   Tol)    // v  -> Toleranzwert
//.............................................................................
{ 
  int ret;                 // Rückgabewert
//
  if (Key) return -10;       // Unzulässiger Key
//.............................................................................
  ret = this->Mia_2OK_c(0);
  if (ret)
  { //.....................Test:   Feld z.T. auáerhalb der Dimensionen
    return -1;
  }
//.............................................................................
  ret = 0;
  if (X  < this->XI - Tol)
  {
    ret = 1;     // Punkt liegt vor dem Kasten
  }
  else if( X  > this->XA + Tol)
  {
    ret = 1;     // Punkt liegt hinter dem Kasten
  }
  if (Y  < this->YI - Tol)
  {
     ret = ret +2;     // Punkt liegt unter dem Kasten
  }
  else if( Y  > this->YA + Tol)
  {
     ret = ret +2;     // Punkt liegt über dem Kasten
  }
  return ret;
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Box_c( int               key,    // v -> vorerst immer null
                                  sstMath01Mbr2Cls *Mima2)  //   -> Min-Max-Werte : Eingabebereich 2
//.............................................................................
{
  int ret;
//.............................................................................
  if (key != 0)  return -10; // Unzulässiger Key
//.............................................................................
  ret = this->Mia_2OK_c(0);
  if (ret)
  { //...........................Feld 1 z.T. auáerhalb der Dimensionen
    return -1;
  }
  ret = Mima2->Mia_2OK_c(0);
  if (ret)
  { //...........................Feld 2 z.T. auáerhalb der Dimensionen
    return -1;
  }
  //.............................................................................

  if (Mima2->XI > this->XA) return 0;
  if (Mima2->YI > this->YA) return 0;
  if (Mima2->XA < this->XI) return 0;
  if (Mima2->YA < this->YI) return 0;

  return 1;
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Ber_c( int      key,   // v -> Eingabe-Key = 0 : Gesamtbereich bilden
                                //      Eingabe-Key = 1 : Schnittbereich bilden
                sstMath01Mbr2Cls *Mima2, //   -> Min-Max-Werte : Eingabebereich 2
                sstMath01Mbr2Cls *Mima3) //  <-  Min-Max-Werte : Rückgabebereich
//.............................................................................
{
  int    ret;                      // Rückgabewert
  double s1x,s1y,s2x,s2y,s3x,s3y; // Alle Seitenlängen der Mima's
//.............................................................................
  if ((key != 0) && (key != 1)) return -10; // Unzulässiger Key
//.............................................................................
  ret = this->Mia_2OK_c(0);
  if (ret)
  { //...........................Feld 1 z.T. außerhalb der Dimensionen
    return -1;
  }
  ret = Mima2->Mia_2OK_c(0);
  if (ret)
  { //...........................Feld 2 z.T. außerhalb der Dimensionen
    return -2;
  }
//.............................................................................
//
  ret = 2;  // Voreinstellung : Verschneidung
//
// Test: Gibt es überhaupt eine Berührung ??
  if (Mima2->XI > this->XA) ret = 3; // Feld 2 liegt links  von Feld 1
  if (Mima2->YI > this->YA) ret = 3; // Feld 2 liegt hinter     Feld 1
  if (Mima2->XA < this->XI) ret = 3; // Feld 2 liegt rechts von Feld 1
  if (Mima2->YA < this->YI) ret = 3; // Feld 2 liegt vor        Feld 1
// Verschneidung gefordert und keine Berührung: Programmende und Fehler
  if (key && ret == 3)
  {
    ret = Mima3->Mia_2Ini_c(0); // Ergebnis ungültig
    return 3;
  }
  if(key)
  {    // Verschneidung
    Mima3->XI = fmax (this->XI,Mima2->XI);
    Mima3->YI = fmax (this->YI,Mima2->YI);
    Mima3->XA = fmin (this->XA,Mima2->XA);
    Mima3->YA = fmin (this->YA,Mima2->YA);
  }
  else
  {    // Gesamtbereich
    Mima3->XI = fmin (this->XI,Mima2->XI);
    Mima3->YI = fmin (this->YI,Mima2->YI);
    Mima3->XA = fmax (this->XA,Mima2->XA);
    Mima3->YA = fmax (this->YA,Mima2->YA);
  }
  s1x = this->XA - this->XI;  // Alle Seitenlängen als Kenngrößen berechnen
  s1y = this->YA - this->YI;
  s2x = Mima2->XA - Mima2->XI;
  s2y = Mima2->YA - Mima2->YI;
  s3x = Mima3->XA - Mima3->XI;
  s3y = Mima3->YA - Mima3->YI;

//.............................................................................
//  Seitenlängen sind identisch

  if ((s3x == s1x) && (s3y ==  s1y)) ret = 1;   // vollst. Überdeckung
  if ((s3x == s2x) && (s3y ==  s2y)) ret = 1;   // vollst. Überdeckung

  return ret;
}
//-----------------------------------------------------------------------------
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Les_c( int    key,     // v ->  = 0 : Rückgabe in D: Min X
                                //       = 1 : Rückgabe in D: Min Y
                                //       = 3 : Rückgabe in D: Max X
                                //       = 4 : Rückgabe in D: Max Y
                                //       = 6 : Rückgabe in D: Länge X
                                //       = 7 : Rückgabe in D: Länge Y
                double  *D)     //  <-  Ergebnis D
//.............................................................................
{
  int ret;             // Rückgabewert
//.............................................................................
  if ((key < 0) || (key > 8)) return -10;  // Zuklarer Key, Abbruch !!
//.............................................................................
  ret = this->Mia_2OK_c(0);
  if (ret)
  {                      //...Feld z.T. auáerhalb der Dimensionen
    ret = -1;
    *D = +dSSTSTR01_UNDEF_DOUBLE;
    return ret;
  }
//.............................................................................
  ret = 0;
  switch(key)
  {
    case 0:   //........................................ Rückgabewert  Min X
      *D = this->XI;
      break;
    case 1:   //........................................ Rückgabewert  Min Y
      *D = this->YI;
      break;
    case 3:   //........................................ Rückgabewert  Max X
      *D = this->XA;
      break;
    case 4:   //........................................ Rückgabewert  Max Y
      *D = this->YA;
      break;
    case 6:   //........................................ Rückgabewert  Seite X
      *D = (this->XA)-(this->XI);
      break;
    case 7:  //......................................... Rückgabewert  Seite Y
      *D = (this->YA)-(this->YI);
      break;
    default:
      ret= -1;
      *D = +dSSTSTR01_UNDEF_DOUBLE;
      break;
    }
  return ret;
}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Centr_c ( int      KEY,     // v  -> Vorerst immer 0
                   sstMath01dPnt2Cls  *Pkt)     //   <-> Mittelpunkt
//.............................................................................
{
  int istat;
//.............................................................................
  if (KEY != 0) return -1;
  istat = 0;

  // MinMax-Feld leer ?
  istat = this->Mia_2OK_c(0);
  if (istat)
  { //.....................Test:   Feld z.T. auáerhalb der Dimensionen
    return -1;
  }

  (*Pkt).x = (this->XI + this->XA) / 2.0;
  (*Pkt).y = (this->YI + this->YA) / 2.0;

  return istat;
}
//=============================================================================
//int Mia_2DrehBox_c ( int       Key,     // v  -> Vorerst immer 0
//                     sstMath01Mbr2Cls    *Mima,    //   <-> Min-Max-Werte
//                     double      Wnk,     // v  -> Drehwinkel (Rad)
//                     D2Box_stru *Box)     //   <-  Berechnetes D2-Viereck
////.............................................................................
//{
//  double Wnk_co;
//  double Wnk_si;

//  int iRet;
//  // Cint2 iStat;
////.............................................................................
//  if (Key != 0) return -1;
//  iRet = 0;
//  // iStat = 0;

//  Wnk_co = cos ( Wnk);
//  Wnk_si = sin ( Wnk);

//  // lokale gedrehte MinMax-Box rechnen
//  Box->Pkt[0].x =  Mima->XI * Wnk_co - Mima->YI * Wnk_si;
//  Box->Pkt[0].y =  Mima->XI * Wnk_si + Mima->YI * Wnk_co;
//  Box->Pkt[1].x =  Mima->XA * Wnk_co - Mima->YI * Wnk_si;
//  Box->Pkt[1].y =  Mima->XA * Wnk_si + Mima->YI * Wnk_co;
//  Box->Pkt[2].x =  Mima->XA * Wnk_co - Mima->YA * Wnk_si;
//  Box->Pkt[2].y =  Mima->XA * Wnk_si + Mima->YA * Wnk_co;
//  Box->Pkt[3].x =  Mima->XI * Wnk_co - Mima->YA * Wnk_si;
//  Box->Pkt[3].y =  Mima->XI * Wnk_si + Mima->YA * Wnk_co;

//  if (iRet < 0)
//  {
//    assert (iRet >= 0);
//  }
//  return iRet;
//}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Move_XY_c ( int         Key,     // v  -> Vorerst immer 0
                     double      Dx,      // v  -> Verschiebungswert X
                     double      Dy)      // v  -> Verschiebungswert Y
//.............................................................................
{
  int iRet;
  // Cint2 iStat;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  this->XI = this->XI + Dx;
  this->XA = this->XA + Dx;

  this->YI = this->YI + Dy;
  this->YA = this->YA + Dy;

  if (iRet < 0)
  {
    assert (iRet >= 0);
  }
  return iRet;
}
//=============================================================================
int sstMath01Mbr2Cls::Mia_2Scal_c ( int      Key,    // v  -> Vorerst immer 0
                  double   Scal)
//.............................................................................
{
  sstMath01Mbr2Cls LocMima;  // Zwischenwert
  sstMath01dPnt2Cls  Center;   // Mittelpunkt
  // int   iRet;
  int   iStat=0;
//.............................................................................
  if (Key  != 0)   return -1;
  if (Scal <= 0.0) return -2;
  // iRet = 0;
  // istat = 0;

  // Mittelpunkt einer MinMax-Box rechnen
  iStat = this->Mia_2Centr_c ( 0, &Center);

  // MinMax-Bereich in Nullpunkt verschieben
  LocMima.XI = this->XI - Center.x;
  LocMima.XA = this->XA - Center.x;
  LocMima.YI = this->YI - Center.y;
  LocMima.YA = this->YA - Center.y;

  // MinMax-Bereich mit Wert skalieren
  LocMima.XI = LocMima.XI * Scal;
  LocMima.XA = LocMima.XA * Scal;
  LocMima.YI = LocMima.YI * Scal;
  LocMima.YA = LocMima.YA * Scal;

  // MinMax-Bereich wieder in Mittelpunkt zurückschieben
  this->XI  = LocMima.XI + Center.x;
  this->XA  = LocMima.XA + Center.x;
  this->YI  = LocMima.YI + Center.y;
  this->YA  = LocMima.YA + Center.y;

  return iStat;
}
//=============================================================================

