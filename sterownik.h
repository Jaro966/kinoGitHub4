#ifndef STEROWNIK_H
#define STEROWNIK_H


class sterownik
{
public:
    sterownik();
    ~sterownik();
    void AO(double &signal, double &setpoint);
    double AI();
    double u(double &signal, double &setpoint); /**< oblicza odchyłke u=signal-setpoint */
    double p(); /**< część proporcjonalna */
    double i(); /**< część całkująca */
    double d(); /**< część różniczkująca */

    double k; /**< wsp. proporcjonalności */
    double ki; /**< stała całkowania */
    double kd; /**< stała różniczkowania */
    double umodule; /**< odchyłka - wartość */
    double umodule_old; /**< odchyłka - wartość poprzednia */
    double pmodule; /**< część proporcjonalna - wartość */
    double imodule; /**< część całkująca - wartość */
    double dmodule; /**< część różniczkująca - wartość */
    double AOsignal; /**< sygnał na wyjściu AO */


};



#endif // STEROWNIK_H
