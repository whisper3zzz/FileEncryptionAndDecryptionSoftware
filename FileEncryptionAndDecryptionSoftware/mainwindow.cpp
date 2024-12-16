#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"fileReader.h"
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_fileReader_Button_clicked()
{
std::optional<QString> content = FileReader::instance().readTextFile();
    if(content){
    QString fileContent =*content;

    }
}

