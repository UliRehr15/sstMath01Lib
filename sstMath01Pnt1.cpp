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
// sstMath01Pnt1.cpp    09.03.18  Re.    30.12.16  Re.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include <string>

#include <sstStr01Lib.h>

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
double sstMath01dPnt2Cls::VBetrag ()
{
  return(sqrt(Quadr(this->x)+Quadr(this->y)));
}
double sstMath01dPnt2Cls::Strecke ( sstMath01dPnt2Cls *P2)
{
  return(sqrt(Quadr(P2->x-this->x)+Quadr(P2->y-this->y)));
}
double sstMath01dPnt2Cls::Riwi ( sstMath01dPnt2Cls *P2)
{
  double   dx, dy, riwi;
  dx = P2->x - this->x;
  dy = P2->y - this->y;

  if ((fabs(dx) <= 0.0) && (fabs(dy) <= 0.0)) return(0.0);  // Strecke zu kurz

  riwi = atan2(dx, dy);                              // Im Intervall [-PI, PI[

  if (riwi < 0.0) riwi += ZWPI;                          // Intervall [0, 2PI[

  return(riwi);
}
double sstMath01dPnt2Cls::VekNorm ()
  {
   double   betrag;

//.........................................2D-Vektor auf Länge 1.0 normieren....

   if ((betrag=this->VBetrag()) < 1e-99) return(0.0);

   this->x /= betrag;
   this->y /= betrag;

   return(betrag);
  }

double sstMath01dPnt2Cls::NeuPkt ( sstMath01dPnt2Cls *Vec, double cc, sstMath01dPnt2Cls *Pn)
{
   sstMath01dPnt2Cls   Vn=*Vec;
   double   betrag;

//.....................................................2D-Neupunkt berechnen....

   betrag = Vn.VekNorm();

   Pn->x = this->x + cc * Vn.x;                     // In Richtung Normalenvektor
   Pn->y = this->y + cc * Vn.y;

   return(betrag);
  }
double sstMath01dPnt2Cls::NeuPkt2 ( sstMath01dPnt2Cls *P2, double cc, sstMath01dPnt2Cls *Pn)
{
   sstMath01dPnt2Cls   Vec;

//.....................................................2D-Neupunkt berechnen....

   Vec.x = P2->x - this->x;
   Vec.y = P2->y - this->y;

   return(this->NeuPkt( &Vec, cc, Pn));
  }

 double sstMath01dPnt2Cls:: FusPkt ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *Ps, sstMath01dPnt2Cls *Pf)
  {
   sstMath01dPnt2Cls   Vb, Pa;
   double   betrag, t0;

//....................................................2D-Fußpunkt auf Gerade....

   Vb.x = P2->x - this->x;                                // Richtung der Geraden
   Vb.y = P2->y - this->y;

   if ((betrag=Vb.VBetrag()) < 1e-99)         // Betrag des Richtungsvektors
     {
      *Pf = *Ps;                                     // Standpunkt ist Fußpunkt
      return(-1.0);
     }

   Pa.x = Ps->x - this->x;
   Pa.y = Ps->y - this->y;

   t0 = (Pa.x*Vb.x + Pa.y*Vb.y) / Quadr(betrag);

   Pf->x = this->x + t0 * Vb.x;                                       // Fußpunkt
   Pf->y = this->y + t0 * Vb.y;

   return(Pf->Strecke( Ps));      // Strecke zwischen Fußpunkt und Standpunkt
  }
double sstMath01dPnt2Cls::SnitWinkl ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *P3, sstMath01dPnt2Cls *P4)
{
   sstMath01dPnt2Cls   Vb1, Vb2;
   double   b1, b2, cosi;

//...........................................2D-Schnittwinkel zweier Geraden....

   Vb1.x = P2->x - this->x;                             // Richtungen der Geraden
   Vb1.y = P2->y - this->y;

   Vb2.x = P4->x - P3->x;
   Vb2.y = P4->y - P3->y;

   b1 = Vb1.VBetrag();                                            // Beträge
   b2 = Vb2.VBetrag();
   if ((b1 < 1e-99) || (b2 < 1e-99)) return(-PI);

   cosi = (Vb1.x*Vb2.x + Vb1.y*Vb2.y) / b1 / b2;

   if (cosi >= 1.0) return(0.0);                                    // Parallel
   if (cosi <= -1.0) return(PI);                        // Gegenläufig parallel

   return(acos(cosi));                                   // Irgendwo dazwischen
  }

