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
//
// Datastructures and Prototypes for system "sstMath01Lib"
//

#ifndef   _SST_MATH01_LIB_HEADER
#define   _SST_MATH01_LIB_HEADER



/**
 * @defgroup sstMath01Lib sstMath01Lib: sst Math lib (Version 1)
 * cpp math functions and classes for sst
 */

// Defines ---------------------------------------------------------------------

/**
 *  Makros für x^n
 *
 *  Hier sind Makros für x^2 und x^3 definiert. Wenn weitere Makros für x^n
 *  folgen, sollten sie hier definiert werden.
*/
#define Quadr(x)   ((x)*(x))            /** x^2     @ingroup sstMath01Lib */
#define Kubic(x)   ((x)*(x)*(x))        /** x^3     @ingroup sstMath01Lib */

// Forward declarations --------------------------------------------------------
class sstMath01dPnt3Cls;
class sstMath01Plane;

// Structures and Classes ------------------------------------------------------

//==============================================================================
/**
* @brief 2D integer point
*
* Changed: 06.01.17  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 06.01.17
*/
// ----------------------------------------------------------------------------
class sstMath01iPnt2Cls
{
  public:   // Public functions
     sstMath01iPnt2Cls();  // Constructor
// ----------------------------------------------------------------------------
     int   x;                  /**< Integer Point coordinates */
     int   y;                  /**< Integer Point coordinates */
  private:  // Private functions
};
//==============================================================================
/**
* @brief 3D unsigned long integer point
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMath01ulPnt3Cls
{
  public:   // Public functions
     sstMath01ulPnt3Cls();  // Constructor
// ----------------------------------------------------------------------------
     unsigned long   x;        /**< Unsigned long integer coordinates */
     unsigned long   y;        /**< Unsigned long integer coordinates */
     unsigned long   z;        /**< Unsigned long integer coordinates */
  private:  // Private functions
};
//==============================================================================
/**
* @brief 2D float point
*
* Changed: 06.01.17  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 06.01.17
*/
// ----------------------------------------------------------------------------
class sstMath01fPnt2Cls
{
  public:   // Public functions
     sstMath01fPnt2Cls();  // Constructor
// ----------------------------------------------------------------------------
     float   x;               /**< Punktkoordinaten */
     float   y;               /**< Punktkoordinaten */
  private:  // Private functions
};
//=============================================================================
/**
* @brief 2D double Point
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMath01dPnt2Cls
{
  public:   // Public functions
     sstMath01dPnt2Cls();  // Constructor
     //=============================================================================
     /**
     ***********************************************************************************************
     * @brief 2D-Vektorbetrag
     *
     * "VBetrag" berechnet den Vektorbetrag von vec.
     *
     * @return double
     *
     * @retval = Vektorbetrag
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double VBetrag ();
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Strecke
     *
     * "Strecke" berechnet die Strecke zwischen p1 und p2.
     *
     * @param p2 : [In]    Streckenende
     *
     * @return double
     *
     * @retval = Strecke zwischen p1 und p2
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double Strecke ( sstMath01dPnt2Cls* p2);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief Richtungswinkel in rad
     *
     * "Riwi" berechnet den Richtungswinkel (rad) einer durch zwei Punkte
     * gegebenen Geraden (von Punkt 1 nach Punkt 2) bzgl. der mathematischen
     * Y-Achse. Sind beide Punkte identisch, so ist der Returnwert 0.0.
     * Drehrichtung im Uhrzeigersinn. Null ist Nord.
     *
     * @param p2 : [In]    Endpunkt der Geraden
     *
     * @return double
     *
     * @retval = Richtungswinkel (von 0 bis 2*PI) der gegebenen Geraden
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double Riwi ( sstMath01dPnt2Cls* p2);

    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Vektor auf Länge 1.0 normieren
     *
     * "VekNorm" normiert den 2D-Vektor vec auf die Länge 1.0. Ist der
     * Vektorbetrag kleiner 1e-99, so wird der Vektor nicht normiert.
     *
     * @return double
     *
     * @retval = Vektorbetrag, 0.0 wenn Vektorbetrag kleiner 1e-99
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double VekNorm ();
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Neupunkt berechnen
     *
     * "NeuPkt" berechnet einen 2D-Punkt mit dem Abstand cc von ps auf
     * dem Vektor vec. Der Neupunkt liegt dann cc entfernt vom Punkt ps
     * in Richtung des Vektors vec (wenn cc negativ, dann Gegenrichtung).
     * Vektorbetrag kleiner 1e-99, so wird der Vektor nicht normiert und
     * das Ergebnis pn ist falsch.
     *
     * @param vec : [In]    Vektor für Blickrichtung (muß nicht normiert sein)
     * @param cc : [In]     Abstand des Neupunktes vom Standpunkt in Richtung vec
     * @param pn : [Out]    Neuer Punkt
     *
     * @return double
     *
     * @retval = Betrag des Richtungsvektors vec
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double NeuPkt ( sstMath01dPnt2Cls* vec, double cc, sstMath01dPnt2Cls* pn);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Neupunkt berechnen
     *
     * "NeuPkt2" berechnet einen 2D-Punkt mit dem Abstand cc von p1 in
     * Richtung p2 auf der durch p1 und p2 definierten Geraden.
     * Der Neupunkt liegt dann cc entfernt vom Punkt p1 in Richtung p2
     * (wenn cc negativ, dann Gegenrichtung).
     * Ist die Strecke zwischen p1 und p2 kleiner 1e-99, so wird der
     * Richtungsvektor nicht bestimmt und das Ergebnis pn ist falsch.
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
     * @param cc : [In]     Abstand des Neupunktes von p1 in Richtung p2
     * @param pn : [Out]    Neuer Punkt
     *
     * @return double
     *
     * @retval = Betrag der Strecke zwischen p1 und p2
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double NeuPkt2 (sstMath01dPnt2Cls* p2, double cc, sstMath01dPnt2Cls* pn);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Fußpunkt auf Gerade
     *
     * "FusPkt" berechnet den 2D-Fußpunkt des Lotes von ps auf die durch
     * p1 und p2 definierte Gerade und den Abstand des Punktes ps von
     * der Geraden. Siehe auch Rep. der Ingenieur-Mathematik S.94.
     * Ist die Strecke zwischen p1 und p2 kleiner 1e-99, so wird von
     * identischen Punkten ausgegangen. Der Returnwert ist dann -1.0.
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
     * @param ps : [In]     Standpunkt
     * @param pf : [Out]    Fußpunkt (bei Fehler Standpunkt)
     *
     * @return double
     *
     * @retval = Abstand von ps zur Geraden (bei Fehler immer -1.0)
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double FusPkt ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* ps, sstMath01dPnt2Cls* pf);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Schnittwinkel zweier Geraden
     *
     * "SnitWinkl" berechnet den Schnittwinkel zweier Geraden. Sind die
     * Geraden parallel, so ist der Schnittwinkel 0.0, sind die Geraden gegen-
     * läufig parallel, so ist der Schnittwinkel PI. Der Schnittwinkel ist
     * immer positiv. Siehe auch Rep. der Ingenieur-Mathematik S.87.
     * Bei Fehler (Strecke zwischen p1 und p2 bzw. Strecke zwischen p3
     * und p4 kleiner 1e-99) ist der Returnwert -PI.
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der ersten Geraden
     * @param p3 : [In]     Erster Punkt zur definition der zweiten Geraden
     * @param p4 : [In]     Zweiter Punkt zur definition der zweiten Geraden
     *
     * @return double
     *
     * @retval = Schnittwinkel in rad, bei Fehler -PI
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double SnitWinkl ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* p3, sstMath01dPnt2Cls* p4);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Schnittpunkt zweier Geraden
     *
     * "SnitGG" berechnet den Schnittpunkt zweier Geraden. Sind die Geraden
     * parallel, so ist der Schnittpunkt gleich p1. Wird ein Faktor größer
     * 1e99 bzw. kleiner 1e-99, so werden die Berechnungen abgebrochen.
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der ersten Geraden
     * @param p3 : [In]     Erster Punkt zur definition der zweiten Geraden
     * @param p4 : [In]     Zweiter Punkt zur definition der zweiten Geraden
     * @param ps : [Out]    Schnittpunkt (bei Fehler p1)
     *
     * @return long int
     *
     * @retval = D2_OK
     * @retval = D2_PARALLEL
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    long SnitGG ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* p3, sstMath01dPnt2Cls* p4, sstMath01dPnt2Cls* ps);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Schnittpunkt zweier Geraden
     *
     * "SnitGG_Unscharf" berechnet den Schnittpunkt zweier Geraden wie
     * "SnitGG": Sind die Geraden parallel, so ist der Schnittpunkt
     * gleich p1. Wird ein Faktor größer 1e99 bzw. kleiner 1e-99, so werden
     * die Berechnungen abgebrochen.
     * Im Unterschied zu "SnitGG" findet keine Überprüfung statt, ob das
     * Ergebnis unscharf ist.
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der ersten Geraden
     * @param p3 : [In]     Erster Punkt zur definition der zweiten Geraden
     * @param p4 : [In]     Zweiter Punkt zur definition der zweiten Geraden
     * @param ps : [Out]    Schnittpunkt (bei Fehler p1)
     *
     * @return long int
     *
     * @retval = D2_OK
     * @retval = D2_PARALLEL
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    long SnitGG_Unscharf ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* p3, sstMath01dPnt2Cls* p4, sstMath01dPnt2Cls* ps);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief Schnittpunkte von Kreis und Gerade
     *
     * "SnitKG" berechnet die Schnittpunkte von Kreis und Gerade. Der
     * Differenzvektor der Schnittpunkte hat die gleiche Richtung wie der
     * Differenzvektor der gegebenen Geradenpunkte p1 und p2.
     * Gibt es keinen Schnittpunkt, so sind ps[0] und ps[1] gleich pm.
     * Läuft die Gerade nur 1e-10 * radi am Kreis vorbei, so ist sie noch
     * eine Tangente und ps[0] gleich ps[1].
     *
     * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
     * @param  pm: [In]     Kreismittelpunkt
     * @param  radi: [In]   Kreisradius
     * @param  ps: [Out]    2 Schnittpunkte (bei Fehler pm)
     *
     * @return long int
     *
     * @retval = D2_OK
     * @retval = D2_AUSSEN
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    long SnitKG ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* pm, double radi, sstMath01dPnt2Cls* ps);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief Kreismitte und Radius aus 3 Punkten
     *
     * "Kreis" berechnet aus 3 gegebenen Punkten den Mittelpunkt und den
     * Radius eines Kreises auf dem alle 3 Punkte liegen. Der Mittelpunkt ist
     * der Schnitt der Mittelsenkrechten. Bei Fehler ist pm nicht
     * definiert.
     *
     * @param p2 : [In]     Zweiter Kreispunkt
     * @param p3 : [In]     Dritter Kreispunkt
     * @param pm : [Out]    Kreismittelpunkt
     *
     * @return double
     *
     * @retval = Kreisradius, -1.0 bei Fehler
     *
     * @author Re,
     *
     *************************************************************************************************
    */
    double Kreis ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* p3, sstMath01dPnt2Cls* pm);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief 2D-Drehmatrix besetzen
     *
     * "DrehMat" besetzt die Drehmatrix für den Drehwinkel kappa. Die
     * Drehung erfolgt im Uhrzeigersinn. Die Matrix mit den 4 Elementen wird
     * folgendermaßen besetzt:
     *                          cos(æ)   sin(æ)
     *                         -sin(æ)   cos(æ)
     *
     * @param kappa : [In]  Drehwinkel in rad von der Y-Achse ausgehend im Uhrzeigersinn
     * @param mat : [Out]   Drehmatrix
     *
     * @return long int
     *
     * @retval = D2_OK (immer)
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    long DrehMat (double kappa, double* mat);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief Fehlende X-Koordinate berechnen
     *
     * "XfuerY" berechnet die fehlende X-Koordinate für den Punkt py,
     * der auf der durch p1 und p2 gegebenen Geraden liegt. Ist die
     * Gerade senkrecht, so ist py.x gleich p1.x gleich p2.x.
     * Ist die Gerade waagerecht, so ist py.x nicht eindeutig und wird
     * gleich p1.x gesetzt.
     *
     * @param p2 : [In]         Zweiter Punkt zur definition der Geraden
     * @param py : [In Out]     ->  Punkt mit gegebener Y-Koordinate    <br>
     *                          <-  Punkt mit X- und Y-Koordinate
     *
     * @return double
     *
     * @retval = Geradensteigung, 1e99 bzw. -1e99 bei senkrechter Geraden
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double XfuerY ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* py);
    //=============================================================================
    /**
     *************************************************************************************************
     * @brief Fehlende Y-Koordinate berechnen
     *
     * "YfuerX" berechnet die fehlende Y-Koordinate für den Punkt px, der
     * auf der durch p1 und p2 gegebenen Geraden liegt. Ist die Gerade
     * waagerecht, so ist py.y gleich p1.y gleich p2.y.
     * Ist die Gerade senkrecht, so ist py.y nicht eindeutig und wird gleich
     * p1.y gesetzt.
     *
     * @param p2 : [In]         Zweiter Punkt zur definition der Geraden
     * @param px : [In Out]     ->  Punkt mit gegebener X-Koordinate    <br>
     *                          <-  Punkt mit X- und Y-Koordinate
     *
     * @return double
     *
     * @retval = Geradensteigung, 1e99 bzw. -1e99 bei senkrechter Geraden
     *
     * @author Re.
     *
     *************************************************************************************************
    */
    double YfuerX ( sstMath01dPnt2Cls* p2, sstMath01dPnt2Cls* px);
    //=============================================================================

    /**
     *************************************************************************************************
     * @brief D2-Punkt initialisieren
     *
     * iStat = PktIni ( Key, Pkt);
     *
     * Datenstruktur vor Gebrauch initialieren
     *
     * 05.08.03: Funktion neu eingebaut.  UR
     *
     * @param Key : [In]     Schalter, vorerst immer Null
     *
     * @return int
     *
     * @retval = D2_OK
     * @retval = -1: Key nicht Null
     *
     * @author Re.
     *
     * @date 05.08.03
     *************************************************************************************************
    */
    int PktIni ( int Key);
    //=============================================================================
    /**
    * @brief D2-Punkt in D3-Punkt erweitern
    *
    * iStat = GetD3Pnt ( Key, *D2Pkt, *D3Pkt);
    *
    * Z-Wert/Höhe wird auf Null gesetzt.
    *
    * Geändert: 02.02.04  UR
    *
    * @return D3 Pnt
    *
    * @author ur
    *
    * @date 02.02.04
    */
    sstMath01dPnt3Cls GetD3Pnt ();  //   <-   D3-Punkt
    //=============================================================================
