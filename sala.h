#ifndef SALA_H
#define SALA_H


class sala
{
public:
    sala();
    ~sala();
    double Vsala(double l, double w, double h);
    int maxOsob();
    void Qprzen(double tempZewn, double tempWewn);
    void Qludzie(int &liczbaOsobS);


    double wysokosc;
    double szerokosc;
    double dlugosc;
    double VsalaObl; /*!< przechowuje objętośc sali */
    int liczbaOsob;
    double QprzS;
    double QludzS;
    double wspK; /*!< współczynnik przenikania ciepła */

};

#endif // SALA_H
