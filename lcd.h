#ifndef LCD_H
#define LCD_H

#include <QObject>
#include <QLCDNumber>

class lcd : public QLCDNumber
{
Q_OBJECT
public:
    lcd(QWidget *parent = 0, double value=0 );
private slots:
    void showData(double value, QLCDNumber &lcd22);
signals:
    void CO2(int newValue);


};

#endif // LCD_H
