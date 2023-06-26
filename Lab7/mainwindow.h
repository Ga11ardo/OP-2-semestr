#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QLineEdit>
#include "classes.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void checkInput(QString, QLineEdit*, QString);

    void checkInputString(QString, QLineEdit*);

    void checkInputDate (QString, QString, QString, QLineEdit*);

    void clearAllLines();

    void on_number_editingFinished();

    void on_day_editingFinished();

    void on_month_editingFinished();

    void on_year_editingFinished();

    void on_hours_editingFinished();

    void on_minutes_editingFinished();

    void on_recordButton_clicked();

    void on_dayToFind_editingFinished();

    void on_monthToFind_editingFinished();

    void on_yearToFind_editingFinished();

    void on_findButton_clicked();

    void on_city_editingFinished();

private:
    Ui::MainWindow *ui;

    TSchedule schedule;
};
#endif // MAINWINDOW_H
