#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  ui->hellolabel->setText("");



}

QLabel *hellolabel;
int stage = 0;

MainWindow::~MainWindow()
{

    delete ui;

}



void MainWindow::resizeEvent(QResizeEvent *event){
      QWidget::resizeEvent(event);

      ui->img->resize(ui->centralwidget->size());

}

void MainWindow::on_pushButton_clicked()
{


    QPixmap pix("C:/Users/bugraguray/Pictures/RDR_2_Artwork_OutlawsForLife.png");
  //  ui->img->setPixmap(pix.scaled(1000,1000, Qt::KeepAspectRatioByExpanding));

    ui->img->clear();


    hellolabel = ui->hellolabel;



    switch (stage) {
    case 0:
         hellolabel->setText("Hello World!");
         stage = 1;
        break;

    case 1:
        hellolabel->setText("Hello Universe!");
        stage = 0;
        break;
    default:
        break;
    }
}


void MainWindow::on_imgPickBtn_clicked()
{
    QFileDialog fidi;
    QString filePath;
    fidi.exec();
    filePath = fidi.selectedFiles().first();
    qInfo() << filePath;
    //std::cout << "\ntest\n";

    QPixmap pix(filePath);
    ui->img->setPixmap(pix.scaled(1000,1000, Qt::KeepAspectRatioByExpanding));



}


void MainWindow::on_zoominbtn_clicked()
{
  ui->img->resize(ui->img->size() * 2);
   ui->scrollArea->resize(ui->centralwidget->size());
  ui->scrollAreaWidgetContents->resize(ui->img->size());
}

