#ifndef CENTRALAWENT_H
#define CENTRALAWENT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <complex>
#include <qstring.h>
#include "powietrzesala.h"
#include "sterownik.h"
#include "sala.h"

using namespace std;


class CentralaWent
{
public:
    CentralaWent();
    ~CentralaWent();
    void Vcentrali(int &liczbaOsob, double &AOcentrala);
    void Qcentrali();

    double tempZewn;
    double stezCO2zewn;
    double VchCentrali;

    sterownik PLCcentrala;


};

#endif // CENTRALAWENT_H
