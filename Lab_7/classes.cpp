#include "classes.h"

//конструктор за замовчуванням
TFlight::TFlight(){
    number = "";
    city = "";
    data = "";
    time = "";
}

//задати номер рейсу
void TFlight::setNumber(QString numToSet){
    number = numToSet;
}

//задати місто рейсу
void TFlight::setCity(QString cityToSet){
    city = cityToSet;
}

//задати дату рейсу
void TFlight::setData(QString dataToSet){
    data = dataToSet;
}

//задати час рейсу
void TFlight::setTime(QString timeToSet){
    time = timeToSet;
}

//отримати дату рейсу
QString TFlight::getData(){
    return data;
}

//отримати номер рейсу
QString TFlight::getNumber(){
    return number;
}

//отримати повну інформацію про рейс
QString TFlight::getFlight(){
    QString fullInfo = number;
    fullInfo.append(' ');
    fullInfo.append(city);
    fullInfo.append(' ');
    fullInfo.append(data);
    fullInfo.append(' ');
    fullInfo.append(time);
    return fullInfo;
}

//конструктор за замовчуванням
TSchedule::TSchedule(){
    countFlights = 0;
}

//додати до розкладу
void TSchedule::addInSchedule(TFlight newFlight){
    if(countFlights == 0){
        fullschedule = new TFlight[1];
    }else{
        TFlight *temp = new TFlight[countFlights+1];
        for(int i = 0; i < countFlights; i++){
            temp[i] = fullschedule[i];
        }
        delete[] fullschedule;
        fullschedule = temp;
    }
    fullschedule[countFlights] = newFlight;
    countFlights++;
}

//вивести розклад
void TSchedule::output(QTextBrowser* brows){
    for(int i = 0; i < countFlights; i++){
        brows->append(fullschedule[i].getFlight());
    }
}

//знайти рейси на задану дату
void TSchedule::findFlights(QString dataToFind, QTextBrowser* brows){
    int find = 0;
    brows->append(dataToFind);
    try{
        for(int i = 0; i < countFlights; i++){
            if(fullschedule[i].getData() == dataToFind){
                brows->append(fullschedule[i].getNumber());
                find = 1;
            }
        }
        if(!find)
            throw "No flights for this day";
    }
    catch(char const* errorName){
        brows->append(errorName);
    }
}
