#include "lcd.h"

lcd::lcd(QWidget *parent, double value) : QLCDNumber (parent)
{
    setSegmentStyle(Filled);

    //lcd *lcdL = new lcd(this);


    //connect(lcdL, &lcd::CO2,this, &lcd::showData );
    //showData(value);

//    setWindowTitle(tr("CO2"));
//    resize(600, 60);

}


void lcd::showData(double value, QLCDNumber &lcd22)
{
lcd *lcdL = new lcd;
    QString text = QString::number(value);
//connect(lcdL, &lcd::CO2,lcd22, SLOT(display));

}

void CO2(int newValue)
{
    emit CO2(newValue);
}