/**
* @brief Set Coordinates for D2-Pnt
*
* iStat = Set ( iKey, *D2Pkt, xx, yy);
*
* More Comment
*
* Changed: 17.04.09  Re
*
* @param xx:    [in]     x-Coordinate
* @param yy:    [in]     y-Coordinate
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 17.04.09  Re
*/
int Set (       double  xx,       // v -> x-Coordinate
                double  yy);      // v -> y-Coordinate

//=============================================================================
/**
* @brief Get Coordinates from D2-Pnt
*
* iStat = Get ( iKey, *D2Pkt, *xx, *yy);
*
* More Comment
*
* Changed: 17.04.09  Re
*
* @param xx:    [out]     x-Coordinate
* @param yy:    [out]     y-Coordinate
*
* @return Errorstate
*
* @retval   = 0: OK
* @retval   < 0: Unspecified Error
*
* @author ur
*
* @date 17.04.09  Re
*/
//-----------------------------------------------------------------------------
int Get (       double *xx,       //   <-  x-Coordinate
                double *yy);      //   <-  y-Coordinate
//==============================================================================
/**
* @brief // Get X Coordinate from 2D Point <BR>
* dX = oPnt.getX ();
*
* @return X Coordinate from 2D Pnt
*/
// ----------------------------------------------------------------------------
double getX();
//==============================================================================
/**
* @brief // Get Y Coordinate from 2D Point <BR>
* dY = oPnt.getY ();
*
* @return Y Coordinate from 2D Pnt
*/
// ----------------------------------------------------------------------------
double getY();
//=============================================================================
/**
* @brief Im rechtwinkeligen Dreieck aus Katheten Hypothenuse berechnen
*
* iStat = Pytha_Hypo ( Key, Ankath, Gegenkath, *Hypo);
*
* Der Satz des Pythagoras, Teil 1.
*
* Geändert: 04.02.02  UR
*
* @param iKey:       [in]  Vorerst immer 0
* @param Ankath:    [in]  Ankathete
* @param Gegenkath: [in]  Gegenkathete
* @param Hypo:      [out] Hypothenuse
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 04.02.02
*/
int Pytha_Hypo ( int     iKey,       // v  -> Vorerst immer 0
                        double  Ankath,     // v  -> Ankathete
                        double  Gegenkath,  // v  -> Gegenkathete
                        double *Hypo);      //   <-  Hypothenuse
//=============================================================================
/**
* @brief Im rechtwinkeligen Dreieck fehlende Kathete berechnen
*
* iStat = Pytha_Kath ( Key, Kath1, Hypo, *Kath2);
*
* Aus Ankathete/Gegenkathete und Hypothenuse fehlende Kathete rechnen.
* Der Satz des Pythagoras, Teil 2.
*
* Geändert: 04.02.02  UR
*
* @param iKey:   [in]  Vorerst immer 0
* @param Kath1: [in]  Kathete1
* @param Hypo:  [in]  Hypothenuse
* @param Kath2: [out] Kathete2
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 04.02.02
*/
int Pytha_Kath ( int     iKey,     // v  -> Vorerst immer 0
                          double  Kath1,    // v  -> Kathete1
                          double  Hypo,     // v  -> Hypothenuse
                          double *Kath2);   //   <-  Kathete2
//=============================================================================
/**
* @brief Aus Winkel und Strecke absolute Koordinaten rechnen
*
* iStat = Polar_Abs ( Key, Winkel, Dist, *Pkt);
*
* Umrechnung von Polarkoordinaten in kathesische Koordinaten.
*
* Geändert: 04.02.02  UR
*
* @param iKey:    [in]  Vorerst immer 0
* @param Winkel: [in]  Winkel -math/rad-
* @param Dist:   [in]  Strecke
* @param Pkt:    [out] Neuer Punkt
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 04.02.02
*/
int Polar_Abs ( int     iKey,    // v  -> Vorerst immer 0
                      double  Winkel, // v  -> Winkel -math/rad-
                      double  Dist,   // v  -> Strecke
                      sstMath01dPnt2Cls *Pkt);   //   <-  Neuer Punkt
//=============================================================================
/**
* @brief Aus Winkel (math/rad) und Strecke Punkt rechnen relativ oder polar zu einem Vorhandenen.
*
* iStat = Polar_Rel ( Key, Winkel, Dist, *AltPkt, *NeuPkt);
*
* Umrechnung von Polarkoordinaten in kathesische Koordinaten.
* Mit Winkel und Strecke von einen vorhandenen Punkt Neupunkt
* absetzen.
*
* Geändert: 04.02.02  UR
*
* @param iKey:    [in]  Vorerst immer 0
* @param Winkel: [in]  Winkel -math/rad-
* @param Dist:   [in]  Strecke
* @param NeuPkt: [out] Neuer Punkt
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 04.02.02
*/
int Polar_Rel ( int     iKey,    // v  -> Vorerst immer 0
                       double  Winkel,  // v  -> Winkel -math/rad-
                       double  Dist,    // v  -> Strecke
                       sstMath01dPnt2Cls *NeuPkt); //   <-  Neuer Punkt
