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
     * @param X     [in]     Prüfwert: Punkt-X
     * @param Y     [in]     Prüfwert: Punkt-Y
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Koor2 ( int      iKey,   // Vorerst immer 0
                       double   X,     // Prüfwert: Punkt-X
                       double   Y);    // Prüfwert: Punkt-Y
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
     * @param Pkt   [in]     Prüfwert: D2-Punkt
     *
     * @return Fehlerstatus
     *
     * @retval   =0 = OK
     * @retval   <0 = allgemeiner Fehler
     */
     int Pkt2( int         iKey,   // v -> Key vorerst immer 0
                     sstMath01dPnt2Cls *Pkt);   //   -> Prüfwert: D2-Punkt

     //==============================================================================
     /**
     * @brief Koordinate mit Min-Max überprüfen
     *
     * iStat = Mia_2Pruef_c ( Key, *Mima, X, Y);
     *
     * Prüfen, ob eine Koordinate innerhalb der Min-Max-Werte liegen.
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in] Vorerst immer 0
     * @param X     [in] Prüfwert: Punkt-X
     * @param Y     [in] Prüfwert: Punkt-Y
     *
     * @return Fehlerstatus
     *
     * @retval     0 : Prüfpunkt liegt innerhalb
     * @retval bit 0 : X außerhalb der Min-Max-Werte
     * @retval bit 1 : Y außerhalb der Min-Max-Werte
     * @retval    -1 : Feld Mima nicht korrekt
     * @retval   -10 : unzulässiger Key <> 0
     */
     int Pruef2 ( int      iKey,   // Vorerst immer 0
                        double   X,     // Prüfwert: Punkt-X
                        double   Y);    // Prüfwert: Punkt-Y

     //==============================================================================
     /**
     * @brief Koordinate mit Min-Max überprüfen
     *
     * iStat = Mia_2Pruef_c ( Key, *Mima, X, Y);
     *
     * Prüfen, ob eine Koordinate innerhalb der Min-Max-Werte liegen.
     *
     * Geändert: 06.02.03  UR
     *
     * @param iKey  [in] Vorerst immer 0
     * @param X     [in] Prüfwert: Punkt-X
     * @param Y     [in] Prüfwert: Punkt-Y
     * @param Tol   [in] Tolerance Value
     *
     * @return Fehlerstatus
     *
     * @retval     0 : Prüfpunkt liegt innerhalb
     * @retval bit 0 : X außerhalb der Min-Max-Werte
     * @retval bit 1 : Y außerhalb der Min-Max-Werte
     * @retval    -1 : Feld Mima nicht korrekt
     * @retval   -10 : unzulässiger Key <> 0
     */
     int PruefT2( int    iKey,    // v  -> Key vorerst immmer 0
                        double   X,      // v  -> Prüfwert: Punkt-X
                        double   Y,      // v  -> Prüfwert: Punkt-Y
                        double   Tol);    // v  -> Toleranzwert
     //==============================================================================
     /**
     * @brief Test, ob Überdeckung vorliegt
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
     * @retval   =1: Boxen berühren sich oder überdecken sich
     * @retval   =0: Keine Überdeckung oder Berührung
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
     * Key = 6 : Rückgabe in D: Länge X
     * Key = 7 : Rückgabe in D: Länge Y
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
     * Skalierungswert  = 1.0: Keine Änderung
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
  public:   // Öffentliche Funktionen
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
//-----------------------------------------------------------------------------

// Prototypen  geo_wink.cpp ------------------------------------------------------

#endif


// ------------------------------------------------------------------- Ende ----