long sstMath01dPnt2Cls::SnitGG ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *P3, sstMath01dPnt2Cls *P4, sstMath01dPnt2Cls *Ps)
{
   double dx, dy, nenner, zahler, zn;

//.............................................Geradenschnittpunkt berechnen....

   dx = P4->x - P3->x;
   dy = P4->y - P3->y;
   if ((fabs(dx) > 1e99) || (fabs(dy) > 1e99))                  // Out of range
     {
      *Ps = *this;
      return(D2_PARALLEL);
     }

   nenner = dy * (P2->x-this->x) - dx * (P2->y-this->y);
   if (fabs(nenner) < 1e-99)                            // Parallel oder Fehler
     {                     // Viel mehr als 1e-14 gibt die Arithmetik nicht her
      *Ps = *this;
      return(D2_PARALLEL);
     }

   zahler = (P3->x-this->x) * (P2->y-this->y) - (P3->y-this->y) * (P2->x-this->x);
   if (fabs(zahler) > 1e99)                             // Parallel oder Fehler
     {
      *Ps = *this;
      return(D2_PARALLEL);
     }

   zn = zahler / nenner;
   if ((fabs(zn) < 1e-14) || (fabs(zn) > 1e14))                  // Zu unscharf
     {
      *Ps = *this;
      return(D2_PARALLEL);
     }

   Ps->x = P3->x + dx * zn;                                     // Schnittpunkt
   Ps->y = P3->y + dy * zn;

   return(D2_OK);
  }

long sstMath01dPnt2Cls::SnitGG_Unscharf ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *P3, sstMath01dPnt2Cls *P4, sstMath01dPnt2Cls *Ps)

{
   double dx, dy, nenner, zahler, zn;

//.............................................Geradenschnittpunkt berechnen....

   dx = P4->x - P3->x;
   dy = P4->y - P3->y;
   if ((fabs(dx) > 1e99) || (fabs(dy) > 1e99))                  // Out of range
     {
      *Ps = *this;
      return(D2_PARALLEL);
     }

   nenner = dy * (P2->x-this->x) - dx * (P2->y-this->y);
   if (fabs(nenner) < 1e-99)                            // Parallel oder Fehler
     {                     // Viel mehr als 1e-14 gibt die Arithmetik nicht her
      *Ps = *this;
      return(D2_PARALLEL);
     }

   zahler = (P3->x-this->x) * (P2->y-this->y) - (P3->y-this->y) * (P2->x-this->x);
   if (fabs(zahler) > 1e99)                             // Parallel oder Fehler
     {
      *Ps = *this;
      return(D2_PARALLEL);
     }

   zn = zahler / nenner;

   Ps->x = P3->x + dx * zn;                                     // Schnittpunkt
   Ps->y = P3->y + dy * zn;

   return(D2_OK);
  }

long sstMath01dPnt2Cls::SnitKG ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *Pm, double radi, sstMath01dPnt2Cls *Ps)
{
   sstMath01dPnt2Cls   Pf, Vec;
   double   tol, sfm, d;

//........................................Schnittpunkte von Kreis und Gerade....

   radi = fabs(radi);
   tol = radi * 1e-10;

   sfm = this->FusPkt( P2, Pm, &Pf);                    // Fußpunkt und Strecke

   if (sfm > (radi+tol))                        // Gerade außerhalb des Kreises
     {
      Ps[0] = Ps[1] = *Pm;
      return(D2_AUSSEN);
     }

   d = Quadr(radi) - Quadr(sfm);

   if (d <= 0.0)                       // Möglich, weil kleine Toleranz erlaubt
     {
      Ps[0] = Ps[1] = Pf;           // Schnittpunkt = Fußpunkt = Tangentenpunkt
      return(D2_OK);
     }

   Vec.x = P2->x - this->x;                               // Richtung der Geraden
   Vec.y = P2->y - this->y;

   Pf.NeuPkt( &Vec, -sqrt(d), &Ps[0]);                     // Schnittpunkte
   Pf.NeuPkt( &Vec, sqrt(d), &Ps[1]);

   return(D2_OK);
}

double sstMath01dPnt2Cls::Kreis ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *P3, sstMath01dPnt2Cls *Pm)
{
   sstMath01dPnt2Cls   P_1, P_2, P_3, P_4;
   double   s12, s13, s23, t1, t2;
   long     ss12, ss13, ss23;

//.......................................Kreismitte und Radius aus 3 Punkten....

   s12 = this->Strecke( P2);
   s13 = this->Strecke( P3);
   s23 = P2->Strecke( P3);

   if ((s12 < 1e-99) || (s13 < 1e-99) || (s23 < 1e-99)) return(-1.0);

   ss12 = ss13 = ss23 = 0;

   if ((s13 <= s12) && (s23 <= s12))                         // S12 am längsten
      ss13 = ss23 = 1;
   else if ((s12 <= s13) && (s23 <= s13))                    // S13 am längsten
      ss12 = ss23 = 1;
   else                                                      // S23 am längsten
      ss12 = ss13 = 1;

   if (ss12)                                                      // S12 ist ok
     {
      t1 = PIH + this->Riwi( P2);
      P_1.x = 0.5 * (this->x + P2->x);
      P_1.y = 0.5 * (this->y + P2->y);
     }
   if (ss13 && ss23)                                         // S13 und ss23 ok
     {
      t1 = PIH + this->Riwi( P3);
      P_1.x = 0.5 * (this->x + P3->x);
      P_1.y = 0.5 * (this->y + P3->y);
     }
   if (ss12 && ss13)                                         // S12 und ss13 ok
     {
      t2 = PIH + this->Riwi( P3);
      P_3.x = 0.5 * (this->x + P3->x);
      P_3.y = 0.5 * (this->y + P3->y);
     }
   if (ss23)                                                      // S23 ist ok
     {
      t2 = PIH + P2->Riwi( P3);
      P_3.x = 0.5 * (P2->x + P3->x);
      P_3.y = 0.5 * (P2->y + P3->y);
     }

   P_2.x = P_1.x + sin(t1);    P_4.x = P_3.x + sin(t2);
   P_2.y = P_1.y + cos(t1);    P_4.y = P_3.y + cos(t2);

   if (P_1.SnitGG( &P_2, &P_3, &P_4, Pm) == 0)          // Schnitt gefunden
      return(Pm->Strecke( this));
   else
      return(-1.0);
  }