//=============================================================================
/**
* @brief Kartesische Koordinaten mit Bezug Null in Polarkoordinaten umformen
*
* iStat = Kart_Abs ( Key, *Pkt, *Wink, *Dist);
*
* Im mathematischen System. Bezugsachse für den Winkel ist die
* mathematische X-Achse (Rechts) .
* Der Winkel wird quadranten-abhängig zu Fußberechnet, vermutlich gibtŽs
* noch elegantere Lösungen.
*
* Geändert: 05.02.02  UR
*
* @param iKey:  [in]  Vorerst immer 0
* @param Wink: [out] Berechneter Winkel
* @param Dist: [out] Berechnete Distanz
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 05.02.02
*/
int Kart_Abs ( int     iKey,  // v  -> Vorerst immer 0
                      double *Wink,  //   <-  Berechneter Winkel
                      double *Dist); //   <-  Berechnete Distanz
//=============================================================================
/**
* @brief Kartesische Koordinaten relativ in Polarkoordinaten umformen
*
* iStat = Kart_Rel ( Key, *Pkt1, *Pkt2, *Wink, *Dist);
*
* Mit Angabe eines Bezugspunktes.
*
* Geändert: 05.02.02  UR
*
* @param iKey:  [in]  Vorerst immer 0
* @param Pkt2: [in]  Differenzpunkt
* @param Wink: [out] Berechneter Winkel
* @param Dist: [out] Berechnete Distanz
*
* @return Fehlerstatus
*
* @retval   =0 = OK
* @retval   <0 = allgemeiner Fehler
*
* @author ur
*
* @date 05.02.02
*/
int Kart_Rel ( int     iKey,    // v  -> Vorerst immer 0
                      sstMath01dPnt2Cls *Pkt2,   //    -> Differenzpunkt
                      double *Wink,   //   <-  Berechneter Winkel
                      double *Dist);  //   <-  Berechnete Distanz
//=============================================================================
/**
* @brief Sind zwei Punkte innerhalb einer Toleranz identisch ?
*
* iStat = sstMat_PktIdent ( Key, *Pkt1, *Pkt2, Tol);
*
* Der Abstand der beiden Punkte wird berechnet und mit der vorgegebenen
* Toleranz verglichen.
*
* Geändert: 27.01.03  UR
*
* @param iKey:  [in] Vorerst immer 0
* @param Pkt2: [in] Geometriepunkt 2
* @param dTol:  [in] Vorgegebende Toleranzdistanz
*
* @return Fehlerstatus
*
* @retval   =1: Ja, Punkte sind identisch
* @retval   =0: Nein, nicht identisch
* @retval   <0: allgemeiner Fehler
*
* @author ur
*
* @date 27.01.03
*/
//-----------------------------------------------------------------------------
int sstMat_PktIdent ( int      iKey,   // v  -> Vorerst immer 0
                      sstMath01dPnt2Cls  *Pkt2,  //    -> Geometriepunkt 2
                      double   dTol);  // v  -> Vorzugebende Toleranzdistanz
//=============================================================================
     double   x;               /**< Punktkoordinaten */
     double   y;               /**< Punktkoordinaten */
  private:  // Private functions
};
//==============================================================================
/**
* @brief 3D double Point
*
* Changed: 09.07.15  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 09.07.15
*/
// ----------------------------------------------------------------------------
class sstMath01dPnt3Cls
{
  public:   // Public functions
     sstMath01dPnt3Cls();  // Constructor

     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Vektorbetrag
      *
      * "VBetrag" berechnet den Vektorbetrag von vec.
      *
      * @return double
      *
      * @retval = Vektorbetrag
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double VBetrag ();

     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Raumstrecke
      *
      * "Strecke" berechnet die 3D-Strecke zwischen p1 und p2.
      *
      * @param p2 : [In]     Streckenende
      *
      * @return double
      *
      * @retval = Raumstrecke
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double Strecke ( sstMath01dPnt3Cls* p2);

