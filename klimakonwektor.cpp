#include "klimakonwektor.h"

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
        this->QklimK=Vsala*10*AOklimakonwektor/10; /**< 10 W/m3 sali */;
    //! Tryb chłodzenia klimakonwektora
    /*!
     jeżeli tempertura zadana<od temp w pomieszczeniu
    */

    if (tempZadana<tempChwil)
        this->QklimK=Vsala*15*AOklimakonwektor/10; /**< 15 W/m3 sali */;
}