long sstMath01dPnt2Cls::DrehMat (double kappa, double *Mat)

{
   double   si=sin(kappa), co=cos(kappa);

//....................................................2D-Drehmatrix besetzen....

   Mat[0] = co;   Mat[1] = si;                    // Wie Drehung um die Z-Achse
   Mat[2] =-si;   Mat[3] = co;

   return(D2_OK);
  }
double sstMath01dPnt2Cls::XfuerY ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *Py)
{
   double   dx, dy, lambda;

//...........................................Fehlende X-Koordinate berechnen....

   dx = P2->x - this->x;                                  // Richtung der Geraden
   dy = P2->y - this->y;

   if (fabs(dx) < 1e-99)                                   // Senkrechte Gerade
      Py->x = this->x;
   else
     {
      if (fabs(dy) < 1e-99)                               // Waagerechte Gerade
         lambda = 0.0;
      else
         lambda = (Py->y - this->y) / dy;
      Py->x = this->x + lambda * dx;
     }

   if (fabs(dx) > 1e-99)                             // Nicht senkrechte Gerade
      return(dy/dx);
   else if (dy < 0.0)                                  // Senkrechte nach unten
      return(-1e99);
   else
      return(1e99);                                     // Senkrechte nach oben
  }

double sstMath01dPnt2Cls::YfuerX ( sstMath01dPnt2Cls *P2, sstMath01dPnt2Cls *Px)
{
   double   dx, dy, lambda;

//...........................................Fehlende Y-Koordinate berechnen....

   dx = P2->x - this->x;                                  // Richtung der Geraden
   dy = P2->y - this->y;

   if (fabs(dy) < 1e-99)                                  // Waagerechte Gerade
      Px->y = this->y;
   else
     {
      if (fabs(dx) < 1e-99)                                // Senkrechte Gerade
         lambda = 0.0;
      else
         lambda = (Px->x - this->x) / dx;
      Px->y = this->y + lambda * dy;
     }

   if (fabs(dx) > 1e-99)                             // Nicht senkrechte Gerade
      return(dy/dx);
   else if (dy < 0.0)                                  // Senkrechte nach unten
      return(-1e99);
   else
      return(1e99);                                     // Senkrechte nach oben
  }
//=============================================================================
int sstMath01dPnt2Cls::PktIni ( int     Key)
//-----------------------------------------------------------------------------
{
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  this->x = 0.0;
  this->y = 0.0;

  return iRet;
 }
//==============================================================================
sstMath01dPnt3Cls sstMath01dPnt2Cls::GetD3Pnt ()
//.............................................................................
{
  sstMath01dPnt3Cls oTmpPnt;
//.............................................................................

  oTmpPnt.x = this->x;
  oTmpPnt.y = this->y;
  oTmpPnt.z = 0.0;

  return oTmpPnt;
}
//=============================================================================
int sstMath01dPnt2Cls::Set (  double  xx,       // v -> x-Coordinate
                              double  yy)       // v -> y-Coordinate
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------

  this->x = xx;
  this->y = yy;

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: Set");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Get (  double *xx,      //   <-  x-Coordinate
                              double *yy)      //   <-  y-Coordinate
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------

  *xx = this->x;
  *yy = this->y;

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: Get");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Pytha_Hypo ( int   Key,        // v  -> Vorerst immer 0
                        double  Ankath,     // v  -> Ankathete
                        double  Gegenkath,  // v  -> Gegenkathete
                        double *Hypo)       //   <-  Hypothenuse
