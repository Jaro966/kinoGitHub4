#include "klimakonwektor.h"
#include "klimakonwektorszablon.h"

klimakonwektor::klimakonwektor()
{

}

klimakonwektor::~klimakonwektor()
{

}

/**
 * @brief klimakonwektor::Qklim
 * @param tempZadana
 * @param tempChwil - temp. w pomieszczeniu
 * @param Vsala - objętość sali
 * @param AOklimakonwektor - sygnał ze sterownika
 * @param QklimK - moc klimakonwektora [W]
 */



void klimakonwektor::Qklim(double tempZadana, double tempChwil, double Vsala, double &AOklimakonwektor, double &QklimK)
{
    //! Tryb grzania klimakonwektora
    /*!
     jeżeli tempertura zadana>od temp w pomieszczeniu
    */
    if (tempZadana>tempChwil)
        QklimK=Vsala*10*AOklimakonwektor/10; /**< 10 W/m3 sali */;
    //! Tryb chłodzenia klimakonwektora
    /*!
     jeżeli tempertura zadana<od temp w pomieszczeniu
    */

    if (tempZadana<tempChwil)
        QklimK=-Vsala*25*AOklimakonwektor/10; /**< 25 W/m3 sali */;
}

/**
 * @brief klimakonwektor::QklimSzK
 * @param tempZadana
 * @param tempChwil
 * @param Vsala
 * @param AOklimakonwektor
 * @param QklimK
 * Szablon do obliczenia mocy klimakonwektora
 * Funkcjonalność identyczna jak funkcji Qklim (powyżej)
 */
void klimakonwektor::QklimSzK (double tempZadana, double tempChwil, double Vsala, double &AOklimakonwektor, double &QklimK )
{
    QklimSz(tempZadana, tempChwil, Vsala, AOklimakonwektor, QklimK);
}

