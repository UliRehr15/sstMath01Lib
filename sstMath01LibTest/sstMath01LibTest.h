// Blanko.h   29.04.10  Re.   29.04.10  Re.
//
// Datastructures and Prototypes for system "Blanko"
//

#ifndef   _BLANKO_HEADER
#define   _BLANKO_HEADER

// Defines ---------------------------------------------------------------------

#define dFINFO_NAM_LEN   12    /**< Irgendeine Erläuterung zum Define @ingroup _bspiele */

/**
 * @brief Erweiterte Möglichkeit, ein Define zu kommentieren
 * @ingroup _bspiele
 */
#define dKODE_MIN

// Strukturen und Klassen ------------------------------------------------------

//==============================================================================
/**
* @brief Definition Structure Dum_stru
*
* More Comment <BR>
* More Comment <BR>
* More Comment <BR>
* More Comment <BR>
*
* Changed: 19.02.10  Re.
*
* @ingroup examples
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
struct _Dum_stru
{
  int Dum;        /**< Dummy */
};
typedef struct _Dum_stru Dum_stru;

//==============================================================================
/**
* @brief Definition Klasse X
*
* More Comment
*
* Changed: 19.02.10  Re.
*
* @ingroup examples
*
* @author Re.
*
* @date 19.02.10
*/
// ----------------------------------------------------------------------------
class X
{
  public:   // Öffentliche Funktionen
     X();  // Konstruktor
    ~X();  // Destruktor
  private:  // Private Funktionen
  int Dum;        /**< Dummy */
};
//-----------------------------------------------------------------------------


//------------------------------------------------------------------------------

// Prototypen datei.c ----------------------------------------------------------

//==============================================================================
/**
* @brief Shortstory
*
* iStat = Blanko ( iKey);
*
* More Comment
*
* Changed: 16.02.10  Re.
*
* @ingroup examples
*
* @param iKey: [in] For the moment 0
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
int Blanko ( int iKey);
//------------------------------------------------------------------------------

#endif

// ------------------------------------------------------------------- Ende ----