//.............................................................................
{
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;
  *Hypo = Ankath*Ankath+Gegenkath*Gegenkath;
  *Hypo = sqrt(*Hypo);
  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Pytha_Kath ( int   Key,      // v  -> Vorerst immer 0
                       double  Kath1,    // v  -> Kathete1
                       double  Hypo,     // v  -> Hypothenuse
                       double *Kath2)    //   <-  Kathete2
//.............................................................................
{
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;
  *Kath2 = Hypo * Hypo - Kath1 * Kath1;
  *Kath2 = sqrt(*Kath2);
  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Kart_Abs ( int   Key,  // v  -> Vorerst immer 0
                     double *Wink, //   <-  Berechneter Winkel
                     double *Dist) //   <-  Berechnete Distanz
//.............................................................................
{
  int iRet;
  int iStat;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  // Im rechtwinkeligen Dreieck aus Katheten Hypothenuse berechnen
  iStat = Pytha_Hypo ( 0, this->x, this->y, Dist);

  if (*Dist <= 0.0 || iStat < 0)
  {
    iRet = -1;
    *Dist = 0.0;
    *Wink = 0.0;
  }
  else
  {

    if (this->x >= 0)
      if (this->y >= 0)
      { *Wink = acos(  this->x / *Dist);        /* Erster Quadrant */
      }
      else
      { *Wink = acos( -this->y / *Dist);       /* Vierter Quadrant */
        *Wink = *Wink + PI + PIH;
      }
    else
      if ( this->y >= 0)
      { *Wink = acos(  this->y / *Dist);       /* Zweiter Quadrant */
        *Wink = *Wink + PIH;
      }
      else
      { *Wink = acos( -this->x / *Dist);      /* Dritter Quadrant */
        *Wink = *Wink + PI;
      }
  }
  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Kart_Rel ( int   Key,   // v  -> Vorerst immer 0
                     sstMath01dPnt2Cls *Pkt2,  //    -> Differenzpunkt
                     double *Wink,  //   <-  Berechneter Winkel
                     double *Dist)  //   <-  Berechnete Distanz
//.............................................................................
{
  sstMath01dPnt2Cls LocPkt;  //  Kleinpunkt
  int  iRet;
  int  iStat;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  LocPkt.x = Pkt2->x - this->x;
  LocPkt.y = Pkt2->y - this->y;

  // Kartesische Koordinaten in Polarkoordinaten umformen
  iStat = LocPkt.Kart_Abs ( Key, Wink, Dist);

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Polar_Abs ( int   Key,    // v  -> Vorerst immer 0
                      double  Winkel, // v  -> Winkel -math/rad-
                      double  Dist,   // v  -> Strecke
                      sstMath01dPnt2Cls *Pkt)    //   <-  Neuer Punkt
//.............................................................................
{
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  Pkt->x = Dist * cos(Winkel);
  Pkt->y = Dist * sin(Winkel);

  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::Polar_Rel ( int   Key,     // v  -> Vorerst immer 0
                      double  Winkel, // v  -> Winkel -math/rad-
                      double  Dist,   // v  -> Strecke
                      sstMath01dPnt2Cls *NeuPkt) //   <-  Neuer Punkt
//.............................................................................
{
  int iRet;
  int iStat;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  // Aus Winkel und Strecke absolute Koordinaten rechnen
  iStat = Polar_Abs ( Key, Winkel, Dist, NeuPkt);

  NeuPkt->x = NeuPkt->x + this->x;
  NeuPkt->y = NeuPkt->y + this->y;

  // Fatal Errors goes to an assert
  assert(iRet >= 0);

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt2Cls::sstMat_PktIdent ( int      iKey,   // v  -> Vorerst immer 0
                      sstMath01dPnt2Cls  *Pkt2,   //    -> Geometriepunkt 2
                      double   dTol)   // v  -> Vorzugebende Toleranzdistanz
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  double dDist = this->Strecke  (  Pkt2 );
  if (dDist <= dTol)
    iStat = 1;
  else
    iStat = 0;

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
double sstMath01dPnt3Cls::VBetrag ()
{
//...........................................................3D-Vektorbetrag....

   return(sqrt(Quadr(this->x)+Quadr(this->y)+Quadr(this->z)));
}

double sstMath01dPnt3Cls::Strecke ( sstMath01dPnt3Cls *P2)
{
//...............................................................Raumstrecke....

   return(sqrt(Quadr(P2->x - this->x)+Quadr(P2->y - this->y)+Quadr(P2->z - this->z)));
}
//=============================================================================
double sstMath01dPnt3Cls::Strecke2 (int iKey, sstMath01dPnt3Cls *P2)
//-----------------------------------------------------------------------------
{
  if ( iKey <= 0|| iKey > 1) return -1.0;

  if (iKey == 0)
  {
    return(sqrt(Quadr(P2->x - this->x)+Quadr(P2->y - this->y)+Quadr(P2->z - this->z)));
  }
  else
  {
    return(sqrt(Quadr(P2->x - this->x)+Quadr(P2->y - this->y)));
  }

}
double sstMath01dPnt3Cls::VekNorm ()
{
   double   betrag;

//....................................3D-Vektor auf die Lnge 1.0 normierten....

   if ((betrag=this->VBetrag()) < 1e-99) return(0.0);

   this->x /= betrag;
   this->y /= betrag;
   this->z /= betrag;

   return(betrag);
}
double sstMath01dPnt3Cls::VekProdukt ( sstMath01dPnt3Cls *V2, sstMath01dPnt3Cls *Vprd)
{
//.............................................................Vektorprodukt....

   Vprd->x = this->y * V2->z - this->z * V2->y;
   Vprd->y = this->z * V2->x - this->x * V2->z;
   Vprd->z = this->x * V2->y - this->y * V2->x;

   return(Vprd->VBetrag());
  }
double sstMath01dPnt3Cls::NeuPkt ( sstMath01dPnt3Cls *Vec, double cc, sstMath01dPnt3Cls *Pn)
{
   sstMath01dPnt3Cls   Vn=*Vec;
   double   betrag;

//...............................................................3D-Neupunkt....

   betrag = Vn.VekNorm();

   Pn->x = this->x + cc * Vn.x;                     // In Richtung Normalenvektor
   Pn->y = this->y + cc * Vn.y;
   Pn->z = this->z + cc * Vn.z;

   return(betrag);
}

double sstMath01dPnt3Cls::NeuPkt2 ( sstMath01dPnt3Cls *P2, double cc, sstMath01dPnt3Cls *Pn)
{
   sstMath01dPnt3Cls   Vec;

//.....................................................3D-Neupunkt berechnen....

   Vec.x = P2->x - this->x;
   Vec.y = P2->y - this->y;
   Vec.z = P2->z - this->z;

   return(this->NeuPkt( &Vec, cc, Pn));
  }

double sstMath01dPnt3Cls::FusPkt ( sstMath01dPnt3Cls *P2, sstMath01dPnt3Cls *Ps, sstMath01dPnt3Cls *Pf)
{
   sstMath01dPnt3Cls   Vg, Va;
   double   betrag, t0;

//...............................................................3D-Fußpunkt....

   Vg.x = P2->x - this->x;                                // Richtung der Geraden
   Vg.y = P2->y - this->y;
   Vg.z = P2->z - this->z;

   if ((betrag=Vg.VBetrag()) < 1e-99)         // Betrag des Richtungsvektors
     {
      *Pf = *Ps;                                     // Standpunkt ist Fußpunkt
      return(-1.0);
     }

   Va.x = Ps->x - this->x;
   Va.y = Ps->y - this->y;
   Va.z = Ps->z - this->z;

   t0 = (Va.x*Vg.x + Va.y*Vg.y + Va.z*Vg.z) / Quadr(betrag);

   Pf->x = this->x + t0 * Vg.x;                                       // Fußpunkt
   Pf->y = this->y + t0 * Vg.y;
   Pf->z = this->z + t0 * Vg.z;

   return(Pf->Strecke( Ps));      // Strecke zwischen Fußpunkt und Standpunkt
}
double sstMath01dPnt3Cls::RtgDif ( sstMath01dPnt3Cls *P2, sstMath01dPnt3Cls *P3, sstMath01dPnt3Cls *P4)
{
   sstMath01dPnt3Cls   Vg1, Vg2;
   double   b1, b2, cosi;

//.....................................Richtungsdifferenz zweier Raumgeraden....

   Vg1.x = P2->x - this->x;                             // Richtungen der Geraden
   Vg1.y = P2->y - this->y;
   Vg1.z = P2->z - this->z;

   Vg2.x = P4->x - P3->x;
   Vg2.y = P4->y - P3->y;
   Vg2.z = P4->z - P3->z;

   b1 = Vg1.VBetrag();                                            // Beträge
   b2 = Vg2.VBetrag();
   if ((b1 < 1e-99) || (b2 < 1e-99)) return(-PI);

   cosi = (Vg1.x*Vg2.x + Vg1.y*Vg2.y + Vg1.z*Vg2.z) / b1 / b2;

   if (cosi >= 1.0) return(0.0);                                    // Parallel
   if (cosi <= -1.0) return(PI);                        // Gegenläufig parallel

   return(acos(cosi));                                   // Irgendwo dazwischen
  }
long sstMath01dPnt3Cls::DrehMat (double omega, double phi, double kappa, double *Mat)
{
   double   sio=sin(omega), coo=cos(omega);
   double   sip=sin(phi), cop=cos(phi);
   double   sik=sin(kappa), cok=cos(kappa);

//....................................................3D-Drehmatrix besetzen....

   Mat[0] =  cop * cok;
   Mat[1] = -cop * sik;
   Mat[2] =  sip;
   Mat[3] =  coo * sik + sio * sip * cok;
   Mat[4] =  coo * cok - sio * sip * sik;
   Mat[5] = -sio * cop;
   Mat[6] =  sio * sik - coo * sip * cok;
   Mat[7] =  sio * cok + coo * sip * sik;
   Mat[8] =  coo * cop;

   return(D3_OK);
}
long sstMath01dPnt3Cls::Transf (double *Dmat)
{
   sstMath01dPnt3Cls   Ve=*this;

//....................................Punkt mit 3D-Drehmatrix transformieren....

   this->x = Ve.x * Dmat[0] + Ve.y * Dmat[3] + Ve.z * Dmat[6];
   this->y = Ve.x * Dmat[1] + Ve.y * Dmat[4] + Ve.z * Dmat[7];
   this->z = Ve.x * Dmat[2] + Ve.y * Dmat[5] + Ve.z * Dmat[8];

   return(D3_OK);
}
double sstMath01dPnt3Cls::EbenePV ( sstMath01dPnt3Cls *Vec, sstMath01Plane *Eb)
{
   sstMath01dPnt3Cls   Vn=*Vec;
   double   betrag;

//.................................Ebene in HNF aus Punkt und Normalenvektor....

   betrag = Vn.VekNorm();                          // Normaleneinheitsvektor

   Eb->d = this->x * Vn.x + this->y * Vn.y + this->z * Vn.z;

   if (Eb->d < 0.0)                                             // Weil k  0.0
     {
      Eb->d = -Eb->d;
      Eb->a = -Vn.x;
      Eb->b = -Vn.y;
      Eb->c = -Vn.z;
     }
   else
     {
      Eb->a = Vn.x;
      Eb->b = Vn.y;
      Eb->c = Vn.z;
     }

   return(betrag);
  }
double sstMath01dPnt3Cls::EbeneP3 ( sstMath01dPnt3Cls *P2, sstMath01dPnt3Cls *P3, sstMath01Plane *Eb)
{
   sstMath01dPnt3Cls   V1, V2, Vprd;

//................................................Ebene in HNF aus 3 Punkten....

   V1.x = P2->x - this->x;                              // Zwei Richtungsvektoren
   V1.y = P2->y - this->y;
   V1.z = P2->z - this->z;

   V2.x = P3->x - this->x;
   V2.y = P3->y - this->y;
   V2.z = P3->z - this->z;

   if (V1.VekProdukt( &V2, &Vprd) < 1e-99) return(-1.0);  // Auf e. Geraden

   return(this->EbenePV( &Vprd, Eb));
  }
double sstMath01dPnt3Cls::AbstPG ( sstMath01dPnt3Cls *P2, sstMath01dPnt3Cls *Ps)
{
   sstMath01dPnt3Cls   Vb, Va, Vprd;
   double   betrag;

//......................................Abstand von Punkt und Gerade im Raum....

   Vb.x = P2->x - this->x;                                // Richtung der Geraden
   Vb.y = P2->y - this->y;
   Vb.z = P2->z - this->z;

   Va.x = Ps->x - this->x;
   Va.y = Ps->y - this->y;
   Va.z = Ps->z - this->z;

   if ((betrag=Vb.VBetrag()) < 1e-99) return(-1.0);

   return(Va.VekProdukt( &Vb, &Vprd) / betrag);
  }

double sstMath01dPnt3Cls::AbstPE ( sstMath01Plane *Eb)
{
//.....................................Abstand eines Punktes von einer Ebene....

   return(this->x * Eb->a + this->y * Eb->b + this->z * Eb->c - Eb->d);
}
double sstMath01dPnt3Cls::FusPktE ( sstMath01Plane *Eb, sstMath01dPnt3Cls *Pf)
{
   sstMath01dPnt3Cls   Vn;
   double   betrag, s0;

//................................................3D-Fußpunkt auf eine Ebene....

   Vn.x = Eb->a;                                    // Normalenvektor der Ebene
   Vn.y = Eb->b;
   Vn.z = Eb->c;

   if ((betrag = Vn.VBetrag()) < 1e-99)          // Betrag des Normalenvektors
     {
      *Pf = *this;                                     // Standpunkt ist Fußpunkt
      return(-1.0);
     }

   s0 = (Eb->d - (this->x*Vn.x + this->y*Vn.y + this->z*Vn.z)) / Quadr(betrag);

   Pf->x = this->x + s0 * Vn.x;                                       // Fußpunkt
   Pf->y = this->y + s0 * Vn.y;
   Pf->z = this->z + s0 * Vn.z;

   return(Pf->Strecke(this));      // Strecke zwischen Fußpunkt und Standpunkt
  }
 double sstMath01dPnt3Cls::SnitWklEE (sstMath01Plane *E1, sstMath01Plane *E2)

{
   sstMath01dPnt3Cls   Vn1, Vn2;
   double   b1, b2, cosi;

//.............................................Ebenenschnittwinkel berechnen....

   Vn1.x = E1->a;                                // Normalenvektoren der Ebenen
   Vn1.y = E1->b;
   Vn1.z = E1->c;

   Vn2.x = E2->a;
   Vn2.y = E2->b;
   Vn2.z = E2->c;

   b1 = Vn1.VBetrag();                                            // Beträge
   b2 = Vn2.VBetrag();
   if ((b1 < 1e-99) || (b2 < 1e-99)) return(-PI);

   cosi = (Vn1.x*Vn2.x + Vn1.y*Vn2.y + Vn1.z*Vn2.z) / b1 / b2;

   if (cosi >= 1.0) return(0.0);                                    // Parallel
   if (cosi <= -1.0) return(PI);                        // Gegenläufig parallel

   return(acos(cosi));                                   // Irgendwo dazwischen
  }

long sstMath01dPnt3Cls::AbbildGE (sstMath01Plane *Eb, sstMath01dPnt3Cls *P1, sstMath01dPnt3Cls *P2)
{
   sstMath01dPnt3Cls   Vn, Vg, Vprd, Pf1, Pf2;

//...................................Projektion einer Geraden auf eine Ebene....

   Vn.x = Eb->a;                                    // Normalenvektor der Ebene
   Vn.y = Eb->b;
   Vn.z = Eb->c;

   Vg.x = P2->x - P1->x;                 // Differenzvektor ist Richtungsvektor
   Vg.y = P2->y - P1->y;
   Vg.z = P2->z - P1->z;

   if (Vn.VekProdukt( &Vg, &Vprd) < 1e-99) return(D3_SENKR);    // Parallel

   P1->FusPktE( Eb, &Pf1);           // Die Fußpunkte ergeben die neue Gerade
   P2->FusPktE( Eb, &Pf2);
   *P1 = Pf1;
   *P2 = Pf2;

   return(D3_OK);
}
long sstMath01dPnt3Cls::SnitGE (sstMath01dPnt3Cls *P2, sstMath01Plane *Eb, sstMath01dPnt3Cls *Pd)
{
   sstMath01dPnt3Cls   Vg;
   double   an, bn, t0;

//......................................................Schnitt Gerade-Ebene....

   Vg.x = P2->x - this->x;                 // Differenzvektor ist Richtungsvektor
   Vg.y = P2->y - this->y;
   Vg.z = P2->z - this->z;

   an = this->x * Eb->a + this->y * Eb->b + this->z * Eb->c;
   bn = Vg.x * Eb->a + Vg.y * Eb->b + Vg.z * Eb->c;

   if (fabs(bn) < 1e-99) return(D3_PARALLEL);                         // Fehler

   t0 = (Eb->d - an) / bn;

   Pd->x = this->x + t0 * Vg.x;                                 // Durchstoßpunkt
   Pd->y = this->y + t0 * Vg.y;
   Pd->z = this->z + t0 * Vg.z;

   return(D3_OK);
}
long sstMath01dPnt3Cls::SnitEE (sstMath01Plane *E1, sstMath01Plane *E2, sstMath01dPnt3Cls *Pg, sstMath01dPnt3Cls *Vg)
{
   sstMath01dPnt3Cls   Vn1, Vn2, P0;
   sstMath01dPnt3Cls   tmpPnt;

//.....................................Schnittgerade zweier Ebenen berechnen....

   Vn1.x = E1->a;                                // Normalenvektoren der Ebenen
   Vn1.y = E1->b;
   Vn1.z = E1->c;

   Vn2.x = E2->a;
   Vn2.y = E2->b;
   Vn2.z = E2->c;

   if (Vn1.VekProdukt( &Vn2, Vg) < 1e-99) return(D3_PARALLEL);  // Parallel

   P0.x = P0.y = P0.z = 0.0;         // Irgend ein Punkt - Null ist praktischer

   tmpPnt.AbbildGE(E1, &P0, &Vn2);  // Normalenvektor von <E2> auf <E1> projizieren

   return(P0.SnitGE( &Vn2, E2, Pg));        // Schnitt liefert Geradenpunkt
  }
long sstMath01dPnt3Cls::ReduP3_P2 ( sstMath01dPnt3Cls *Vec, sstMath01dPnt3Cls *Pd, sstMath01dPnt2Cls *Pb)
{
   sstMath01dPnt3Cls   Pr;

//..........................................3D-Punkt auf 2D-Punkt reduzieren....

   Pr.x = Pd->x - this->x;                             // Auf Ursprung reduzieren
   Pr.y = Pd->y - this->y;
   Pr.z = Pd->z - this->z;

   Pb->x = Pr.x * Vec[0].x + Pr.y * Vec[0].y + Pr.z * Vec[0].z;
   Pb->y = Pr.x * Vec[1].x + Pr.y * Vec[1].y + Pr.z * Vec[1].z;

   return(D3_OK);
}
int sstMath01dPnt3Cls::PktIni ( int     Key)
{
  int iRet;
//.............................................................................
  if (Key != 0) return -1;
  iRet = 0;
  // iStat = 0;

  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;

  return iRet;
 }
//=============================================================================
int sstMath01dPnt3Cls::Set ( double  xx,       // v -> x-Coordinate
                double  yy,       // v -> y-Coordinate
                double  zz)       // v -> z-Coordinate
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  // if ( iKey != 0) return -1;

  this->x = xx;
  this->y = yy;
  this->z = zz;

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: Set");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt3Cls::Get (int     iKey,    // v  -> For the moment 0
                double *xx,      //   <-  x-Coordinate
                double *yy,      //   <-  y-Coordinate
                double *zz)      //   <-  z-Coordinate
//-----------------------------------------------------------------------------
{
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  *xx = this->x;
  *yy = this->y;
  *zz = this->z;

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: Get");
  }

  // Small Errors will given back
  iRet = iStat;

  return iRet;
}
//=============================================================================
int sstMath01dPnt3Cls::CalcDistLimit ( int    iKey,        // v  -> For the moment 0
                       sstMath01dPnt3Cls  *Pnt2,        // Pnt 2
                       double   GivenLimit,  // Given Limit Distance
                       double  *CalcDist)    // Calulated Distance
//-----------------------------------------------------------------------------
{
  sstMath01dPnt2Cls  D2Pnt1;   // Pnt 1
  sstMath01dPnt2Cls  D2Pnt2;   // Pnt 2
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  D2Pnt1 = this->GetD2Pnt ();
  D2Pnt2 = Pnt2->GetD2Pnt ();

      *CalcDist = D2Pnt1.Strecke ( &D2Pnt2);
      if (*CalcDist <= GivenLimit)
      {
        // Treffer!!
        iStat = 1;
      }
      else
      {
        iStat = 0;
        // *CalcDist = 0.0;

      }

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
int sstMath01dPnt3Cls::SnitGG (int iKey,
                                  sstMath01dPnt3Cls *P2,
                                  sstMath01dPnt3Cls *P3,
                                  sstMath01dPnt3Cls *P4,
                                  sstMath01dPnt3Cls *Ps)
//-----------------------------------------------------------------------------
{
  sstMath01dPnt3Cls KleinPkt;
  sstMath01Plane eb;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // Sind zwei 3D-Punkte innerhalb Toleranz 1 cm identisch ?
  iStat = this->PktIdent3D ( 1, P2, 0.01);
  if (iStat == 1) return -2;
  iStat = P3->PktIdent3D ( 1, P4, 0.01);
  if (iStat == 1) return -3;
  if (iKey == 0)
  {
  // Kleinpunkt, der oberhalb der Geraden liegt
    KleinPkt.x = (P3->x + P4->x)/2.0;
    KleinPkt.y = (P3->y + P4->y)/2.0;
    KleinPkt.z = (P3->z + P4->z)+10.0;
    // Senkrecht stehende Ebene aus P3 und P4 bilden
    double dRet = P3->EbeneP3  (  P4, &KleinPkt, &eb);
    if (dRet == -1) return -4;

    // Schnittpunkt Raumgerade und Ebene
    long lRet = this->SnitGE  ( P2, &eb, Ps);
    if (lRet == D3_PARALLEL)
      return -5;
    else
      iStat = 1;
  }
  else
  {
  // Kleinpunkt, der oberhalb der Geraden liegt
    KleinPkt.x = (this->x + P2->x)/2.0;
    KleinPkt.y = (this->y + P2->y)/2.0;
    KleinPkt.z = (this->z + P2->z)+10.0;
    // Senkrecht stehende Ebene aus P3 und P4 bilden
    double dRet = this->EbeneP3  (  P2, &KleinPkt, &eb);
    if (dRet == -1) return -4;

    // Schnittpunkt Raumgerade und Ebene
    long lRet = P3->SnitGE  ( P4, &eb, Ps);
    if (lRet == D3_PARALLEL)
      return -5;
    else
      iStat = 1;
  }



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
double sstMath01dPnt3Cls::RiWi (int         iKey,
                sstMath01dPnt3Cls *Pnt2)

//-----------------------------------------------------------------------------
{
  sstMath01dPnt2Cls D2Pkt1;
  sstMath01dPnt2Cls D2Pkt2;

  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey != 0) return -1;

  // D3-Punkt in D2-Punkt reduzieren.
  D2Pkt1 = this->GetD2Pnt ();
  D2Pkt2 = Pnt2->GetD2Pnt ();

  // Richtungswinkel berechnen
  double dRiWiAnschluss = D2Pkt1.Riwi  ( &D2Pkt2);

  // Heavy Errors goes to an assert
  if (iRet < 0)
  {
    // Expression (iRet >= 0) has to be fullfilled
    assert("Error in function: xxx");
  }

  // Small Errors will given back
  iRet = iStat;

  return dRiWiAnschluss;
}
//=============================================================================
int sstMath01dPnt3Cls::CoorTrans(int         iKey,
                 double      dScal,
                 double      dMov)
{
  if ( iKey != 0) return -1;

  this->x = this->x * dScal;
  this->y = this->y * dScal;
  this->z = this->z * dScal;

  this->x = this->x + dMov;
  this->y = this->y + dMov;
  this->z = this->z + dMov;

  return 0;
}
//=============================================================================
int sstMath01dPnt3Cls::CoorXTrans(int         iKey,
                 double      dScal,
                 double      dMovX,
                 double      dMovY)
{
  if ( iKey != 0) return -1;

  this->x = this->x + dMovX;
  this->y = this->y + dMovY;
  // dPnt->z = dPnt->z + dMov;

  this->x = this->x * dScal;
  this->y = this->y * dScal;
  this->z = this->z * dScal;

  return 0;
}
//=============================================================================
int sstMath01dPnt3Cls::PktIdent3D ( int      iKey,   // v  -> 0 oder 1
                        sstMath01dPnt3Cls  *Pkt2,   //    -> Geometriepunkt 2
                        double   dTol)   // v  -> Vorzugebende Toleranzdistanz
//-----------------------------------------------------------------------------
{
  sstMath01dPnt2Cls d2Pkt1;
  sstMath01dPnt2Cls d2Pkt2;
  double dDist;
  int iRet  = 0;
  int iStat = 0;
//-----------------------------------------------------------------------------
  if ( iKey < 0 || iKey > 1) return -1;


  switch (iKey)
  {
    case 0:

      // D3-Punkt in D2-Punkt reduzieren.
    d2Pkt1 = this->GetD2Pnt ();
    d2Pkt2 = Pkt2->GetD2Pnt ();

      dDist = d2Pkt1.Strecke  ( &d2Pkt2);
      break;
    case 1:
      dDist = this->Strecke  (  Pkt2 );
       break;
    default:
       dDist = 0.0;
       break;
  }


  if (dDist <= dTol)
    iStat = 1;
  else
    iStat = 0;

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
//==============================================================================
sstMath01dPnt2Cls sstMath01dPnt3Cls::GetD2Pnt ()
//.............................................................................
{
  // int iRet;
  sstMath01dPnt2Cls D2Pkt;
//.............................................................................
  // if (Key != 0) return -1;
  // iRet = 0;
  // iStat = 0;
  D2Pkt.x = this->x;
  D2Pkt.y = this->y;

  return D2Pkt;
}
//=============================================================================
sstMath01Plane::sstMath01Plane()
{
  a = 0;
  b = 0;
  c = 0;
  d = 0;
}
//=============================================================================
