#include "sala.h"
#include <math.h>

using namespace std;

sala::sala()
{
    this->wysokosc=10; /*!< wysokość pomieszczenia [m] */
    this->szerokosc=25; /*!< szerokość pomieszczenia [m] */
    this->dlugosc=40; /*!< długość pomieszczenia [m] */
    this->liczbaOsob=50; /*!< liczba osób w pomieszczeniu */
    this->wspK=0.23; /*!< współczynnik przenikania ciepła dla ściany [W/m2*K] */
}

sala::~sala()
{

}

/**
* Funkcja oblicza objętość sali.
* Pobiera trzy wartości double i zwraca wartość double.
*
* \param[in] dlugosc długość sali.
* \param[in] szerokosc szerokosc sali.
* \param[in] wysokość sali.
*/
double sala::Vsala(double l, double w, double h)
{
    double V;
    V=this->dlugosc*this->wysokosc*this->szerokosc;
    return V;
}

/**
* Funkcja oblicza maksymalną liczbę osób, która zmieści się w sali (=40% powierzchni sali).
*
* \param[in] dlugosc długość sali.
* \param[in] szerokosc szerokosc sali.
*/
int sala::maxOsob()
{
    int maxO;
    maxO=round(this->dlugosc*this->szerokosc*0.4);
    return maxOsob();
}

/**
 * @brief sala::Qprzen
 * @return straty ciepła [kW]
 * Funkcja oblicza straty ciepła przez przenikanie[W].
 * Przyjęto, iż najdłuższa ściana sali jest ścianą zewnętrzną.
 * Jeśli straty są mniejsze od zera (Qstr<0) wtedy występują zyski ciepła
 * \param[in] tempZewn temperatura zewnętrzna
 */
void sala::Qprzen(double tempZewn, double tempWewn)
{
    this->QprzS=this->dlugosc*this->wysokosc*this->wspK*(tempWewn-tempZewn); /**< Straty ciepła przez przenikanie [kW] */
}

/**
 * @brief sala::Qludzie
 * @param liczbaOsobS - liczba osób w sali
 * @return [W] zyski ciepła od ludzi
 * Funkcja oblicza zyski ciepła od ludzi
 */
void sala::Qludzie(int &liczbaOsobS)
{
    double lOsobSala;
    lOsobSala = double (liczbaOsobS);
    this->QludzS=lOsobSala*95.0;

}