 //=============================================================================
 /**
 * @brief Raumstrecke oder ebene Strecke
 *
 * dDist = Strecke2 ( iKey, P1, P2);
 *
 * More Comment
 *
 * Changed: 01.09.09  Re.
 *
 * @param iKey: [in] iKey=0: Raumstrecke, iKey=1:Ebene Strecke
 * @param P2:   [in] Punkt 2
 *
 * @return Strecke
 *
 * @retval   >= 0: Strecke
 * @retval   <  0: Wrong Key
 *
 * @author Re.
 *
 * @date 01.09.09
 */
 //-----------------------------------------------------------------------------
 double Strecke2 (int iKey, sstMath01dPnt3Cls *P2);
 //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Vektor auf die Länge 1.0 normierten
      *
      * "VekNorm" normiert den 3D-Vektor vec auf die Länge 1.0. Ist der
      * Vektorbetrag kleiner 1e-99, so wird der Vektor nicht normiert.
      *
      * @return double
      *
      * @retval = Vektorbetrag, 0.0 wenn Vektorbetrag kleiner 1e-99
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double VekNorm ();
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Vektorprodukt
      *
      * "VekProdukt" berechnet das Vektorprodukt der Vektoren v1 und v2.
      *
      * @param v2 : [In]     Beliebiger Vektor
      * @param vprd : [Out]  Vektorielles Produkt
      *
      * @return double
      *
      * @retval = Betrag des Vektorprodukts, bzw. die Fläche des von v1 und    <br>
      *           v2 aufgespannten Parallelogramms
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double VekProdukt ( sstMath01dPnt3Cls* v2, sstMath01dPnt3Cls* vprd);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Neupunkt
      *
      * "NeuPkt" berechnet einen 3D-Punkt mit dem Abstand cc von ps auf
      * dem Vektor vec. Der Neupunkt liegt dann cc entfernt vom Punkt ps
      * in Richtung des Vektors vec (wenn cc negativ, dann Gegenrichtung).
      *
      * @param vec : [In]    Vektor für Blickrichtung (muß nicht normiert sein)
      * @param cc : [In]     Abstand des Neupunktes vom Standpunkt in Richtung vec
      * @param pn : [Out]    Neuer Punkt
      *
      * @return double
      *
      * @retval = Betrag des Richtungsvektors vec
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double NeuPkt ( sstMath01dPnt3Cls* vec, double cc, sstMath01dPnt3Cls* pn);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Neupunkt berechnen
      *
      * "NeuPkt2" berechnet einen 3D-Punkt mit dem Abstand cc von p1 in
      * Richtung p2 auf der durch p1 und p2 definierten Geraden.
      * Der Neupunkt liegt dann cc entfernt vom Punkt p1 in Richtung p2
      * (wenn cc negativ, dann Gegenrichtung).
      * Ist die Strecke zwischen p1 und p2 kleiner 1e-99, so wird der
      * Richtungsvektor nicht bestimmt und das Ergebnis pn ist falsch.
      *
      * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
      * @param cc : [In]     Abstand des Neupunktes von p1 in Richtung p2
      * @param pn : [Out]    Abstand des Neupunktes von p1 in Richtung p2
      *
      * @return double
      *
      * @retval = Betrag der Raumstrecke zwischen p1 und p2
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double NeuPkt2 ( sstMath01dPnt3Cls* p2, double cc, sstMath01dPnt3Cls* pn);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Fußpunkt
      *
      * "FusPkt" berechnet den 3D-Fußpunkt des Lotes von ps auf die durch
      * p1 und p2 definierte Gerade und den Abstand des Punktes ps von
      * der Geraden. Siehe auch Rep. der Ingenieur-Mathematik S.94. Ist die
      * Strecke zwischen p1 und p2 kleiner 1e-99, so wird von identischen
      * Punkten ausgegangen. Der Returnwert ist dann -1.0.
      *
      * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
      * @param ps : [In]     Standpunkt
      * @param pf : [Out]    Fußpunkt (bei Fehler Standpunkt)
      *
      * @return double
      *
      * @retval = Abstand von ps zur Geraden (bei Fehler immer -1.0)
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double FusPkt ( sstMath01dPnt3Cls* p2, sstMath01dPnt3Cls* ps, sstMath01dPnt3Cls* pf);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Richtungsdifferenz zweier Raumgeraden
      *
      * "RtgDif" berechnet die Richtungsdifferenz zweier Geraden. Die
      * Richtungsdifferenz ist der Schnittwinkel der Richtungsvektoren. Sind
      * die Geraden parallel, so ist die Richtungsdifferenz 0.0, sind die
      * Geraden gegenläufig parallel, so ist die Richtungsdifferenz PI. Die
      * Richtungsdifferenz ist immer positiv. Siehe auch Rep. der Ingenieur-
      * Mathematik S.87.
      * Bei Fehler (Strecke zwischen p1 und p2 bzw. Strecke zwischen p3
      * und p4 kleiner 1e-99) ist der Returnwert -PI.
      *
      * @param p2 : [In]     Zweiter Punkt zur definition der ersten Geraden
      * @param p3 : [In Out] Erster Punkt zur definition der zweiten Geraden
      * @param p4 : [In Out] Zweiter Punkt zur definition der zweiten Geraden
      *
      * @return double
      *
      * @retval = Richtungsdifferenz in rad, bei Fehler -PI
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double RtgDif ( sstMath01dPnt3Cls* p2, sstMath01dPnt3Cls* p3, sstMath01dPnt3Cls* p4);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Drehmatrix besetzen
      *
      * "DrehMat" besetzt die Drehmatrix. Es wird in der Reihenfolge -
      * Drehung um X-Achse - Drehung um Y-Achse - Drehung um Z-Achse gedreht.
      * Die Drehungen erfolgen alle im Uhrzeigersinn. Die Einzelmatrizen
      * sind folgendermaßen besetzt:
      *
      *  1      0      0        cos(Þ)   0     sin(Þ)     cos(æ) -sin(æ)  0
      *  0   cos(Û) -sin(Û)       0      1      0         sin(æ)  cos(æ)  0
      *  0   sin(Û)  cos(Û)    -sin(Þ)   0     cos(Þ)       0      0      1
      *
      * Die vollständige Drehmatrix  A = AÛ * AÞ * Aæ  ist dann:
      *
      *         cos(Þ)*cos(æ)                -cos(Þ)*sin(æ)             sin(Þ)
      * co(Û)*si(æ)+si(Û)*si(Þ)*co(æ)  co(Û)*co(æ)-si(Û)*si(Þ)*si(æ) -si(Û)*co(Þ)
      * si(Û)*si(æ)-co(Û)*si(Þ)*co(æ)  si(Û)*co(æ)+co(Û)*si(Þ)*si(æ)  co(Û)*co(Þ)
      *
      * @param omega : [In]  Drehwinkel um die X-Achse (rad)
      * @param phi : [In]    Drehwinkel um die Y-Achse (rad)
      * @param kappa : [In]  Drehwinkel um die Z-Achse (rad)
      * @param mat : [Out]   Drehmatrix mit 9 Elementen
      *
      * @return long int
      *
      * @retval = D3_OK (immer)
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     long DrehMat (double omega, double phi, double kappa, double* mat);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Punkt mit 3D-Drehmatrix transformieren
      *
      * "Transf" transformiert den Punkt bzw. Vektor vec mit der Drehmatrix dmat.
      *
      * @param dmat : [In]       Drehmatrix (3x3)
      *
      * @return long int
      *
      * @retval = D3_OK (immer)
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     long Transf (double* dmat);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Ebene in HNF aus Punkt und Normalenvektor
      *
      * "EbenePV" berechent aus einem Punkt pf und dem Normalenvektor
      * vec die 'Hessesche Normalform' der Ebene (Koordinatendarstellung
      * mit Normaleneinheitsvektor und k = 0).
      * Siehe Rep. der Ingenieur-Mathematik S.99/100.
      *
      * @param vec : [In]    Auf die Ebene senkrecht stehender Vektor
      * @param eb : [Out]    Ebene in Koordinatendarstellung - HNF
      *
      * @return double
      *
      * @retval = Betrag des Richtungsvektors vec
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double EbenePV ( sstMath01dPnt3Cls* vec, sstMath01Plane* eb);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Ebene in HNF aus 3 Punkten
      *
      * "EbeneP3" berechnet aus 3 Punkten die 'Hessesche Normalform' der
      * Ebene. Liegen die 3 Punkte auf einer Geraden, so ist die Ebene nicht
      * definiert.
      *
      * @param p2 : [In]     Zweiter Punkt auf der Ebene
      * @param p3 : [In]     Dritter Punkt auf de Ebene
      * @param eb : [Out]    Ebene in Koordinatendarstellung - HNF
      *
      * @return double
      *
      * @retval = Betrag des Richtungs- bzw. Normalenvektors, -1.0 bei Fehler
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double EbeneP3 ( sstMath01dPnt3Cls* p2, sstMath01dPnt3Cls* p3, sstMath01Plane* eb);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Abstand von Punkt und Gerade im Raum
      *
      * "AbstPG" berechent den Abstand des Punktes ps von der durch p1
      * und p2 gegebenen Geraden.
      *
      * @param p2 : [In]     Zweiter Punkt zur definition der Geraden
      * @param ps : [In]     Raumpunkt
      *
      * @return double
      *
      * @retval = Abstand zur Geraden, -1.0 bei Fehler
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double AbstPG ( sstMath01dPnt3Cls* p2, sstMath01dPnt3Cls* ps);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Abstand eines Punktes von einer Ebene
      *
      * "AbstPE" berechent den Abstand des Punktes pa von der Ebene eb.
      * Liegt der Punkt auf der den Koordinaten-Nullpunkt enthaltenden Seite
      * der Ebene, so ist der Abstand negativ.
      * Siehe Rep. der Ingenieur-Mathematik S.100.
      *
      * @param eb : [In]     Ebene in Koordinatendarstellung - HNF
      *
      * @return double
      *
      * @retval = Abstand des Punktes von der Ebene
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double AbstPE ( sstMath01Plane* eb);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief 3D-Fußpunkt auf eine Ebene
      *
      * "FusPktE" berechnet den 3D-Fußpunkt des Lotes von ps auf die
      * Ebene eb und den Abstand des Punktes ps von der Ebene.
      * Siehe auch Repetitorium der Ingenieur-Mathematik S.101.
      *
      * @param eb : [In]     Ebene in HNF
      * @param pf : [Out]    Fußpunkt, Standpunkt bei Fehler
      *
      * @return double
      *
      * @retval = Abstand von ps zur Ebene, -1.0 wenn Ebene fehlerhaft
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double FusPktE ( sstMath01Plane* eb, sstMath01dPnt3Cls* pf);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Schnittwinkel zweier Ebenen
      *
      * "SnitWklEE" berechnet den Schnittwinkel zweier Ebenen über deren
      * Normalenvektoren. Sind die Normalenvektoren parallel, so ist der
      * Schnittwinkel 0.0, sind die Normalenvektoren gegenläufig parallel, so
      * ist der Schnittwinkel PI. Der Schnittwinkel ist immer positiv.
      * Siehe auch Rep. der Ingenieur-Mathematik S.87 und S.101.
      * Bei Fehler (Betrag der eines Normalenvektors kleiner 1e-99) ist der
      * Returnwert -PI.
      *
      * @param e1 : [In]     Ebene 1
      * @param e2 : [In]     Ebene 2
      *
      * @return double
      *
      * @retval = Schnittwinkel in rad, bei Fehler -PI
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     double SnitWklEE (sstMath01Plane* e1, sstMath01Plane* e2);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Projektion einer Geraden auf eine Ebene
      *
      * "AbbildGE" projiziert die durch p1 und p2 gegebene Raumgerade
      * auf die Ebene eb. Steht die Gerade senkrecht auf der Ebene, so bleibt
      * die Gerade unverändert.
      *
      * @param eb : [In]     Ebene in Koordinatendarstellung
      * @param p1 : [In Out] -> Erster Punkt zur definition der Raumgeraden <br>
      *                      <- Erster Punkt zur definition der Bildgeraden
      * @param p2 : [In Out] -> Zweiter Punkt zur definition der Raumgeraden <br>
      *                      <- Zweiter Punkt zur definition der Bildgeraden
      *
      * @return long int
      *
      * @retval = D3_OK
      * @retval = D3_SENKR
      *
      * @author RE.
      *
      *************************************************************************************************
     */
     long AbbildGE (sstMath01Plane* eb, sstMath01dPnt3Cls* p1, sstMath01dPnt3Cls* p2);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Schnitt Gerade-Ebene
      *
      * "SnitGE" berechent den Durchstoßpunkt einer durch 2 Punkte
      * definierten Raumgeraden auf der Ebene eb.
      * Siehe auch Rep. der Ingenieur-Math. S.102.
      *
      * @param p2 : [In]     Zweiter Punkt zur definition der Raumgeraden
      * @param eb : [In]     Ebene in Koordinatendarstellung
      * @param pd : [Out]    Durchstoßpunkt
      *
      * @return long int
      *
      * @retval = D3_OK
      * @retval = D3_PARALLEL
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     long SnitGE ( sstMath01dPnt3Cls* p2, sstMath01Plane* eb, sstMath01dPnt3Cls* pd);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Schnittgerade zweier Ebenen berechnen
      *
      * "SnitEE" berechent die Schnittgerade zweier Ebenen. Sind die Ebenen
      * parallel, so ist die Schnittgerade nicht definiert.
      *
      * @param e1 : [In]     Ebene 1
      * @param e2 : [In]     Ebene 2
      * @param pg : [Out]    Punkt auf der Schnittgeraden
      * @param vg : [Out]    Richtungsvektor der Schnittgeraden
      *
      * @return long int
      *
      * @retval = D3_OK
      * @retval = D3_PARALLEL
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     long SnitEE (sstMath01Plane* e1, sstMath01Plane* e2, sstMath01dPnt3Cls* pg, sstMath01dPnt3Cls* vg);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief Reduziert Punkt auf Ursprung einer Bildebene
      *
      * "ReduP3_P2" reduziert den 3D-Punkt pd auf den Ursprung ur einer
      * Bildebene und auf zwei auf der Bildebene liegende Richtungsvektoren
      * vec[0] und vec[1]. Das Ergebnis ist ein 2D-Punkt in Koordinaten
      * der Ebene bzgl. dem Ursprung und der Richtungsvektoren.
      *
      * @param vec : [In]    Richtungsvektoren(vec[0], vec[1]), auf die pd reduziert wird
      * @param pd : [In]     Zu reduzierender Punkt
      * @param pb : [Out]    Reduzierter Bildpunkt
      *
      * @return long int
      *
      * @retval = D3_OK (immer)
      *
      * @author Re.
      *
      *************************************************************************************************
     */
     long ReduP3_P2 ( sstMath01dPnt3Cls* vec, sstMath01dPnt3Cls* pd, sstMath01dPnt2Cls* pb);
     //=============================================================================
     /**
      *************************************************************************************************
      * @brief D3-Punkt initialisieren
      *
      * iStat = PktIni ( Key, Pkt);
      *
      * Datenstruktur vor Gebrauch initialieren
      *
      * 05.08.03: Funktion neu eingebaut.  UR
      *
      * @param iKey : [In]     Schalter, vorerst immer Null
      *
      * @return int
      *
      * @retval = D2_OK
      * @retval = -1: Key nicht Null
      *
      * @ingroup Geometrie
      *
      * @author UR
      *
      * @date 05.08.03
      *************************************************************************************************
     */
     int PktIni ( int iKey);
     //=============================================================================
 /**
 * @brief D3-Punkt in D2-Punkt reduzieren
 *
 * iStat = GetD2Pnt ( Key, *D3Pkt, *D2Pkt);
 *
 * Information Z-Wert/Höhe geht verloren.
 *
 * Geändert: 02.02.04  UR
 *
 * @return Fehlerstatus
 *
 * @retval   =0 = OK
 * @retval   <0 = allgemeiner Fehler
 *
 * @author ur
 *
 * @date 02.02.04
 */
 sstMath01dPnt2Cls GetD2Pnt ();
 //==============================================================================
 /**
 * @brief // Convert Pnt to csv-string with decimal point char and 2 decimal values <BR>
 *
 * @return string
 */
 // ----------------------------------------------------------------------------
 std::string toString ();
 //=============================================================================
 /**
 * @brief Set Coordinates for D3-Pnt
 *
 * iStat = Set ( iKey, *D3Pkt, xx, yy, zz);
 *
 * More Comment
 *
 * Changed: 17.04.09  Re
 *
 * @param xx:    [in]     x-Coordinate
 * @param yy:    [in]     y-Coordinate
 * @param zz:    [in]     z-Coordinate
 *
 * @return Errorstate
 *
 * @retval   = 0: OK
 * @retval   < 0: Unspecified Error
 *
 * @author ur
 *
 * @date 17.04.09  Re
 */
 //-----------------------------------------------------------------------------
 int Set (       double xx,       // v -> x-Coordinate
                 double yy,       // v -> y-Coordinate
                 double zz);      // v -> z-Coordinate
 //=============================================================================
 /**
 * @brief Get Coordinates from D3-Pnt
 *
 * iStat = Get ( iKey, *D3Pkt, *xx, *yy, *zz);
 *
 * More Comment
 *
 * Changed: 17.04.09  Re
 *
 * @param iKey:  [in]     For the moment 0
 * @param xx:    [out]     x-Coordinate
 * @param yy:    [out]     y-Coordinate
 * @param zz:    [out]     z-Coordinate
 *
 * @return Errorstate
 *
 * @retval   = 0: OK
 * @retval   < 0: Unspecified Error
 *
 * @author ur
 *
 * @date 17.04.09  Re
 */
 //-----------------------------------------------------------------------------
 int Get (int     iKey,    // v  -> For the moment 0
                 double *xx,      //   <-  x-Coordinate
                 double *yy,      //   <-  y-Coordinate
                 double *zz);     //   <-  z-Coordinate
 //==============================================================================
 /**
 * @brief // Get X Coordinate from 3D Point <BR>
 * dX = oPnt.getX ();
 *
 * @return X Coordinate from 3D Pnt
 */
 // ----------------------------------------------------------------------------
 double getX();
 //==============================================================================
 /**
 * @brief // Get Y Coordinate from 3D Point <BR>
 * dY = oPnt.getY ();
 *
 * @return Y Coordinate from 3D Pnt
 */
 // ----------------------------------------------------------------------------
 double getY();
 //==============================================================================
 /**
 * @brief // Get Z Coordinate from 3D Point <BR>
 * dY = oPnt.getZ ();
 *
 * @return Z Coordinate from 3D Pnt
 */
 // ----------------------------------------------------------------------------
 double getZ();
 //=============================================================================
 /**
 * @brief Calculate Distance when within the Limiations
 *
 * iStat = CalcDistLimit ( iKey, *Pnt1, *Pnt2, GivenLimit, *CalcDist);
 *
 * Changed: 20.04.09  UR
 *
 * @param iKey: [in]       For the moment 0
 * @param Pnt2: [in]       Point around
 * @param GivenLimit: [in] Limited Distance
 * @param CalcDist: [out]  Calculated when within
 *
 * @return Errorstate
 *
 * @retval   = 1: Within the Limitations
 * @retval   = 0: Outside
 * @retval   < 0: Unspecified Error
 *
 * @author ur
 *
 * @date 20.04.09
 */
 //-----------------------------------------------------------------------------
 int CalcDistLimit (int      iKey,         // v  -> For the moment 0
                       sstMath01dPnt3Cls  *Pnt2,         // Pnt 2
                       double   GivenLimit,   // Given Limit Distance
                       double  *CalcDist);    // Calulated Distance
 //=============================================================================
 /**
 * @brief Schnitt zweier Raumgeraden
 *
 * iStat = SnitGG ( iKey, P1, P2, P3, P4, Ps);
 *
 * Die Höhe des Schnittpunkts wird in der Raumgeraden interpoliert.
 *
 * Changed: 02.09.09  Re.
 *
 * @param iKey: [in]  iKey=0: Höhe von Gerade 1, iKey=1: Höhe von Gerade 2
 * @param P2:   [in]  Punkt 2 von Gerade 1
 * @param P3:   [in]  Punkt 1 von Gerade 2
 * @param P4:   [in]  Punkt 2 von Gerade 2
 * @param Ps:   [out] Schnittpunkt
 *
 * @return Errorstate
 *
 * @retval   =  1: OK
 * @retval   =  0: Kein Schnittpunkt
 * @retval   = -1: Wrong Key
 * @retval   = -2: Punkte 1 und 2 identisch
 * @retval   = -3: Punkte 3 und 4 identisch
 * @retval   = -4: Ebenenbildung nicht möglich
 * @retval   = -5: Keinen Schnittpunkt gefunden, Parallel?
 *
 * @author Re.
 *
 * @date 02.09.09
 */
 //-----------------------------------------------------------------------------
 int SnitGG (int iKey,
                sstMath01dPnt3Cls *P2,
                sstMath01dPnt3Cls *P3,
                sstMath01dPnt3Cls *P4,
                sstMath01dPnt3Cls *Ps);

