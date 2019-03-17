#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<sstream>
#include<iostream>
#include<fstream>
#include<string>
#include <unistd.h> /*!< opóźnienie w programie [ms] */
#include <sala.h>
#include <centralawent.h>
#include <klimakonwektor.h>
#include <powietrzesala.h>
#include <sterownik.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    CentralaWent centrala;
    klimakonwektor klimakonwektor;
    PowietrzeSala powietrze;
    sala kino;
    sterownik sterCentr;
    sterownik sterKlim;
    double *signalCentrala; /*!< pomiar CO2 w powietrzu wewnętrznym [ppm] */
    double *setpointCentrala; /*!< stężenie zadane CO2 w powietrzu wewnętrznym [ppm] */
    double *signalKlimakonwektor; /*!< pomiar TEMPERATURY w powietrzu wewnętrznym [ppm] */
    double *setpointKlimakonwektor; /*!< pomiar TEMPERATURY w powietrzu wewnętrznym [ppm] */
    double *AOcentrala; /*!< AnalogOutput  dla centrali */
    double *AOklimakonwektor; /*!< AnalogOutput  dla klimakonwektora */
    int *liczbaOsob; /*!< liczba osób w sali] */
    double *tSala; /*!< temperatura chwilowa sali] */
    double *Qprz; /*!< straty przenikania ciepła [W] */
    double *Qludz; /*!< zyski ciepła od ludzi [W] */






private slots:
    void on_lineEdit_dlugosc_returnPressed();

    void on_lineEdit_szerokosc_returnPressed();

    void on_lineEdit_wysokosc_returnPressed();

    void on_lineEdit_liczbaOsob_returnPressed();

    void on_lineEdit_wspK_returnPressed();

    void on_lineEdit_tempPom_returnPressed();

    void on_lineEdit_tempZewn_returnPressed();

    void on_lineEdit_CO2sala_returnPressed();

    void on_lineEdit_CO2naOsobe_returnPressed();

    void on_lineEdit_zyskiOdLudzi_returnPressed();

    void on_pushButton_Start_clicked();

    void on_pushButton_Stop_clicked();

    void pokazCO2(double &CO2);


signals:

    void valueChanged(double CO2);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
