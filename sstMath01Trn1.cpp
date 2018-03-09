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
// sstMath01Trn1.cpp    30.12.16  Re.    30.12.16  Re.
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
sstMath01TrnCls::sstMath01TrnCls()
{

  int ii, jj;

  for ( ii=0; ii<=3; ii++)
  {
    for ( jj=0; jj<=3; jj++)
    {
      Trn[ii][jj] = 0.0;
    }
  }

  // Einheitsmatrix setzen, sonst funktionieren die Multiplikationen nicht.
  for (ii=0; ii <=3; ii++)
  {
    Trn[ii][ii] = 1.0;
  }
}
//=============================================================================
int sstMath01TrnCls::SetMov ( int               Key,   // v  -> Vorerst immer 0
                              double            MovX,  // v  -> Verschiebung X
                              double            MovY,  // v  -> Verschiebung Y
                              double            MovZ)  // v  -> Verschiebung Z
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  Trn[3][0] = MovX;
  Trn[3][1] = MovY;
  Trn[3][2] = MovZ;
  return iret;
}
//=============================================================================
int sstMath01TrnCls::SetScal ( int             Key,    // v  -> Vorerst immer 0
                               double            ScalX,  // v  -> Skalierung X
                               double            ScalY,  // v  -> Skalierung Y
                               double            ScalZ)  // v  -> Skalierung Z
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  Trn[0][0] = ScalX;
  Trn[1][1] = ScalY;
  Trn[2][2] = ScalZ;
  return iret;
}
//=============================================================================
int sstMath01TrnCls::SetRotZ ( int               Key,    // v  -> Vorerst immer 0
                               double            RotZ)   // v  -> Rotation Z-Achse
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  Trn[0][0] =   cos ( RotZ);
  Trn[0][1] = - sin ( RotZ);
  Trn[1][0] =   sin ( RotZ);
  Trn[1][1] =   cos ( RotZ);
  return iret;
}
//=============================================================================
int sstMath01TrnCls::GetMov ( int                Key,   // v  -> Vorerst immer 0
                              double            *MovX,  //   <-  Verschiebung X
                              double            *MovY,  //   <-  Verschiebung Y
                              double            *MovZ)  //   <-  Verschiebung Z
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  *MovX = Trn[3][0];
  *MovY = Trn[3][1];
  *MovZ = Trn[3][2];
  return iret;
}
//=============================================================================
int sstMath01TrnCls::GetScal ( int                Key,    // v  -> Vorerst immer 0
                          double            *ScalX,  //   <-  Skalierung X
                          double            *ScalY,  //   <-  Skalierung Y
                          double            *ScalZ)  //   <-  Skalierung Z
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  *ScalX = Trn[0][0];
  *ScalY = Trn[1][1];
  *ScalZ = Trn[2][2];
  return iret;
}
//=============================================================================
int sstMath01TrnCls::GetRotZ ( int                Key,    // v  -> Vorerst immer 0
                               double            *RotZ)   // v  -> Rotation Z-Achse
//-----------------------------------------------------------------------------
{
  int iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  *RotZ =   cos ( Trn[0][0]);
  return iret;
}
//=============================================================================
int sstMath01TrnCls::CalcPnt2 ( int               Key,     // v  -> Vorerst immer 0
                            sstMath01dPnt2Cls           *PktIn,   //    -> 2D-Punkt
                            sstMath01dPnt2Cls           *PktOut)  //   <-  Transformierter Punkt
//-----------------------------------------------------------------------------
{
  d4Pnt_stru  PIn;
  d4Pnt_stru  POut;

  int jj,ll;

  double ce;
  int  iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  PIn.Kor[0] = PktIn->x;
  PIn.Kor[1] = PktIn->y;
  PIn.Kor[2] = 1.0;  // die ominöse homogene Koordinate ?
  PIn.Kor[3] = 1.0;  // die ominöse homogene Koordinate ?

  for ( jj=0; jj<= 3; jj++)
  {
    ce = 0.0;
    for ( ll=0; ll<= 3; ll++)
      {
        ce = PIn.Kor[ll] * Trn[ll][jj] + ce;
      }
    POut.Kor[jj] = ce;
  }

  PktOut->x = POut.Kor[0];
  PktOut->y = POut.Kor[1];

  return iret;
}
//=============================================================================
int sstMath01TrnCls::CalcPnt3 ( int                 Key,     // v  -> Vorerst immer 0
                            const sstMath01dPnt3Cls   *PktIn,   //    -> 3D-Punkt
                            sstMath01dPnt3Cls         *PktOut)  //   <-  Transformierter Punkt