 //==============================================================================
 /**
 * @brief Simple coordinate transformation for 3d points
 *
 * iStat = CoorTrans( iKey, *dPnt, dScal, dMov);
 *
 * More Comment
 *
 * Changed: 16.02.10  Re.
 *
 * @param iKey [in] For the moment 0
 * @param dScal [in] For the moment 0
 * @param dMov [in] For the moment 0
 *
 * @return Errorstate
 *
 * @retval   = 0: OK
 * @retval   < 0: Unspecified Error
 *
 * @author Re.
 *
 * @date 16.02.10
 */
 //------------------------------------------------------------------------------
 int CoorTrans(int         iKey,
                  double      dScal,
                  double      dMov);
 //==============================================================================
 /**
 * @brief Simple coordinate transformation for 3d points
 *
 * iStat = CoorTrans( iKey, *dPnt, dScal, dMov);
 *
 * More Comment
 *
 * Changed: 16.02.10  Re.
 *
 * @param iKey [in] For the moment 0
 * @param dScal [in] For the moment 0
 * @param dMovX [in] For the moment 0
 * @param dMovY [in] For the moment 0
 *
 * @return Errorstate
 *
 * @retval   = 0: OK
 * @retval   < 0: Unspecified Error
 *
 * @author Re.
 *
 * @date 16.02.10
 */
 //------------------------------------------------------------------------------
 int CoorXTrans(int         iKey,
                  double      dScal,
                  double      dMovX,
                  double      dMovY);
 //=============================================================================
 /**
 * @brief Sind zwei 3D-Punkte innerhalb einer Toleranz identisch ?
 *
 * iStat = PktIdent3D ( Key, *Pkt1, *Pkt2, Tol);
 *
 * Der Abstand der beiden Punkte wird berechnet und mit der vorgegebenen
 * Toleranz verglichen.
 *
 * Geändert: 12.08.09  Re.
 *
 * @param iKey:  [in] iKey=0: 2D, iKey=1: 3D
 * @param Pkt2: [in] Geometriepunkt 2
 * @param dTol:  [in] Vorzugebende Toleranzdistanz
 *
 * @return Fehlerstatus
 *
 * @retval   =1: Ja, Punkte sind identisch
 * @retval   =0: Nein, nicht identisch
 * @retval   <0: allgemeiner Fehler
 *
 * @author Re.
 *
 * @date 12.08.09
 */
 //-----------------------------------------------------------------------------
 int PktIdent3D ( int      iKey,   // v  -> 0 oder 1
                         sstMath01dPnt3Cls  *Pkt2,   //    -> Geometriepunkt 2
                         double   dTol);   // v  -> Vorzugebende Toleranzdistanz
 //=============================================================================
 /**
 * @brief D2-Richtungswinkel von D3-Punkten berechnen
 *
 * dRiWi = RiWi ( iKey, *Pnt1, *Pnt2);
 *
 * More Comment
 *
 * Changed: 25.08.09
 *
 * @ingroup Geometrie
 *
 * @param iKey: [in] For the moment 0
 * @param Pnt2: [in] Punkt 2
 *
 * @return Errorstate
 *
 * @retval   = 0: OK
 * @retval   < 0: Unspecified Error
 *
 * @author Re.
 *
 * @date 25.08.09
 */
 //-----------------------------------------------------------------------------
 double RiWi (int         iKey,
                 sstMath01dPnt3Cls *Pnt2);
 //=============================================================================
 double   x;               /**< Punktkoordinaten */
 double   y;               /**< Punktkoordinaten */
 double   z;               /**< Punktkoordinaten */
  private:  // Private functions
};
//==============================================================================
/**
* @brief 2D Minimum Bounding Rectangle
*
* Changed: 06.01.17  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 06.01.17
*/
// ----------------------------------------------------------------------------
class sstMath01Mbr2Cls
{
  public:   // Public functions
     sstMath01Mbr2Cls();  // Constructor
// ----------------------------------------------------------------------------

