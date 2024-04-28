#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<filters.h>
#include<fluids.h>
#include<QDate>
#include <QHBoxLayout>
#include<QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void update_widget();
    void addfilters();
    void addfluids();
    void filterloadStatus(int row, int column, QString status);
    void fluidloadStatus(int row, int column, QString status);
    void handlefilterValueChange();
    void handlefluidValueChange();
    QTimer *timer;
    Filters *filter;
    Fluids *fluid;
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSet<QString>fluids;
    QSet<QString>filters;
    int a=100;
    int b=110;
    int c=140;
};
#endif // MAINWINDOW_H