//-----------------------------------------------------------------------------
{
  d4Pnt_stru  PIn;
  d4Pnt_stru  POut;

  int jj,ll;

  double ce;
  int  iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  PIn.Kor[0] = PktIn->x;
  PIn.Kor[1] = PktIn->y;
  PIn.Kor[2] = PktIn->z;
  PIn.Kor[3] = 1.0;  // die ominöse homogene Koordinate ?

  for ( jj=0; jj<= 3; jj++)
  {
    ce = 0.0;
    for ( ll=0; ll<= 3; ll++)
      {
        ce = PIn.Kor[ll] * Trn[ll][jj] + ce;
      }
    POut.Kor[jj] = ce;
  }

  PktOut->x = POut.Kor[0];
  PktOut->y = POut.Kor[1];
  PktOut->z = POut.Kor[2];

  return iret;
}
//=============================================================================
int sstMath01TrnCls::TrnMult ( int               Key,     // v  -> Vorerst immer 0
                       sstMath01TrnCls  b)       //    -> Zweite Transformation
//-----------------------------------------------------------------------------
{
  int           ii,jj,ll;
  double        ce;
  sstMath01TrnCls  Loc_c;
  int           iret;
//.............................................................................
  if (Key != 0) return -1;
  iret = 0;

  for ( jj=0; jj<=3; jj++)
    for ( ii=0; ii<=3; ii++)
    { ce = 0.0;
      for ( ll=0; ll<=3; ll++)
      {
        ce = this->Trn[ii][ll] * b.Trn[ll][jj] + ce;
      }
      Loc_c.Trn[ii][jj]=ce;
    }

  for ( jj=0; jj<=3; jj++)
    for ( ii=0; ii<=3; ii++)
      this->Trn[jj][ii] = Loc_c.Trn[jj][ii];

  return iret;
}
//=============================================================================
int sstMath01TrnCls::InvertMatrix( sstMath01TrnCls *c)
{ int i,j,k;
  int np,ke;
  double pv;
  int ni[dMATDIM],nj[dMATDIM];
  double b[dMATDIM+1][dMATDIM];
  int error;
  error = 0;
  ke = dMATDIM;

  /*--- Festlegen der Anfangsbedingungen -------------------------------------*/
  for ( k=0;k<=dMATDIM-1;k++)
  { ni[k] = -1;
    nj[k] = -1;
    b[ke][k] = 0.0;
  }
  for ( i=0;i<= dMATDIM-1;i++)
    for ( j=0;j<=dMATDIM-1;j++)
    { b[i][j] = this->Trn[i][j];
      c->Trn[i][j] = this->Trn[i][j];
    }
/*--- Große Programmschleife -----------------------------------------------*/
  for ( i=0; i<= dMATDIM-1;i++)
  { pv = 0.0;
    np = -1;
/*--- Suchen des zeilengrößten Elements (Pivot) ----------------------------*/
    for ( j=0;j<=dMATDIM-1;j++)
    { if (( fabs(b[i][j]) > fabs(pv)) && (ni[j] == -1) )
      { pv = b[i][j];
  np = j;
      }
    }
/*---Speichern der Pivotstelle zum Sortieren -------------------------------*/
/*---Größtes Element = 0, -> Determinante = 0; -----------------------------*/
    if ( pv == 0.0) error = 1;
    if ( error == 0 )
    { ni[np] = i;
      nj[i]  = np;
/*--- Bilden der Kellerzeile -----------------------------------------------*/
      for ( j=0;j<=dMATDIM-1;j++)
  if (np != j) b[ke][j] = (b[i][j] / pv) * (-1.0);
/*--- Rückspeichern der Kellerzeile (Pivotzeile ) --------------------------*/
      for ( j=0;j<=dMATDIM-1;j++)
  if ( np != j) b[i][j] = b[ke][j];
/*--- Errechnen der Restelemente -------------------------------------------*/
      for ( k=0;k<=dMATDIM-1;k++)
  for (j=0;j<= dMATDIM-1;j++)
    if ( (k != i) && (j != np) )
      b[k][j] = b[k][j] + ( b[ke][j] * b[k][np]);
/*--- Nullsetzen der Kellerzeile -------------------------------------------*/
      for ( j=0;j<=dMATDIM-1;j++)
        b[ke][j] = 0.0;
/*--- Bilden der Pivotspalte -----------------------------------------------*/
      for ( k=0;k<=dMATDIM-1;k++)
  if ( i != k) b[k][np] = b[k] [np] / pv;
/*--- Pivot invertieren ----------------------------------------------------*/
      b[i][np] = 1.0 / pv;
    }
  }
/* Sortieren der invertierten Matrix ---------------------------------------*/
  for ( i=0;i<=dMATDIM-1;i++)
    for ( j=0;j<=dMATDIM-1;j++)
      c->Trn[nj[i]][ni[j]] = b[i][j];
  return error;
}
/*--- Ende Inversion -------------------------------------------------------*/


