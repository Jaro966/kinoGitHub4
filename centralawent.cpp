#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <complex>
#include <qstring.h>

#include "centralawent.h"


CentralaWent::CentralaWent()
{
    tempZewn=32;
    stezCO2zewn=400;
}

CentralaWent::~CentralaWent()
{

}

/**
 * @brief CentralaWent::Vcentrali
 * @param liczbaOsob - liczba osób w sali (sala->liczbaOsob)
 * @param AOcentrala - wyjście na sterowniku (0...10V)
 * Funkcja oblicza chwilową wydajność centrali
 * Maksymalna wydajność: Vmax = liczba osób * 45 m3/h
 * Minimalna wydajność: Vmin = 30%*Vmax (wynika z charakterystyki wentylatora)
 */
void CentralaWent::Vcentrali(int &liczbaOsob, double &AOcentrala)
{
    double lOsobCentr;
    lOsobCentr = double (liczbaOsob);
    double AOcentralaWewn = AOcentrala;

    /*!
    Równanie na wydajność chwilową
    Vch=liczbaOsób*(45 [m3/h]/3600)*30% + liczbaOsób*45 [m3/h]*70%*AOcentral/10
    AOcentral/10 - dzielenie przez 10 sprowadza sygnał 0...10V do zakresu <0,1>
    */
    this->VchCentrali=(lOsobCentr*45)/3600*(0.3+0.7*AOcentralaWewn/10);

}
