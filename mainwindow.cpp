#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    signalKlimakonwektor = new(double); /**< temperatura chwilowa w sali=odczyt temperatury w strerowniku klimakonw. */
    setpointKlimakonwektor=new(double); /**< temperatura zadana sali = nastawa klimakonwektora */
    AOklimakonwektor=new(double); /**< AnalogOutput dla klimakonwektora */
    Qprz=new(double);  /**< ciepło przenikania */
    Qludz=new(double); /*!< zyski ciepła od ludzi [W] */
    Qklim=new(double); /*!< moc klimakonwektora [W] */
    signalCentrala=new(double); /**< Stężenie CO2 w sali. Równoważne odczytowi z czujnika CO2 */
    setpointCentrala=new(double); /**< Zadane CO2 */
    liczbaOsob=new(int);
    AOcentrala=new(double); /**< AnalogOutput dla centrali wentylacyjne */

}

MainWindow::~MainWindow()
{
    delete ui;

    delete signalKlimakonwektor;
    delete setpointKlimakonwektor;
    delete AOklimakonwektor;
    delete Qprz;
    delete Qludz;
    delete Qklim;
    delete signalCentrala;
    delete setpointCentrala;
    delete liczbaOsob;
    delete AOcentrala;

}


void MainWindow::on_lineEdit_dlugosc_returnPressed()
{
    kino.dlugosc=ui->lineEdit_dlugosc->text().toDouble();
    ui->lineEdit_dlugosc->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}


void MainWindow::on_lineEdit_szerokosc_returnPressed()
{
    kino.szerokosc=ui->lineEdit_szerokosc->text().toDouble();
    ui->lineEdit_szerokosc->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}


void MainWindow::on_lineEdit_wysokosc_returnPressed()
{
    kino.wysokosc=ui->lineEdit_wysokosc->text().toDouble();
    ui->lineEdit_wysokosc->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}



void MainWindow::on_lineEdit_liczbaOsob_returnPressed()
{
    kino.liczbaOsob=ui->lineEdit_liczbaOsob->text().toInt();
    ui->lineEdit_liczbaOsob->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}



void MainWindow::on_lineEdit_wspK_returnPressed()
{
    kino.wspK=ui->lineEdit_wspK->text().toDouble();
    ui->lineEdit_wspK->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}



void MainWindow::on_lineEdit_tempPom_returnPressed()
{
    powietrze.tempZadanaSali=ui->lineEdit_tempPom->text().toDouble();
    ui->lineEdit_tempPom->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}


void MainWindow::on_lineEdit_tempZewn_returnPressed()
{
    centrala.tempZewn=ui->lineEdit_tempZewn->text().toDouble();
    ui->lineEdit_tempZewn->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}



void MainWindow::on_lineEdit_CO2sala_returnPressed()
{
    powietrze.CO2zadaneSala=ui->lineEdit_CO2sala->text().toDouble();
    ui->lineEdit_CO2sala->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}



void MainWindow::on_lineEdit_CO2naOsobe_returnPressed()
{
    powietrze.emisjaCO2osoba=ui->lineEdit_CO2naOsobe->text().toDouble();
    powietrze.emisjaCO2osoba=powietrze.emisjaCO2osoba/(3.6); /**< this->emisjaCO2osoba/(3.6) - zamiana z [l/h] na [m3/h*1e-6]  */
    ui->lineEdit_CO2naOsobe->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}

void MainWindow::on_lineEdit_zyskiOdLudzi_returnPressed()
{
    powietrze.zyskiCieplaOsoba=ui->lineEdit_zyskiOdLudzi->text().toDouble();
    ui->lineEdit_zyskiOdLudzi->setStyleSheet("QLineEdit { background: rgb(66, 244, 72); selection-background-color: rgb(233, 99, 0); }");
}

/**
 * @brief MainWindow::on_pushButton_Start_clicked
 */

void MainWindow::on_pushButton_Start_clicked()
{
    //! Dane do obliczenia chwilowej temperatury
    /*!
     */
    *signalKlimakonwektor = powietrze.tempChwilSali; /**< ustawienie temperatury początkowej w sali*/
    *setpointKlimakonwektor=powietrze.tempZadanaSali; /**< ustawienie temperatury zadanej w sali */
    //! Dane do obliczenia chwilowego CO2
    /*!
     */
    signalCentrala=&powietrze.CO2chwilSali;
    setpointCentrala=&powietrze.CO2zadaneSala;
    *liczbaOsob=kino.liczbaOsob;


    centrala.Vcentrali(*liczbaOsob, *AOcentrala); /**< Uruchomienie centrali. Ustalenie wydatku */

    for (int i=0; i<3600;i++)
    {
        //! Wyświetlacz LCD
        /*!
        */

        //QObject::connect(&powietrze, &valueChanged(*signalCentrala), &powietrze, setValue(*signalCentrala));
        ui->lcdNumber_CO2->display(*signalCentrala);
        pokazCO2(*signalCentrala);
        usleep(500);

        kino.VsalaObl=kino.Vsala(kino.dlugosc, kino.szerokosc, kino.wysokosc); /*!< oblicza objętość sali */
        powietrze.obliczCO2wSali(centrala.VchCentrali, *liczbaOsob, kino.VsalaObl, *signalCentrala); /*!< oblicza stęż. CO2 chwilowe */
        sterCentr.AO(*signalCentrala, *setpointCentrala, *AOcentrala); /*!< oblicza wyjście sterownika 0...10V */
        centrala.Vcentrali(*liczbaOsob, *AOcentrala); /*!< wyznacza strumień chwilowy centrali [m3/s] */








    //! Obliczenie sygnału sterującego do klimakonwektora
    /*!
     */
    sterKlim.AO(*signalKlimakonwektor, *setpointKlimakonwektor, *AOklimakonwektor);

    //! Obliczenie strat ciepła i mocy klimakonwektora
    /*!
     */
    kino.Qludzie(*liczbaOsob, *Qludz);
    kino.Qprzen(centrala.tempZewn, powietrze.tempChwilSali, *Qprz);
    klimakonwektor.Qklim(*setpointKlimakonwektor, *signalKlimakonwektor, kino.VsalaObl, *AOklimakonwektor, *Qklim);
    powietrze.obliczTempSali(*Qprz, *Qludz, *Qklim, kino.VsalaObl, *signalKlimakonwektor);
    cout<<"i = "<<i<<" stez CO2= "<< *signalCentrala<<" Tsali = "<<*signalKlimakonwektor<< endl;


}



}

void MainWindow::on_pushButton_Stop_clicked()
{

}

void MainWindow::pokazCO2(double &CO2)
{

    QString CO2Text =QString::number(CO2);

    ui->lcdNumber_CO2->display(CO2);
    ui->lcdNumber_CO2->display("");
   ui->label_12->setText(CO2Text);
   ui->plainTextEdit_CO2->appendPlainText(CO2Text);
}












