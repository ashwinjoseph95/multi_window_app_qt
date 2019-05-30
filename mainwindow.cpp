#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->verticalSlider, SIGNAL(valueChanged(int)),
                this, SLOT(set_val(int)) );

    connect(this, SIGNAL(reset(int)),
            ui->verticalSlider, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_val(int val)
{
    ui->label->setText(QString::number(val));
}


void MainWindow::on_pushButton_clicked()
{
//    ui->label->setText("0");
    emit reset(0);

}
