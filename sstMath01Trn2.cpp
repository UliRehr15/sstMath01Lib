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
// sstMath01Trn2.cpp    24.11.18  Re.    30.12.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>

#include "sstMath01Lib.h"

#include "sstMath01LibInt.h"

//=============================================================================
sstMath01CoorTrnCls::sstMath01CoorTrnCls()
{

}
//=============================================================================
int sstMath01CoorTrnCls::Calc_WC_VRC ( int           Key,
                      sstMath01Mbr2Cls      *WC_Mima,
                      sstMath01TrnCls  *TrnWC_VRC)
//-----------------------------------------------------------------------------
{
  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  // In WC_VRC-Transformation Verschiebungswerte setzen
  // iStat = TrnWC_VRC->SetMov( 0,  (-WC_Mima->XI), (-WC_Mima->YI),  0.0);
  iStat = TrnWC_VRC->SetMov( 0,  (-WC_Mima->getXI()), (-WC_Mima->getYI()),  0.0);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_VRC_NPC ( int         Key,
                       sstMath01Mbr2Cls      *WC_Mima,
                       sstMath01TrnCls  *TrnVRC_NPC)
//-----------------------------------------------------------------------------
{
  double  dx,dy,dd;

  int iStat = 0;
//.............................................................................
  if (Key != 0) return -1;

  dx = WC_Mima->getXA() - WC_Mima->getXI();  /* Ausdehnung X der Datenbank */
  dy = WC_Mima->getYA() - WC_Mima->getYI();  /* Ausdehnung Y der Datenbank */

  dx = 1 / dx; dy = 1 / dy;
  dd = fmin(dx,dy);        /* Gráere Ausdehnung whlen */

  // Skalierungswerte in Transformation setzen
  iStat = TrnVRC_NPC->SetScal( 0, dd, dd, 1.0);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_NPC_MC ( int           iKey,
                      unsigned long ulDB_Max,
                      sstMath01TrnCls  *TrnNPC_MC)
//-----------------------------------------------------------------------------
{
  double  dd;

  int iStat;
//.............................................................................
  if (iKey != 0) return -1;

  dd = (double) ulDB_Max;        /* Gráere Ausdehnung whlen */

  // Skalierungswerte in Transformation setzen
  iStat = TrnNPC_MC->SetScal( 0, dd, dd, 1.0);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_MC_DC ( int           iKey,
                     unsigned long ulDB_Max,
                                          double        dDC_Max)
//-----------------------------------------------------------------------------
{
  double  dd;
  double dDB_Max = 0.0;

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  dDB_Max = (double)ulDB_Max;

  dd = dDB_Max / dDC_Max;

  dd = 1 / dd;

  // Skalierungswerte in Transformation setzen

  if (iKey == 0)
  {
    // Da der Nullpunkt des Bildschirmfensters immer links oben liegt,
    // muß das Koordinatensystem auf den Kopf gestellt werden.
    iStat = this->sTrnMC_DC.SetScal( 0, dd, -dd, 1.0);

    // Da das Koordinatensystem auf dem Kopf steht, liegt der Nullpunkt nicht bei
    // 0/0, sondern bei 0/-dd. Das muß bei der Verschiebung berücksichtigt werden.
    iStat = this->sTrnMC_DC.SetMov( 0,  0.0, dDC_Max,  0.0);

  }
  else
  {
    // Da der Nullpunkt des Bildschirmfensters immer links oben liegt,
    // muß das Koordinatensystem auf den Kopf gestellt werden.
    iStat = this->sTrnMC_DC.SetScal( 0, dd, dd, 1.0);

  }

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_NPC_DC ( int           iKey,
                      sstMath01Mbr2Cls      *ScrMima,
                      sstMath01TrnCls  *TrnNPC_DC)
//-----------------------------------------------------------------------------
{
  double  dx,dy,dd;

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  dx = ScrMima->getXA() - ScrMima->getXI();  /* Ausdehnung X der Datenbank */
  dy = ScrMima->getYA() - ScrMima->getYI();  /* Ausdehnung Y der Datenbank */

  dd = fmin(dx,dy);        /* Größere Ausdehnung wählen */

  // Skalierungswerte in Transformation setzen

  if (iKey == 0)
  {
    // Da der Nullpunkt des Bildschirmfensters immer links oben liegt,
    // muß das Koordinatensystem auf den Kopf gestellt werden.
    iStat = TrnNPC_DC->SetScal( 0, dd, -dd, 1.0);

    // Da das Koordinatensystem auf dem Kopf steht, liegt der Nullpunkt nicht bei
    // 0/0, sondern bei 0/-dd. Das muß bei der Verschiebung berücksichtigt werden.
    iStat = TrnNPC_DC->SetMov( 0,  ScrMima->getXI(), (ScrMima->getYI() + dd),  0.0);

  }
  else
  {
    // Da der Nullpunkt des Bildschirmfensters immer links oben liegt,
    // muß das Koordinatensystem auf den Kopf gestellt werden.
    iStat = TrnNPC_DC->SetScal( 0, dd, dd, 1.0);

  }

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_WC_MC ( int           iKey,        // v  -> Vorerst immer 0
                     sstMath01Mbr2Cls      *WC_Mima,
                     unsigned long ulDB_Max)
//-----------------------------------------------------------------------------
{
  sstMath01TrnCls  TrnWC_VRC;   //  WC_VRC_Transformation
  sstMath01TrnCls  TrnVRC_NPC;  //  VRC_NPC_Transformation
  sstMath01TrnCls  TrnNPC_MC;   //  NPC_MC_Transformation

  int iStat = 0;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  // Transformation von Weltkoordinaten in Video-Referenz-Koordinaten berechnen
  iStat = Calc_WC_VRC ( 0, WC_Mima, &TrnWC_VRC);
  iStat = this->sTrnWC_MC.TrnMult( 0,  TrnWC_VRC);

  // Skalierung der VRC-Koordinaten in Einheitskoordinaten.
  iStat = Calc_VRC_NPC ( 0, WC_Mima, &TrnVRC_NPC);
  iStat = this->sTrnWC_MC.TrnMult( 0,  TrnVRC_NPC);

  // Transformation von Einheitskoordinaten in Datenbank-Koordinaten
  iStat = Calc_NPC_MC ( 0, ulDB_Max, &TrnNPC_MC);
  iStat = this->sTrnWC_MC.TrnMult( 0,  TrnNPC_MC);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_WC_DC ( int               iKey,
                                          sstMath01Mbr2Cls  WC_Mima,
                                          unsigned long     ulDB_Max,
                                          double            dDC_Max)
//-----------------------------------------------------------------------------
{
  sstMath01TrnCls  TrnWC_VRC;   //  WC_VRC_Transformation
  sstMath01TrnCls  TrnVRC_NPC;  //  VRC_NPC_Transformation
  sstMath01TrnCls  TrnNPC_MC;   //  NPC_MC_Transformation

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

  // Transformation von Weltkoordinaten in Video-Referenz-Koordinaten berechnen
  iStat = this->Calc_WC_VRC ( 0, &WC_Mima, &TrnWC_VRC);
  iStat = this->sTrnWC_DC.TrnMult( 0,  TrnWC_VRC);

  // Skalierung der VRC-Koordinaten in Einheitskoordinaten.
  iStat = this->Calc_VRC_NPC ( 0, &WC_Mima, &TrnVRC_NPC);
  iStat = this->sTrnWC_DC.TrnMult( 0,  TrnVRC_NPC);

  // Transformation von Einheitskoordinaten in Datenbank-Koordinaten
  iStat = this->Calc_NPC_MC ( 0, ulDB_Max, &TrnNPC_MC);
  iStat = this->sTrnWC_DC.TrnMult( 0,  TrnNPC_MC);

  // Transformation von Datenbank in Bildschirmkoordinaten
  iStat = this->Calc_MC_DC ( iKey, ulDB_Max, dDC_Max);
  iStat = this->sTrnWC_DC.TrnMult( 0,  this->sTrnMC_DC);

  iStat = this->sTrnWC_DC.InvertMatrix( &this->sTrnDC_WC);


  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Calc_All ( int               iKey,
                                          sstMath01Mbr2Cls  WC_Mima,
                                          unsigned long     ulDB_Max,
                                          double            dDC_Max)
//-----------------------------------------------------------------------------
{
  sstMath01TrnCls  TrnWC_VRC;   //  WC_VRC_Transformation
  sstMath01TrnCls  TrnVRC_NPC;  //  VRC_NPC_Transformation
  sstMath01TrnCls  TrnNPC_MC;   //  NPC_MC_Transformation

  int iStat;
//.............................................................................
  if (iKey < 0 || iKey > 1) return -1;

//  iStat = this->Calc_WC_DC ( 1, WC_Mima, ulDB_Max, dDC_Max);
//  iStat = this->Calc_WC_MC ( 0, &WC_Mima, ulDB_Max);
//  iStat = this->Calc_MC_DC ( 1, ulDB_Max, dDC_Max);
  iStat = this->Calc_WC_DC ( iKey, WC_Mima, ulDB_Max, dDC_Max);
  iStat = this->Calc_WC_MC ( iKey, &WC_Mima, ulDB_Max);
  iStat = this->Calc_MC_DC ( iKey, ulDB_Max, dDC_Max);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3WC_DC ( int             iKey,
                       sstMath01dPnt3Cls     *WC_Pnt,
                       sstMath01iPnt2Cls     *DC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_DC.CalcPnt3( 0, WC_Pnt, &d3DC_Pnt);

  // Reduzieren in 2D
  DC_Pnt->x = (int) d3DC_Pnt.x;
  DC_Pnt->y = (int) d3DC_Pnt.y;

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3WC_DC2 ( int             iKey,
                        sstMath01dPnt3Cls     *WC_Pnt,
                        sstMath01fPnt2Cls    *DC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_DC.CalcPnt3( 0, WC_Pnt, &d3DC_Pnt);

  // Reduzieren in 2D
  DC_Pnt->x = (float) d3DC_Pnt.x;
  DC_Pnt->y = (float) d3DC_Pnt.y;

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3WC_DC3 ( int                 iKey,
                        const sstMath01dPnt3Cls   *WC_Pnt,
                        sstMath01ulPnt3Cls        *ulDC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_DC.CalcPnt3( 0, WC_Pnt, &d3DC_Pnt);

  // Reduzieren in 2D
  ulDC_Pnt->x = (unsigned long) round (d3DC_Pnt.x);
  ulDC_Pnt->y = (unsigned long) round (d3DC_Pnt.y);
  ulDC_Pnt->z = (unsigned long) round (d3DC_Pnt.z);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3WC_MC ( int                 iKey,
                       const sstMath01dPnt3Cls   *WC_Pnt,
                       sstMath01ulPnt3Cls        *ulDC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_MC.CalcPnt3( 0, WC_Pnt, &d3DC_Pnt);

  // Reduzieren in 2D
  ulDC_Pnt->x = (unsigned long) round (d3DC_Pnt.x);
  ulDC_Pnt->y = (unsigned long) round (d3DC_Pnt.y);
  ulDC_Pnt->z = (unsigned long) round (d3DC_Pnt.z);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3DC_WC ( int             iKey,
                       sstMath01iPnt2Cls     *DC_Pnt,
                       sstMath01dPnt3Cls     *WC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // Reduzieren in 2D
  d3DC_Pnt.x = (double) DC_Pnt->x;
  d3DC_Pnt.y = (double) DC_Pnt->y;
  d3DC_Pnt.z = 0.0;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_DC.CalcPnt3( 0, &d3DC_Pnt, WC_Pnt);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3DC_WC2( int             iKey,
                       sstMath01fPnt2Cls     *DC_Pnt,
                       sstMath01dPnt3Cls     *WC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // Reduzieren in 2D
  d3DC_Pnt.x = (double) DC_Pnt->x;
  d3DC_Pnt.y = (double) DC_Pnt->y;
  d3DC_Pnt.z = 0.0;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnDC_WC.CalcPnt3( 0, &d3DC_Pnt, WC_Pnt);

  return iStat;
}
//=============================================================================
int sstMath01CoorTrnCls::Pnt3DC_WC3 ( int             iKey,
                        sstMath01ulPnt3Cls    *DC_Pnt,
                        sstMath01dPnt3Cls     *WC_Pnt)
//-----------------------------------------------------------------------------
{

  sstMath01dPnt3Cls d3DC_Pnt;  // Bildschirmpunkt in D3/Double
  int iStat = 0;
//.............................................................................
  if (iKey != 0) return -1;

  // Reduzieren in 2D
  d3DC_Pnt.x = (double) DC_Pnt->x;
  d3DC_Pnt.y = (double) DC_Pnt->y;
  d3DC_Pnt.z = 0.0;

  // 3D-Punkt transformieren in Bildschirm-Koordinatenebene
  iStat = this->sTrnWC_DC.CalcPnt3( 0, &d3DC_Pnt, WC_Pnt);

  return iStat;
}
//=============================================================================
//=============================================================================
int sstMath01CoorTrnCls::Transform_WC_DC (int iKey, double *dX, double *dY)
//-----------------------------------------------------------------------------
{
  sstMath01fPnt2Cls fDC_Pnt;  // 2D Device (screen) coordinates as float
  sstMath01dPnt3Cls dWC_Pnt;  // 3D World coordinates as double

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  dWC_Pnt.x = *dX;
  dWC_Pnt.y = *dY;

  this->Pnt3WC_DC2(0,&dWC_Pnt,&fDC_Pnt);

  *dX = fDC_Pnt.x;
  *dY = fDC_Pnt.y;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01CoorTrnCls::Transform_DC_WC (int iKey, double *dX, double *dY)
//-----------------------------------------------------------------------------
{
  sstMath01fPnt2Cls fDC_Pnt;  // 2D Device (screen) coordinates as float
  sstMath01dPnt3Cls dWC_Pnt;  // 3D World coordinates as double

  int iRet  = 0;
  int iStat = 0;
  //-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  fDC_Pnt.x = (float) *dX;
  fDC_Pnt.y = (float) *dY;

  this->Pnt3DC_WC2(0,&fDC_Pnt, &dWC_Pnt);

  *dX = dWC_Pnt.x;
  *dY = dWC_Pnt.y;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
double sstMath01CoorTrnCls::Transform_WC_DC_Dist (const double dWcDist)
{
  double dScalX = 0.0;
  double dScalY = 0.0;
  double dScalZ = 0.0;
  this->sTrnWC_DC.GetScal(0,&dScalX,&dScalY,&dScalZ);
  return dScalX * dWcDist;
}
//=============================================================================
double sstMath01CoorTrnCls::Transform_DC_WC_Dist (const double dDcDist)
{
  double dScalX = 0.0;
  double dScalY = 0.0;
  double dScalZ = 0.0;
  this->sTrnDC_WC.GetScal(0,&dScalX,&dScalY,&dScalZ);
  return dScalX * dDcDist;
}
//=============================================================================

