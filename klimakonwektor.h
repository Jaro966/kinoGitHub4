#ifndef KLIMAKONWEKTOR_H
#define KLIMAKONWEKTOR_H


class klimakonwektor
{
public:
    klimakonwektor();
    ~klimakonwektor();


    void Qklim (double tempZadana, double tempChwil, double Vsala, double &AOklimakonwektor, double &QklimK);
    void QklimSzK (double tempZadana, double tempChwil, double Vsala, double &AOklimakonwektor, double &QklimK );


};

#endif // KLIMAKONWEKTOR_H
