#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fluid=new Fluids;
    filter=new Filters;
    fluids=fluid->getfluidlist();
    filters=filter->getfilterlist();
    ui->stackedWidget->setCurrentIndex(0);
    addfilters();
    addfluids();
    timer = new QTimer();

    timer->setInterval(1000);
    timer->setSingleShot(false);

    connect(timer, &QTimer::timeout,this, &MainWindow::handlefilterValueChange);
    connect(timer, &QTimer::timeout,this, &MainWindow::handlefluidValueChange);

    timer->start();

}


void MainWindow::addfilters()
{
    ui->tableWidget->clearContents();
    // ui->tableWidget->setRowCount(0);
    int i=0;
    QDate currentdate = QDate::currentDate();
    QString datestring=currentdate.toString("dd-MM-yyyy");
    for(auto it:filters){
        // qDebug()<<it;
        QTableWidgetItem* filterItem = new QTableWidgetItem(it);
        filterItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,0,filterItem);

        QTableWidgetItem* dateItem = new QTableWidgetItem(datestring);
        dateItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(i,2,dateItem);
        filterloadStatus(i,1,"good");
        i++;
    }
}

void MainWindow::addfluids()
{
    ui->tableWidget_2->clearContents();
    // ui->tableWidget_2->setRowCount(0);
    int i=0;
    QDate currentdate = QDate::currentDate();
    QString datestring=currentdate.toString("dd-MM-yyyy");
    for(auto it:fluids){
        // qDebug()<<it;
        QTableWidgetItem* fluidItem = new QTableWidgetItem(it);
        fluidItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_2->setItem(i,0,fluidItem);

        QTableWidgetItem* dateItem = new QTableWidgetItem(datestring);
        dateItem->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_2->setItem(i,2,dateItem);
        fluidloadStatus(i,1,"good");
        i++;
    }
}

void MainWindow::filterloadStatus(int row, int column, QString status){
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);
    ui->tableWidget->setCellWidget(row, column, widget);

    int width = 25;
    int height = 25;

    label1->setFixedSize(width, height);

    if(status == "good"){
        QPixmap pixmap(":/new/images/check.png");
        label2->setText("Looks Good");
        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "warning"){
        QPixmap pixmap(":/new/images/warning.png");
        label2->setText("Warning !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "critical"){
        QPixmap pixmap(":/new/images/critical.jpg");
        label2->setText("Critical Problem !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }
}

void MainWindow::fluidloadStatus(int row, int column, QString status)
{
    QWidget *widget = new QWidget();
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    QLabel *label1 = new QLabel();
    QLabel *label2 = new QLabel();
    hBoxLayout->addWidget(label1);
    hBoxLayout->addWidget(label2);
    widget->setLayout(hBoxLayout);
    ui->tableWidget_2->setCellWidget(row, column, widget);

    int width = 25;
    int height = 25;

    label1->setFixedSize(width, height);

    if(status == "good"){
        QPixmap pixmap(":/new/images/check.png");
        label2->setText("Looks Good");
        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "warning"){
        QPixmap pixmap(":/new/images/warning.png");
        label2->setText("Warning !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }

    if(status == "critical"){
        QPixmap pixmap(":/new/images/critical.jpg");
        label2->setText("Critical Problem !!!");

        if (!pixmap.isNull()) {
            label1->setPixmap(pixmap);
            label1->setScaledContents(true);
        } else {
            label1->setText("Image not found");
        }
    }
}

void MainWindow::handlefilterValueChange()
{
    if((a<=100) && (a>75))    filterloadStatus(0,1,"good");
    if((b<=110) && (b>75))    filterloadStatus(1,1,"good");
    if((c<=140) && (c>75))    filterloadStatus(2,1,"good");
    if((a<75) && (a>50))    filterloadStatus(0,1,"warning");
    if((b<75) && (b>50))    filterloadStatus(1,1,"warning");
    if((c<75) && (c>50))    filterloadStatus(2,1,"warning");
    if((a<50) && (a>25))    filterloadStatus(0,1,"critical");
    if((b<50) && (b>25))    filterloadStatus(1,1,"critical");
    if((c<50) && (c>25))    filterloadStatus(2,1,"critical");

    a-=7;
    b-=10;
    c-=13;

}

void MainWindow::handlefluidValueChange()
{
    if((a<=100) && (a>75))    fluidloadStatus(0,1,"good");
    if((b<=110) && (b>75))    fluidloadStatus(1,1,"good");
    if((c<=140) && (c>75))    fluidloadStatus(2,1,"good");
    if((a<75) && (a>50))    fluidloadStatus(0,1,"warning");
    if((b<75) && (b>50))    fluidloadStatus(1,1,"warning");
    if((c<75) && (c>50))    fluidloadStatus(2,1,"warning");
    if((a<50) && (a>25))    fluidloadStatus(0,1,"critical");
    if((b<50) && (b>25))    fluidloadStatus(1,1,"critical");
    if((c<50) && (c>25))    fluidloadStatus(2,1,"critical");

    a-=7;
    b-=10;
    c-=13;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
}

