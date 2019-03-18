#ifndef SALA_H
#define SALA_H


class sala
{
public:
    sala();
    ~sala();
    double Vsala(double l, double w, double h);
    int maxOsob();
    void Qprzen(double tempZewn, double tempWewn, double &QprzenS);
    void Qludzie(int &liczbaOsobS, double &QludzS);


    double wysokosc;
    double szerokosc;
    double dlugosc;
    double VsalaObl; /*!< przechowuje objętośc sali */
    int liczbaOsob;
    double wspK; /*!< współczynnik przenikania ciepła */

};

#endif // SALA_H
