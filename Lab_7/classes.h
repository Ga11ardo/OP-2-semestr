#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <QString>
#include <QTextBrowser>
#include <QMessageBox>
using namespace std;


class TFlight
{
    QString number, city, data, time;
public:
    TFlight();
    void setNumber(QString);
    void setCity(QString);
    void setData(QString);
    void setTime(QString);
    QString getData();
    QString getNumber();
    QString getFlight();
};

class TSchedule
{
    TFlight *fullschedule;
    int countFlights;
public:
    TSchedule();
    void addInSchedule(TFlight);
    void output(QTextBrowser*);
    void findFlights(QString, QTextBrowser*);
};

#endif // CLASSES_H