     //==============================================================================
     /**
     * @brief Min-Max initialisieren
     *
     * iStat = Mia_2Ini_c  ( Key, *Mima);
     *
     * Kommentar 1
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in]  Vorerst immer 0
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Ini2 ( int    iKey);
     //==============================================================================
     /**
     * @brief Min-Max mit einem Punkt initialisieren
     *
     * iStat = Mia_2IniPkt ( Key, *Mima, X1, Y1);
     *
     * Weiterer Kommentar
     *
     * Geändert: 13.05.04
     *
     * @param iKey  [in] Vorerst immer 0
     * @param X1    [in] Eingabe-Punkt X
     * @param Y1    [in] Eingabe-Punkt Y
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int IniPkt2( int      iKey,   // v  -> Key vorerst immer 0
                        double   X1,     // v  -> x Punkt 1
                        double   Y1);    // v  -> y Punkt 1
     //==============================================================================
     /**
     * @brief Min-Max mit einer 2D-Geraden initialisieren
     *
     * iStat = Mia_2IniLin_c( Key, *Mima, X1, Y1, X2, Y2);
     *
     * Kommentar 1
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey [in]     Vorerst immer 0
     * @param X1   [in]     x Punkt 1
     * @param Y1   [in]     y Punkt 1
     * @param X2   [in]     x Punkt 2
     * @param Y2   [in]     y Punkt 2
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int IniLin2( int      iKey,   // v  -> Key vorerst immer 0
                        double   X1,     // v  -> x Punkt 1
                        double   Y1,     // v  -> y Punkt 1
                        double   X2,     // v  -> x Punkt 2
                        double   Y2);    // v  -> y Punkt 2

     //==============================================================================
     /**
     * @brief Abfrage:Min-Max-Werte in Ordnung ??
     *
     * iStat = Mia_2OK_c ( Key, *Mima);
     *
     * Kommentar 1
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in]     Vorerst immer 0
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int OK2 ( int      iKey);
     //==============================================================================
     /**
     * @brief Min-Max mit Koordinaten abgleichen
     *
     * iStat = Mia_2Koor_c ( Key, *Mima,  X,  Y);
     *
     * Kommentar 1
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in]     Vorerst immer 0
     * @param X     [in]     PrÃŒfwert: Punkt-X
     * @param Y     [in]     PrÃŒfwert: Punkt-Y
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Koor2 ( int      iKey,   // Vorerst immer 0
                       double   X,     // PrÃŒfwert: Punkt-X
                       double   Y);    // PrÃŒfwert: Punkt-Y
     //==============================================================================
     /**
     * @brief Min-Max-Bereich mit D2-Punkt abgleichen
     *
     * iStat = Mia_2Pkt_c ( Key, *Mima, *Pkt);
     *
     * Kommentar 1
     *
     * Geändert: 06.08.03  UR
     *
     * @param iKey  [in]     Vorerst immer 0
     * @param Pkt   [in]     PrÃŒfwert: D2-Punkt
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Pkt2( int         iKey,   // v -> Key vorerst immer 0
                     sstMath01dPnt2Cls *Pkt);   //   -> PrÃŒfwert: D2-Punkt

     //==============================================================================
     /**
     * @brief Koordinate mit Min-Max ÃŒberprÃŒfen
     *
     * iStat = Mia_2Pruef_c ( Key, *Mima, X, Y);
     *
     * PrÃŒfen, ob eine Koordinate innerhalb der Min-Max-Werte liegen.
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in] Vorerst immer 0
     * @param X     [in] PrÃŒfwert: Punkt-X
     * @param Y     [in] PrÃŒfwert: Punkt-Y
     *
     * @return Fehlerstatus
     *
     * @retval     0 : PrÃŒfpunkt liegt innerhalb
     * @retval bit 0 : X auÃerhalb der Min-Max-Werte
     * @retval bit 1 : Y auÃerhalb der Min-Max-Werte
     * @retval    -1 : Feld Mima nicht korrekt
     * @retval   -10 : unzulÃ€ssiger Key <> 0
     */
     int Pruef2 ( int      iKey,   // Vorerst immer 0
                        double   X,     // PrÃŒfwert: Punkt-X
                        double   Y);    // PrÃŒfwert: Punkt-Y

