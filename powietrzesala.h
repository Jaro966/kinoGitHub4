/**
* Klasa PowietrzeSala służy do modelowania parametrów powietrza - temperatury i stężenia CO2.
* Pobiera trzy wartości typu int i zwraca wartość typu bool.
*
* \param[in] CO2zadaneSala wartość zadana stężenia CO2 wyrażona w ppm (objętościowo).
* \param[in] emisjaCO2osoba wartość emisji CO2 na 1 osobę wyrażona w litrach CO2/(osoba x godz).
* \param[in] zyskiCieplaOsoba wartość zysków ciepła generowanych przez 1 osobę wyrażone w Watach.
* \return true jeśli da się zbudować trójkąt, false w przeciwnym wypadku
*/

#ifndef POWIETRZESALA_H
#define POWIETRZESALA_H
#include "sala.h"



class PowietrzeSala
{


public:
    PowietrzeSala();
    ~PowietrzeSala();

    double CO2zadaneSala; /**< stężenie CO2 zadane w sali - setpoint CO2 */
    double emisjaCO2osoba; /**< emisja CO2 przez 1 osobę - wartość domyślna w konstruktorze*/
    double zyskiCieplaOsoba; /**< zyski ciepła od jednej osoby - wartość domyślna w konstruktorze */
    double CO2zadaneZewn; /**< zawartość CO2 w powietrzu zewnętrznym - wartość domyślna w konstruktorze */
    double tempChwilSali; /**< przechowuje temperaturę chwilową sali */
    double tempZadanaSali; /**< przechowuje temperaturę zadaną sali */
    double CO2chwilSali; /**< przechowuje stężenie chwilowe sali */


    void obliczTempSali(double QprzenP, double QludzP, double QklimP, double VsaliP, double &tSala);
    void obliczCO2wSali(double Vchw, int &liczbaOsob, double Vkina, double &CO2Sala);

};

#endif // POWIETRZESALA_H
