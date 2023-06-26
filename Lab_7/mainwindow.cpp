#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//перевірка введення полів в залежності від даних, що вони мають приймати
void MainWindow::checkInput(QString input, QLineEdit *line, QString id){
    try{
        for(int i = 0; i<input.size(); i++){
            if(input[i]<'0'||input[i]>'9'){
                throw "Incorrect input: number of flight should be number";
            }
        }
        if(id == "day" && (input.toInt()<1 || input.toInt()>31)){
            throw "Incorrect input: day should be 1-31";
        }else if(id == "month" && (input.toInt()<1 || input.toInt()>12)){
            throw "Incorrect input: month should be 1-12";
        }else if(id == "year" && (input.toInt()<2023 || input.toInt()>2030)){
            throw "Incorrect input: year should be 2023-2030";
        }else if(id == "hours" && (input.toInt()<0 || input.toInt()>23)){
            throw "Incorrect input: hours should be 0-23";
        }else if(id == "minutes" && (input.toInt()<0 || input.toInt()>59)){
            throw "Incorrect input: minutes should be 0-59";
        }
    }
    catch(char const* errorName){
        QMessageBox::warning(this, "Error", errorName);
        line->clear();
    }
}

//перевірка введення поля на зайві символи окрім букв і пробілу
void MainWindow::checkInputString (QString input, QLineEdit *line){
    try{
        for(int i = 0; i<input.size(); i++){
            if(input[i]==' '){}
            else if(input[i]>='A'&& input[i]<='z'){//' ' 32, A-Z 65-90, a-z 97-122
                if(input[i]>'Z'&& input[i]<'a')
                    throw "Incorrect input: name of a city should be string";
            }
            else throw "Incorrect input: name of a city should be string";
        }
    }
    catch(char const* errorName){
        QMessageBox::warning(this, "Error", errorName);
        line->clear();
    }
}

//перевірка введення дати на неіснуючі дні
void MainWindow::checkInputDate (QString input_year, QString input_month, QString input_day, QLineEdit *line){
    try{
        if(input_year == "" || input_month== "" || input_day== ""){}
        else{
            int year = input_year.toInt();
            int month = input_month.toInt();
            int day = input_day.toInt();

            if(month == 2){
                if (year % 4 == 0 && (year % 400 == 0 || year % 100 != 0)) {
                    if (day < 1 || day > 29) throw "Incorrect input: in the input month day should be 1-29";
                }
                else if (day < 1 || day > 28) throw "Incorrect input: in the input month day should be 1-28";
            }
            else if(month == 4 || month == 6 ||month == 9 ||month == 11){
                if (day < 1 || day > 30) throw "Incorrect input: in the input month day should be 1-30";
            }
            else if(month == 1 || month == 3 ||month == 5 ||month == 7 ||month == 8 ||month == 10 ||month == 12) {
                if (day < 1 || day > 31) throw "Incorrect input: in the input month day should be 1-31";
            }
        }
    }
    catch(char const* errorName){
        QMessageBox::warning(this, "Error", errorName);
        line->clear();
    }
}

//перевірка введення номера
void MainWindow::on_number_editingFinished()
{
    QString input = ui->number->text();
    checkInput(input, ui->number, "null");
}

