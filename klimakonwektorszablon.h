#ifndef KLIMAKONWEKTORSZABLON_H
#define KLIMAKONWEKTORSZABLON_H

template<typename KlimSz> KlimSz QklimSz(KlimSz tempZadana, KlimSz tempChwil, KlimSz Vsala, KlimSz &AOklimakonwektor, KlimSz &QklimK )
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



#endif // KLIMAKONWEKTORSZABLON_H
