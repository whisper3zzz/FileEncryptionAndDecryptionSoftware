#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"fileReader.h"
#include"cipherManager.h"
#include<QDebug>
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_fileReader_Button_clicked()
{
std::optional<QString> content = FileReader::instance().readTextFile();
    qDebug()<<content;
    if(content){
    QString fileContent =*content;
        if(ui->swich_Button->text()=="当前处于:加密模式")
    {
        if(ui->Cipher_comboBox->currentIndex()==0){
          //  ui->keySet_textEdit->setPlaceholderText("ssssss");
           // qDebug()<<ui->keySet_textEdit;
            auto key=ui->keySet_textEdit->toPlainText().toInt();
            CaesarCipher::instance().setShift(key);
            auto output=CipherManager::instance().encrypt("Caesar",fileContent.toStdString());
              //  qDebug()<< output+"output";
            ui->show_textEdit->setText(QString::fromStdString(output));
            }
        if(ui->Cipher_comboBox->currentIndex()==1)
            {
          //   ui->keySet_textEdit->setPlaceholderText("请输入密钥，密钥应该为一个英文字符，超过数量将取第一个字符");
            std::string key=(ui->keySet_textEdit->toPlainText()).toStdString();
           XorCipher::instance().setKey(key[0]);
            auto output=CipherManager::instance().encrypt("Xor",fileContent.toStdString());
           ui->show_textEdit->setText(QString::fromStdString(output));

        }if(ui->Cipher_comboBox->currentIndex()==2){
            auto key =ui->keySet_textEdit->toPlainText().toStdString();
            VigenereCipher::instance().setKey(key);
            auto output =CipherManager::instance().encrypt("Vigenere",fileContent.toStdString());
              ui->show_textEdit->setText(QString::fromStdString(output));
        }
        if(ui->Cipher_comboBox->currentIndex()==3){
            std::unordered_map<char, char> substitutionMap = {
                {'A', 'D'}, {'B', 'E'}, {'C', 'F'}, {'D', 'G'},
                {'E', 'H'}, {'F', 'I'}, {'G', 'J'}, {'H', 'K'},
                {'I', 'L'}, {'J', 'M'}, {'K', 'N'}, {'L', 'O'},
                {'M', 'P'}, {'N', 'Q'}, {'O', 'R'}, {'P', 'S'},
                {'Q', 'T'}, {'R', 'U'}, {'S', 'V'}, {'T', 'W'},
                {'U', 'X'}, {'V', 'Y'}, {'W', 'Z'}, {'X', 'A'},
                {'Y', 'B'}, {'Z', 'C'}, // 替换映射
            };
            SubstitutionCipher::instance().setSubstitution(substitutionMap);
            auto output =CipherManager::instance().encrypt("Substitution",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));
         }



    }
        if(ui->swich_Button->text()=="当前处于:解密模式"){
        if(ui->Cipher_comboBox->currentIndex()==0){
            auto key=ui->keySet_textEdit->toPlainText().toInt();
            CaesarCipher::instance().setShift(key);
            auto output=CipherManager::instance().decrypt("Caesar",fileContent.toStdString());

            //  qDebug()<< output+"output";
            ui->show_textEdit->setText(QString::fromStdString(output));
        }
        if(ui->Cipher_comboBox->currentIndex()==1)
        {
            std::string key=(ui->keySet_textEdit->toPlainText()).toStdString();
            XorCipher::instance().setKey(key[0]);
            auto output=CipherManager::instance().decrypt("Xor",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));

        }
        //if(ui->Cipher_comboBox->currentIndex()==3)


      }
    else return;

    }
}



void MainWindow::on_swich_Button_clicked()
{

    if(ui->swich_Button->text()=="当前处于:加密模式")
    {
        ui->swich_Button->setText("当前处于:解密模式");

    }
    else
    {
        ui->swich_Button->setText("当前处于:加密模式");
    }
}

