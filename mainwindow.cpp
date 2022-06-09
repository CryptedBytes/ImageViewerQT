#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QFileDialog>
#include <iostream>
#include <QScroller>



QLabel *hellolabel;
int stage = 0;
QString imgpath;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

  ui->hellolabel->setText("");


      QScroller::grabGesture(ui->scrollArea->viewport(),QScroller::LeftMouseButtonGesture);

  QStringList arguments = qApp->arguments();
  if(arguments.size() > 1){


      QFile file("args.txt");

      if(file.open(QIODevice::WriteOnly | QIODevice::Text)) { //clear the file


         file.write("");
      }
      file.close();



        for(int i = 0; i < arguments.size(); i++){
            qDebug() << "\niterating argument #" << i << ":" << arguments[i] << "\n";

            if(arguments[i].contains("png")){
                imgpath = arguments[i].toUtf8();
                 QPixmap pix(imgpath);
                  ui->img->setPixmap(pix.scaled(1000,1000, Qt::KeepAspectRatioByExpanding));
            }


               if(file.open(QIODevice::WriteOnly | QIODevice::Append)) {


                  file.write(arguments[i].toUtf8() + "\n");
                  if(imgpath.size() > 2) file.write("\nFOUND IMG IN ARGS: "+ imgpath.toUtf8() + "\n");
               }
               file.close();
        }
  }

}



MainWindow::~MainWindow()
{

    delete ui;



}



void MainWindow::resizeEvent(QResizeEvent *event){
      QWidget::resizeEvent(event);

      ui->img->resize(ui->centralwidget->size());
      ui->scrollArea->resize(ui->centralwidget->size());
     ui->scrollAreaWidgetContents->resize(ui->img->size());

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