     //==============================================================================
     /**
     * @brief Koordinate mit Min-Max ÃŒberprÃŒfen
     *
     * iStat = Mia_2Pruef_c ( Key, *Mima, X, Y);
     *
     * PrÃŒfen, ob eine Koordinate innerhalb der Min-Max-Werte liegen.
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in] Vorerst immer 0
     * @param X     [in] PrÃŒfwert: Punkt-X
     * @param Y     [in] PrÃŒfwert: Punkt-Y
     * @param Tol   [in] Tolerance Value
     *
     * @return Fehlerstatus
     *
     * @retval     0 : PrÃŒfpunkt liegt innerhalb
     * @retval bit 0 : X auÃerhalb der Min-Max-Werte
     * @retval bit 1 : Y auÃerhalb der Min-Max-Werte
     * @retval    -1 : Feld Mima nicht korrekt
     * @retval   -10 : unzulÃ€ssiger Key <> 0
     */
     int PruefT2( int    iKey,    // v  -> Key vorerst immmer 0
                        double   X,      // v  -> PrÃŒfwert: Punkt-X
                        double   Y,      // v  -> PrÃŒfwert: Punkt-Y
                        double   Tol);    // v  -> Toleranzwert
     //==============================================================================
     /**
     * @brief Test, ob Ãberdeckung vorliegt
     *
     * iSat = Mia_2Box_c ( Key, *Mima1, *Mima2);
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey   [in] Vorerst immer 0
     * @param Mima2  [in] Min-Max-Werte : Eingabebereich 2
     *
     * @return Fehlerstatus
     *
     * @retval   =1: Boxen berÃŒhren sich oder ÃŒberdecken sich
     * @retval   =0: Keine Ãberdeckung oder BerÃŒhrung
     * @retval   <0: allgemeiner Fehler
     */
     int Box2 ( int      iKey,    // v -> vorerst immer null
                      sstMath01Mbr2Cls *Mima2); //   -> Min-Max-Werte : Eingabebereich 2
     //==============================================================================
     /**
     * @brief Min-Max verschneiden
     *
     * iStat = Mia_2Ber_c ( Key, *Mima1, *Mima2, *Mima3);
     *
     * Eingabe-Key = 0 : Gesamtbereich bilden
     * Eingabe-Key = 1 : Schnittbereich bilden
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey   [in]  0 oder 1
     * @param Mima2 [in]  Min-Max-Werte : Eingabebereich 2
     * @param Mima3 [out] Min-Max-Werte : Rückgabebereich
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Ber2 ( int      iKey,     // 0 oder 1
                      sstMath01Mbr2Cls *Mima2,   // Min-Max-Werte : Eingabebereich 2
                      sstMath01Mbr2Cls *Mima3);  // Min-Max-Werte : Rückgabebereich
     //==============================================================================
     /**
     * @brief Min-Max abfragen
     *
     * iStat = Mia_2Les_c ( Key, *Mima, *D);
     *
     * Key = 0 : Rückgabe in D: Min X
     * Key = 1 : Rückgabe in D: Min Y
     * Key = 3 : Rückgabe in D: Max X
     * Key = 4 : Rückgabe in D: Max Y
     * Key = 6 : Rückgabe in D: LÃ€nge X
     * Key = 7 : Rückgabe in D: LÃ€nge Y
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in]      0 bis 7
     * @param D     [out]     Ergebnis D
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Les2 ( int      iKey,   // 0 bis 7
                      double  *D);     // Ergebnis D
     //==============================================================================
     /**
     * @brief Mittelpunkt einer MinMax-Box rechnen
     *
     * iStat = Mia_2Centr_c ( Key, *Mima, *Pkt);
     *
     * Kommentar 1
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in]     Vorerst immer 0
     * @param Pkt   [out]    Mittelpunkt
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Centr2 ( int      iKey,     // v  -> Vorerst immer 0
                        sstMath01dPnt2Cls  *Pkt);    //   <-> Mittelpunkt
     //==============================================================================
     /**
     * @brief MinMax-Box um Dx und Dy verschieben
     *
     * iStat = Mia_2Move_XY_c ( Key, *Mima, Dx, Dy);
     *
     * Kommentar 1
     *
     * Geändert: 06.08.03  UR
     *
     * @param iKey  [in]     Vorerst immer 0
     * @param Dx    [in]     Verschiebungswert X
     * @param Dy    [in]     Verschiebungswert Y
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Move_XY2 ( int         iKey,     // v  -> Vorerst immer 0
                          double      Dx,      // v  -> Verschiebungswert X
                          double      Dy);     // v  -> Verschiebungswert Y
     //==============================================================================
     /**
     * @brief MinMax um MinMax-Mittelpunkt skalieren
     *
     * Skalierungswert  = 1.0: Keine Ãnderung
     * Skalierungswert <= 0.0: Nicht erlaubt.
     *
     * Geändert: 02.02.04  UR
     *
     * 02.02.04: Aus Modul dxflage geholt.  UR
     *
     * @param iKey   [in]      Vorerst immer 0
     * @param dScal  [in]      Skalierungswert
     *
     * @return Rückgabe Funktion
     *
     * @retval   =0 = OK
     * @retval   -1 = Nicht erlaubter Key
     * @retval   -2 = Skalierungswert zu klein
     * @retval   <0 = Allgemeiner Fehler
     */
     int Scal2 ( int      iKey,
                 double   dScal);
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * iStat = oMbr.GetValue.getValue(dVal);
     *
     * @return double value
     */
     // ----------------------------------------------------------------------------
     double getXI() const;
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * iStat = oMbr.GetValue.getValue(dVal);
     *
     * @return double value
     */
     // ----------------------------------------------------------------------------
     double getYI() const;
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * iStat = oMbr.GetValue.getValue(dVal);
     *
     * @return double value
     */
     // ----------------------------------------------------------------------------
     double getXA() const;
     //==============================================================================
     /**
     * @brief // Get Value <BR>
     * iStat = oMbr.GetValue.getValue(dVal);
     *
     * @return double value
     */
     // ----------------------------------------------------------------------------
     double getYA() const;
     //==============================================================================
     /**
     * @brief // Get MBR as csv string (XI;YI;XA;YA) <BR>
     * oMBR_Str = oMbr.toString();
     *
     * @return string value
     */
     // ----------------------------------------------------------------------------
     std::string toString() const;
     //==============================================================================

private:  // Private functions
     double XI;   /**< Lower, left corner */
     double YI;   /**< Lower, left corner */
     double XA;   /**< Upper, right corner */
     double YA;   /**< Upper, right corner */
};
/**
* @brief 4D transformation matrix
*
* Changed: 19.02.10  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class sstMath01TrnCls
{
  public:   // Ãffentliche Funktionen
     sstMath01TrnCls();  // Konstruktor
    // ~X();  // Destruktor
     //=============================================================================
     /**
     * @brief Set Move Values in Transformation Matrix
     *
     * @param iKey  [in]  Vorerst immer 0
     * @param dMovX [in]  Verschiebung X
     * @param dMovY [in]  Verschiebung Y
     * @param dMovZ [in]  Verschiebung Z
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int SetMov ( int               iKey,
                  double            dMovX,
                  double            dMovY,
                  double            dMovZ);
     //=============================================================================
     /**
     * @brief Set Scal values in transformation matrix
     *
     * @param iKey   [in]  Vorerst immer 0
     * @param dScalX [in]  Skalierung X
     * @param dScalY [in]  Skalierung Y
     * @param dScalZ [in]  Skalierung Z
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int SetScal ( int             iKey,
                   double          dScalX,
                   double          dScalY,
                   double          dScalZ);
     //=============================================================================
     /**
     * @brief Set rotation value in transformation matrix
     *
     * @param iKey  [in]  Vorerst immer 0
     * @param dRotZ [in]  Rotation Z-Achse
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int SetRotZ ( int               iKey,
                   double            dRotZ);
     //=============================================================================
     /**
     * @brief Get move values from transformation matrix
     *
     * @param iKey  [in]  Vorerst immer 0
     * @param dMovX [out] Verschiebung X
     * @param dMovY [out] Verschiebung Y
     * @param dMovZ [out] Verschiebung Z
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int GetMov ( int                iKey,
                  double            *dMovX,
                  double            *dMovY,
                  double            *dMovZ);
     //=============================================================================
     /**
     * @brief Get Scal values from transformation matrix
     *
     * @param iKey   [in]  Vorerst immer 0
     * @param dScalX [out] Skalierung X
     * @param dScalY [out] Skalierung Y
     * @param dScalZ [out] Skalierung Z
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int GetScal ( int                iKey,
                   double            *dScalX,
                   double            *dScalY,
                   double            *dScalZ);
     //=============================================================================
     /**
     * @brief Get rotation value from transformation matrix
     *
     * @param iKey  [in]  Vorerst immer 0
     * @param dRotZ [out] Rotation Z-Achse
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int GetRotZ ( int                iKey,
                   double            *dRotZ);
     //=============================================================================
     /**
     * @brief transform 2D point with tranformation matrix
     *
     * Weiterer Kommentar
     *
     * @param iKey   [in]  Vorerst immer 0
     * @param PntIn  [in]  2D-Punkt
     * @param PntOut [out] Transformierter Punkt
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int CalcPnt2 ( int               iKey,
                    sstMath01dPnt2Cls           *PntIn,
                    sstMath01dPnt2Cls           *PntOut);
     //=============================================================================
     /**
     * @brief transform 3D Point with transformation matrix
     *
     * @param iKey   [in]  Vorerst immer 0
     * @param PntIn  [in]  3D-Punkt
     * @param PntOut [out] Transformierter Punkt
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int CalcPnt3 ( int                 iKey,
                    const sstMath01dPnt3Cls   *PntIn,
                    sstMath01dPnt3Cls         *PntOut);
     //=============================================================================
     /**
     * @brief multiply two tranformation matixes
     *
     * Weiterer Kommentar
     *
     * @param iKey [in]  Vorerst immer 0
     * @param b    [in]  Zweite Transformation
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int TrnMult ( int               iKey,
                   sstMath01TrnCls   b);
     //=============================================================================
     /**
     * @brief Invert coordinate transformation
     *
     * @param c    [out]  inverted transformtion
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     //-----------------------------------------------------------------------------
     int InvertMatrix (  sstMath01TrnCls *c);
     //=============================================================================

  private:  // Private Funktionen
     double Trn[4][4];  /**< 4d transformation matrix */

};
//==============================================================================
/**
* @brief point Coordinates transformation class
*
* transformation between would coodinates and screen coordinates and back <BR>
*
* Changed: 04.01.17  Re.
*
* @ingroup sstMath01Lib
*
* @author Re.
*
* @date 04.01.17
*/
// ----------------------------------------------------------------------------
class sstMath01CoorTrnCls
{
  public:   // Public functions
     sstMath01CoorTrnCls();  // Constructor
     //=============================================================================
     /**
     * @brief transform D3-Point from world coordinate system to device system (int)
     *
     * iStat = Pnt3WC_DC ( Key, TrnWC_DC, *WC_Pnt, *DC_Pnt);
     *
     * More Comment
     *
     * Changed: 14.01.03  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param WC_Pnt   [in]  World-Coordinates
     * @param DC_Pnt   [out] Device-Coordinates
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 14.01.03
     */
     //-----------------------------------------------------------------------------
     int Pnt3WC_DC ( int             iKey,
                            sstMath01dPnt3Cls     *WC_Pnt,
                            sstMath01iPnt2Cls     *DC_Pnt);
     //=============================================================================
     /**
     * @brief transform D3-Point from world coordinate system to device system (float)
     *
     * iStat = Pnt3WC_DC2 ( Key, TrnWC_DC, *WC_Pnt, *DC_Pnt);
     *
     * More Comment
     *
     * Changed: 14.01.03  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param WC_Pnt   [in]  World-Coordinates
     * @param DC_Pnt   [out] Device-Coordinates
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 14.01.03
     */
     //-----------------------------------------------------------------------------
     int Pnt3WC_DC2 ( int             iKey,
                             sstMath01dPnt3Cls     *WC_Pnt,
                             sstMath01fPnt2Cls    *DC_Pnt);

