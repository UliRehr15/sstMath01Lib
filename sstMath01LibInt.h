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
// sstMath01LibInt.h   30.12.16  Re.   30.12.16  Re.
//
// Intern Datastructures and Prototypes for system "sstMath01Lib"
//

#ifndef   _SST_MATH01_LIB_INT_HEADER
#define   _SST_MATH01_LIB_INT_HEADER

// Defines ---------------------------------------------------------------------


// Structures and Classes ------------------------------------------------------

/**
 *  Defines rund um PI
 *
 *  Hier sind alle Defines die mit PI zusammenhängen definiert.
*/
#define RHO20    63.6619772367581343055     /** RHO20 = 200.0 gon / PI  @ingroup Geometrie */
#define RHO18    57.2957795130823208767     /** RHO18 = 180.0 Grad/ PI  @ingroup Geometrie */
#define GON      0.01570796326794896619     /** Rad-Wert für ein Gon    @ingroup Geometrie */
#define GRAD     0.01745329251994329576     /** Rad-Wert fÜr ein Grad   @ingroup Geometrie */



//............................................Strukturen und Typdefinitionen....


//...............................................................Returnwerte....

/**
 *  Returnwerte für 2D- und 3D-Geomet-Funktionen
 *
 *  Hier sind Returnwerte für die 2- und 3-dimensionalen Geometrie-
 *  Funktionen definiert.
*/

#define D2_OK         0      /** Alles OK                                  @ingroup Geometrie */
#define D2_PARALLEL  -1      /** Fehler: parallel oder unscharf            @ingroup Geometrie */
#define D2_AUSSEN    -2      /** Fehler: Gearade außerhalb Kreis           @ingroup Geometrie */

#define D3_OK         0      /** Alles OK                                  @ingroup Geometrie */
#define D3_PARALLEL  -1      /** Fehler: Gerade/Ebene parallel (zur Ebene) @ingroup Geometrie */
#define D3_SENKR     -2      /** Fehler: Gerade sekrecht (zur Ebene)       @ingroup Geometrie */

#define dMATDIM   4    /**< Dimension der Matrizen @ingroup mathem */


/**
* @brief Struktur für Funktionübergabe von Koordinaten-Transformationen
*
* Sollen unter ANSI-C Arrays an Unterprogramme übergeben werden, muß eine
* spezielle Form gewählt werden.
* Vermutlich läßt sich das auch irgendwie eleganter lösen.
*
* @ingroup mathem
*
* @author ur
*
* @date 24.06.04
*/
struct _d4Pnt_stru
{
   double Kor[4];
};
typedef struct _d4Pnt_stru d4Pnt_stru;



#endif

// ------------------------------------------------------------------- Ende ----
