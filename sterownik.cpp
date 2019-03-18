#include "sterownik.h"

sterownik::sterownik()
{
    this->k=2;
    this->ki=3;
    this->kd=2;
    this->umodule=0;
    this->umodule_old=this->umodule;
    this->pmodule=0;
    this->imodule=0;
    this->dmodule=0.0;
    this->AOsignal=0.0;
}
sterownik::~sterownik()
{

}
/**
 * @brief sterownik::u - oblicza odchyłkę sterowania
 * @param signal - sygnał wejściowy
 * @param setpoint - wartość zadana
 * @return u=signal-setpoint
 */
double sterownik::u(double &signal, double &setpoint)
{
    this->umodule=signal-setpoint;
    return this->umodule;
}
/**
 * @brief sterownik::p oblicza wartość części proporcjonalnej p=k*ui
 * @return
 */
double sterownik::p()
{
    this->pmodule=this->k*this->umodule; /**< p=k*u(n) */
    return this->pmodule; /**< p */
}
/**
 * @brief sterownik::i oblicza wartość częśći całkującej i=ki*SUMA(ui)
 * @return this
 *
 */
double sterownik::i()
{
    this->imodule=this->imodule+this->umodule*this->ki; /**< i = ki*SUMA(un) */
    return this->imodule; /**< i */
}
/**
 * @brief sterownik::d oblicza wartość części różniczkującej d
 * @return
 */
double sterownik::d()
{
    this->dmodule=this->kd*(this->umodule-this->umodule_old); /**< d=kd[u(n)-u(n-1)] */
    this->umodule_old=this->umodule; /**< u(n-1)=u(n) */
    return this->dmodule; /**< d */
}

/**
 * @brief sterownik::AO - oblicza sygnał na wyjściu AO sterownika
 * @param signal
 * @param setpoint
 * @return
 */
void sterownik::AO(double &signal, double &setpoint, double &AOs)
{
    this->u(signal, setpoint); /**< liczy odchyłkę: u = signal - setpoint */
    this->p(); /**< p */
    this->i(); /**< i */
    this->d(); /**< d */
    this->AOsignal=(this->pmodule+this->imodule+this->dmodule)*10.0; /**< AO=(p+i+d)*10V - sygnał 0...10V */
    AOs=(this->pmodule+this->imodule+this->dmodule)*10.0; /**< AO=(p+i+d)*10V - sygnał 0...10V */
    //! Filtr sygnału AO.
    /*!
          Filtruje do zakresu 0...10V
        */
    if (this->AOsignal>10)
        this->AOsignal=10;
    if (this->AOsignal<0)
        this->AOsignal=0;

    if (AOs>10)
        AOs=10;
    if (AOs<0)
        AOs=0;

}