     //=============================================================================
     /**
     * @brief transform D3-Point from world coordinate system to device system (unsigned long)
     *
     * iStat = Pnt3WC_DC3 ( Key, TrnWC_DC, *WC_Pnt, *DC_Pnt);
     *
     * DC = Database? Better use WC_DC or WC_DC2.
     *
     * Changed: 14.01.03  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param WC_Pnt   [in]  World-Coordinates
     * @param DC_Pnt   [out] Device-Coordinates
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 14.01.03
     */
     //-----------------------------------------------------------------------------
     int Pnt3WC_DC3 ( int                iKey,
                             const sstMath01dPnt3Cls  *WC_Pnt,
                             sstMath01ulPnt3Cls       *DC_Pnt);
     //=============================================================================
     /**
     * @brief transform D3-Point from world coordinate system to model coordinates.
     *
     * iStat = Pnt3WC_MC ( Key, TrnWC_MC, *WC_Pnt, *MC_Pnt);
     *
     * More Comment
     *
     * Changed: 24.01.14  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param WC_Pnt   [in]  World-Coordinates
     * @param DC_Pnt   [out] Device-Coordinates
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 24.01.14
     */
     //-----------------------------------------------------------------------------
     int Pnt3WC_MC ( int                iKey,
                            const sstMath01dPnt3Cls  *WC_Pnt,
                            sstMath01ulPnt3Cls       *DC_Pnt);
     //=============================================================================
     /**
     * @brief Transform Device Coordinate (int) in World Coordinate
     *
     * iStat = Pnt3DC_WC ( iKey, TrnDC_WC, *DC_Pnt, *WC_Pnt);
     *
     * More Comment
     *
     * Changed: 02.05.13  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param DC_Pnt   [in]  Device-Coordinates
     * @param WC_Pnt   [out] World-Coordinates (Height / Z = 0)
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 02.05.13
     */
     //-----------------------------------------------------------------------------
     int Pnt3DC_WC ( int             iKey,
                            sstMath01iPnt2Cls    *DC_Pnt,
                            sstMath01dPnt3Cls     *WC_Pnt);
     //=============================================================================
     /**
     * @brief Transform Device Coordinates (float) to World Coordinates
     *
     * iStat = Pnt3DC_WC2 ( iKey, TrnWC_DC, *DC_Pnt, *WC_Pnt);
     *
     * More Comment
     *
     * Changed: 02.05.13  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param DC_Pnt   [in]  Device-Coordinates
     * @param WC_Pnt   [out] World-Coordinates (Height / Z = 0)
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 02.05.13
     */
     //-----------------------------------------------------------------------------
     int Pnt3DC_WC2 ( int             iKey,
    //                         sstMath01TrnCls    TrnDC_WC,
                             sstMath01fPnt2Cls    *DC_Pnt,
                             sstMath01dPnt3Cls     *WC_Pnt);
     //=============================================================================
     /**
     * @brief Transform Device Coordinate (unsigned long) to World Coordinate
     *
     * iStat = Pnt3DC_WC3 ( iKey, TrnWC_DC, *DC_Pnt, *WC_Pnt);
     *
     * More Comment
     *
     * Changed: 02.05.13  UR
     *
     * @param iKey     [in]  For the moment 0
     * @param DC_Pnt   [in]  Device-Coordinates
     * @param WC_Pnt   [out] World-Coordinates (Height / Z = 0)
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 02.05.13
     */
     //-----------------------------------------------------------------------------
     int Pnt3DC_WC3 ( int             iKey,
                             sstMath01ulPnt3Cls    *DC_Pnt,
                             sstMath01dPnt3Cls     *WC_Pnt);
     //=============================================================================
     /**
     * @brief Calculate all intern coordinate transformation matrixes
     *
     * iStat = Calc_WC_DC ( iKey, &WC_Mima, ulDB_Max);
     *
     * iKey = 0; Center of Device Coordinate System is upper left  <BR>
     * iKey = 1; Center of Device Coordinate System is lower left  <BR>
     *
     * Changed: 24.04.13  UR
     *
     * @param iKey      [in]  0 or 1
     * @param WC_Mima   [in]  boundary box for world coordinates
     * @param ulDB_Max  [in]  Maximum for model (intern database) coordinates
     * @param dDC_Max   [in]  Maximum for device coordinates
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 14.01.03
     */
     //-----------------------------------------------------------------------------
     int Calc_All ( int           iKey,
                          sstMath01Mbr2Cls      WC_Mima,
                          unsigned long ulDB_Max,
                          double            dDC_Max);
     //==============================================================================
     /**
     * @brief // transform coordinates from world to device (screen)  coordinate system  <BR>
     * iStat = oCoorTrn.Transform_WC_DC(iKey, &dX, &dY);
     *
     * @param iKey  [in] For the moment 0
     * @param dX    [in out] X Value
     * @param dY    [in out] Y Value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Transform_WC_DC (int iKey, double *dX, double *dY);
     //==============================================================================
     /**
     * @brief // transform coordinates from device (screen)  to world coordinate system  <BR>
     * iStat = oCoorTrn.Transform_DC_WC(iKey, &dX, &dY);
     *
     * @param iKey  [in] For the moment 0
     * @param dX    [in out] X Value
     * @param dY    [in out] Y Value
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     */
     // ----------------------------------------------------------------------------
     int Transform_DC_WC (int iKey, double *dX, double *dY);
     //==============================================================================


  private:  // Private functions

     //=============================================================================
     /**
     * @brief Calculate WC_DC Matrix
     *
     * iStat = Calc_WC_DC ( iKey, &WC_Mima, ulDB_Max, &TrnWC_DC);
     *
     * iKey = 0; Center of Device Coordinate System is upper left  <BR>
     * iKey = 1; Center of Device Coordinate System is lower left  <BR>
     *
     * Changed: 24.04.13  UR
     *
     * @param iKey      [in]  0 or 1
     * @param WC_Mima   [in]  Min-Max-Werte Projekt
     * @param ulDB_Max  [in]  Min-Max-Werte Model
     * @param dDC_Max   [in]  Min-Max-Werte Bildschirm
     * @param TrnWC_DC  [out] WC_DC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 14.01.03
     */
     //-----------------------------------------------------------------------------
     int Calc_WC_DC ( int           iKey,
                          sstMath01Mbr2Cls      WC_Mima,
                          unsigned long ulDB_Max,
                          double            dDC_Max);

     //=============================================================================
     /**
     * @brief Calculate NPC_DC Matrix
     *
     * iStat = Calc_NPC_DC ( Key, *ScrMima, TrnNPC_DC);
     *
     * iKey = 0; Center of Device Coordinate System is upper left  <BR>
     * iKey = 1; Center of Device Coordinate System is lower left  <BR>
     *
     * Changed: 24.04.13  UR
     *
     * @param iKey:      [in]  0 or 1
     * @param ScrMima:   [in]  Min-Max-Werte Bildschirm
     * @param TrnNPC_DC: [out] NPC_DC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 16.09.02
     */
     //-----------------------------------------------------------------------------
     int Calc_NPC_DC ( int           iKey,
                           sstMath01Mbr2Cls      *ScrMima,
                       sstMath01TrnCls  *TrnNPC_DC);
     //=============================================================================
     /**
     * @brief Calculate VRC_NPC Matrix
     *
     * iStat = Calc_VRC_NPC ( Key, *WC_Mima, TrnVRC_NPC);
     *
     * More Comment
     *
     * Changed: 24.09.02  UR
     *
     * @param iKey:       [in]  For the moment 0
     * @param WC_Mima:    [in]  Min-Max-Werte
     * @param TrnVRC_NPC: [out] VRC_NPC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 16.09.02
     * */
     //-----------------------------------------------------------------------------
     int Calc_VRC_NPC ( int           iKey,
                            sstMath01Mbr2Cls      *WC_Mima,
                            sstMath01TrnCls  *TrnVRC_NPC);

     //=============================================================================
     /**
     * @brief Calculate NPC_MC Matrix
     *
     * More Comment
     *
     * @param iKey       [in]  For the moment 0
     * @param ulDB_Max   [in]  DataBase-Max
     * @param TrnNPC_MC  [out] NPC_MC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @date 16.09.02
     * */
     //-----------------------------------------------------------------------------
     int Calc_NPC_MC ( int           iKey,
                           unsigned long ulDB_Max,
                       sstMath01TrnCls  *TrnNPC_MC);
     //=============================================================================
     /**
     * @brief Calculate WC_VRC Matrix
     *
     * iStat = Calc_WC_VRC ( Key, *WC_Mima, TrnWC_VRC);
     *
     * Verschiebung der Min-Max-Werte in den Nullpunkt.
     *
     * Changed: 24.09.02  UR
     *
     * @param iKey:      [in]  For the moment 0
     * @param WC_Mima:   [in]  Min-Max-Werte
     * @param TrnWC_VRC: [out] WC_VRC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 16.09.02
     */
     //-----------------------------------------------------------------------------
     int Calc_WC_VRC ( int           iKey,
                           sstMath01Mbr2Cls      *WC_Mima,
                           sstMath01TrnCls  *TrnWC_VRC);
     //=============================================================================
     /**
     * @brief Calculate WC_MC Matrix
     *
     * iStat = Calc_WC_MC (  iKey,  *WC_Mima, ulDB_Max, TrnWC_MC);
     *
     * Verschiebung der Min-Max-Werte in den Nullpunkt.
     *
     * Changed: 24.09.02  UR
     *
     * @param iKey      [in]  For the moment 0
     * @param WC_Mima   [in]  Min-Max-Werte
     * @param ulDB_Max  [in]  Min-Max-Werte
     * @param TrnWC_MC  [out] WC_VRC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 16.09.02
     */
     //-----------------------------------------------------------------------------
     int Calc_WC_MC ( int           iKey,
                          sstMath01Mbr2Cls      *WC_Mima,
                          unsigned long ulDB_Max);
//                          sstMath01TrnCls  *TrnWC_MC);
     //=============================================================================
     /**
     * @brief Calculate MC_WC Matrix
     *
     * iStat = Calc_MC_DC ( Key, ulDB_Max, dDC_Max, TrnMC_DC);
     *
     * Verschiebung der Min-Max-Werte in den Nullpunkt.
     *
     * Changed: 24.09.02  UR
     *
     * @param iKey:    [in]  For the moment 0
     * @param ulDB_Max [in]  Min-Max-Werte
     * @param dDC_Max  [in]  Min-Max-Werte
     * @param TrnMC_DC [out] WC_VRC_Transformation
     *
     * @return Errorstate
     *
     * @retval   = 0: OK
     * @retval   < 0: Unspecified Error
     *
     * @author ur
     *
     * @date 16.09.02
     */
     //-----------------------------------------------------------------------------
     int Calc_MC_DC ( int           iKey,
                          unsigned long ulDB_Max,
                          double        dDC_Max);
//                          sstMath01TrnCls  *TrnMC_DC);
     //-----------------------------------------------------------------------------
     sstMath01TrnCls sTrnWC_DC;  // coordinate transformation from world to device
     sstMath01TrnCls sTrnWC_MC;  // coordinate transformation from world to model
     sstMath01TrnCls sTrnMC_DC;  // coordinate transformation from model to device
     sstMath01TrnCls sTrnDC_WC;  // coordinate transformation from device to World
};
//==============================================================================
/**
* @brief Plane Class
*
* Weiterer Kommentar
*
* Geändert: 19.01.04  Re.
*
* 19.01.04: Doxygen-Kommentar ausgeweitet.  UR
*
* @ingroup sstMath01Lib
*
* @author Re
*
* @date 16.09.99
*/
// ----------------------------------------------------------------------------
class sstMath01Plane
{
  public:   // Public functions
     sstMath01Plane();   // Constructor
    // ~sstMath01Plane();   // Destructor
// ----------------------------------------------------------------------------
     double   a;         /**< Ebene: ax + by + cz = d */
     double   b;         /**< Ebene: ax + by + cz = d */
     double   c;         /**< Ebene: ax + by + cz = d */
     double   d;         /**< Ebene: ax + by + cz = d */
  private:  // Private functions
};
//-----------------------------------------------------------------------------



// Prototypen  geo_wink.cpp ------------------------------------------------------

#endif


// ------------------------------------------------------------------- Ende ----
