#include "powietrzesala.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <complex>
#include <qstring.h>

//! Klasa opisująca parametry powietrza wewnętrznego
/*!
 Klasa oblicza temperaturę chwilową powietrza
 oraz chwilowe stężenie CO2
 */

PowietrzeSala::PowietrzeSala()
{
    this->CO2zadaneSala=800; /*!< stężenie zadane CO2 w powietrzu wewnętrznym [ppm] */
    this->emisjaCO2osoba=4.1667; /*!< emisja CO2 przez 1 osobę [m3 CO2/sx10e-6] */
    this->zyskiCieplaOsoba=0.095; /*!< zyski ciepła od 1 osoby [kW] */
    this->CO2zadaneZewn=400; /*!< stężenie zadane CO2 w powietrzu zewnętrznym [ppm] */
    this->CO2chwilSali=450;
    this->tempZadanaSali=20; /*!< temperatura chwilowa w pomieszczeniu [deg C] */
    this->tempChwilSali=20;
}

/**
 * @brief PowietrzeSala::obliczTempSali
 * @param QchwCentr moc centrali wentylacyjnej [kWat]
 * @param QchwKlima moc klimakonwektora [kWat]
 * @param Qprzen straty ciepła przez przenikanie, jeśli Qprzen<0 to opisuje zyski ciepła przez przenikanie [kWat]
 * @param Vs objętość pomieszczenia [m3]
 * @param *tSala temperatura zadana pomieszczenia [deg C]
 * @return temperatura chwilowa pomieszczenia przekazywana przez wskźnik
 * Temperatura obliczana jest w interwalłach co 1 sekunda
 * Funkcja pezekazuje przez wskaźnik wartość chwilową
 */
void PowietrzeSala::obliczTempSali(double QprzenP, double QludzP, double QklimP, double VsaliP, double &tSala)
{
    double m; /**< masa powietrza w objętości pomieszczenia [kg] */
    double cp=2.2; /**< ciepło właściwe powietrza = 2.2 [kJ/kg*K] */
    double sumaQ; /**< bilans mocy [kW]*/


    m=VsaliP*1.2;  /**< masa powietrza [kg], 1,20 - gęstość powietrza dla 20 st. C i 45%  */

    //! Bilans mocy
    /*!
     Równanie na bilans mocy
     Ponieważ interwał czasowy to 1 sekunda
     Jest to również równanie na bilans energii dostarczonej w 1 sekundzie
    */
    sumaQ=QprzenP+QludzP+QklimP;

    //! Temp. chwilowa
    /*!
      Oblicza temperaturę chwilową w sali
    */
    tSala=(sumaQ/1000)/(m*cp)+tSala;

}

/**
 * @brief PowietrzeSala::obliczCO2wSali [ppm] - chwilowe stężenie CO2
 * @param Vch [m3/h] - przepływ chwilowy powietrza
 * @param liczbaOsob
 * @param Vkina - objętość kina
 * @param Co2Sala - wartość stężenia CO2 w sali [ppm]=this.CO2Sali
 * Funkcja oblicza chwilowe stężenie CO2 w powietrzu
 */
void PowietrzeSala::obliczCO2wSali(double Vch, int &liczbaOsob, double Vkina, double &Co2Sala)
{
    double lOsob;
    lOsob = double (liczbaOsob);
    this->CO2chwilSali=1/Vkina*(Vkina*Co2Sala+Vch*this->CO2zadaneZewn+this->emisjaCO2osoba*lOsob
                               -Vch*Co2Sala);
    Co2Sala=this->CO2chwilSali;

}



PowietrzeSala::~PowietrzeSala()
{

}