//перевірка введення дня
void MainWindow::on_day_editingFinished()
{
    QString input_day = ui->day->text();
    checkInput(input_day, ui->day, "day");
    QString input_month = ui->month->text();
    QString input_year = ui->year->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//перевірка введення місяця
void MainWindow::on_month_editingFinished()
{
    QString input_month = ui->month->text();
    checkInput(input_month, ui->month, "month");
    QString input_day = ui->day->text();
    QString input_year = ui->year->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//перевірка введення року
void MainWindow::on_year_editingFinished()
{
    QString input_year = ui->year->text();
    checkInput(input_year, ui->year, "year");
    QString input_day = ui->day->text();
    QString input_month = ui->month->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//перевірка введення годин
void MainWindow::on_hours_editingFinished()
{
    QString input = ui->hours->text();
    checkInput(input, ui->hours, "hours");
}

//перевірка введення хвилин
void MainWindow::on_minutes_editingFinished()
{
    QString input = ui->minutes->text();
    checkInput(input, ui->minutes, "minutes");
}

//перевірка введення міста призначення
void MainWindow::on_city_editingFinished()
{
    QString input = ui->city->text();
    checkInputString(input, ui->city);
}

//очищення полів введення даних про рейс
void MainWindow::clearAllLines(){
    ui->number->clear();
    ui->day->clear();
    ui->month->clear();
    ui->year->clear();
    ui->city->clear();
    ui->hours->clear();
    ui->minutes->clear();
}

//запис рейса з введеними даними з попередньою перевіркою полів на пустоту
void MainWindow::on_recordButton_clicked()
{
    try {
        QStringList emptyFields;

        if (ui->number->text().isEmpty())
            emptyFields.append("number");
        if (ui->day->text().isEmpty())
            emptyFields.append("day");
        if (ui->month->text().isEmpty())
            emptyFields.append("month");
        if (ui->year->text().isEmpty())
            emptyFields.append("year");
        if (ui->city->text().isEmpty())
            emptyFields.append("city");
        if (ui->hours->text().isEmpty())
            emptyFields.append("hours");
        if (ui->minutes->text().isEmpty())
            emptyFields.append("minutes");

        if (!emptyFields.isEmpty())
            throw "Error: the following fields are full: " + emptyFields.join(", ");

        TFlight newFlight;
        newFlight.setNumber(ui->number->text());
        QString dataToSet;
        if(ui->day->text().size() == 1)
            dataToSet.append('0');
        dataToSet.append(ui->day->text());
        dataToSet.append('.');
        if(ui->month->text().size() == 1)
            dataToSet.append('0');
        dataToSet.append(ui->month->text());
        dataToSet.append('.');
        dataToSet.append(ui->year->text());
        newFlight.setData(dataToSet);
        newFlight.setCity(ui->city->text());
        QString timeToSet;
        if(ui->hours->text().size() == 1)
            timeToSet.append('0');
        timeToSet.append(ui->hours->text());
        timeToSet.append(':');
        if(ui->minutes->text().size() == 1)
            timeToSet.append('0');
        timeToSet.append(ui->minutes->text());
        newFlight.setTime(timeToSet);

        schedule.addInSchedule(newFlight);

        clearAllLines();

        ui->fullSchedule->clear();

        schedule.output(ui->fullSchedule);
    }
    catch(QString const& errorName){
        QMessageBox::warning(this, "Error", errorName);
    }

}

//перевірка введення дня для пошуку рейса
void MainWindow::on_dayToFind_editingFinished()
{
    QString input_day = ui->dayToFind->text();
    checkInput(input_day, ui->dayToFind, "day");
    QString input_month = ui->monthToFind->text();
    QString input_year = ui->yearToFind->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//перевірка введення місяця для пошуку рейса
void MainWindow::on_monthToFind_editingFinished()
{
    QString input_month = ui->monthToFind->text();
    checkInput(input_month, ui->monthToFind, "month");
    QString input_day = ui->dayToFind->text();
    QString input_year = ui->yearToFind->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//перевірка введення року для пошуку рейса
void MainWindow::on_yearToFind_editingFinished()
{
    QString input_year = ui->yearToFind->text();
    checkInput(input_year, ui->yearToFind, "year");
    QString input_day = ui->dayToFind->text();
    QString input_month = ui->monthToFind->text();
    checkInputDate(input_year, input_month, input_day, ui->day);
}

//знаходження рейса на введену дату з попередньою перевіркою коректності дати
void MainWindow::on_findButton_clicked()
{
    try{
        QStringList emptyFields;

        if (ui->dayToFind->text().isEmpty())
            emptyFields.append("day");
        if (ui->monthToFind->text().isEmpty())
            emptyFields.append("month");
        if (ui->yearToFind->text().isEmpty())
            emptyFields.append("year");

        if (!emptyFields.isEmpty())
            throw "Error: the following fields are full: " + emptyFields.join(", ");

        QString dataToFind;
        if(ui->dayToFind->text().size() == 1)
            dataToFind.append('0');
        dataToFind.append(ui->dayToFind->text());
        dataToFind.append('.');
        if(ui->monthToFind->text().size() == 1)
            dataToFind.append('0');
        dataToFind.append(ui->monthToFind->text());
        dataToFind.append('.');
        dataToFind.append(ui->yearToFind->text());
        ui->findedFlights->clear();
        schedule.findFlights(dataToFind, ui->findedFlights);

        ui->dayToFind->clear();
        ui->monthToFind->clear();
        ui->yearToFind->clear();
    }
    catch(QString const& errorName){
        QMessageBox::warning(this, "Error", errorName);
    }
}

