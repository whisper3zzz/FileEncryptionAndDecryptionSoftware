#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"fileReader.h"
#include"cipherManager.h"
#include<QDebug>
#include <QMessageBox>
#include <QTextStream>
#include <QStandardPaths>
#include <QDir>
#include<stdio.h>
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_fileReader_Button_clicked()
{
    if(ui->Cipher_comboBox->currentIndex()!=3&&ui->keySet_textEdit->toPlainText().isEmpty()){
        QMessageBox::information(this, "提示", "请先输入密钥");
        return;

    }
    std::optional<QString> content = FileReader::instance().readTextFile();
    qDebug()<<content;
    if(content){
    QString fileContent =*content;
        if(ui->swich_Button->text()=="当前处于:加密模式")
    {
        if(ui->Cipher_comboBox->currentIndex()==0){

            auto key=ui->keySet_textEdit->toPlainText().toInt();
            CaesarCipher::instance().setShift(key);
          
            auto output=CipherManager::instance().encrypt("Caesar",fileContent.toStdString());
              //  qDebug()<< output+"output";


                  
            ui->show_textEdit->setText(QString::fromStdString(output));

                   // 获取当前时间并生成文件名
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("encrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("encrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }
            }
        if(ui->Cipher_comboBox->currentIndex()==1)
            {

            std::string key=(ui->keySet_textEdit->toPlainText()).toStdString();
           XorCipher::instance().setKey(key[0]);
          
            auto output=CipherManager::instance().encrypt("Xor",fileContent.toStdString());
       

                 
            ui->show_textEdit->setText(QString::fromStdString(output));

                  // 获取当前时间并生成文件名
           QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
           QString fileName = QString("encrypted_%1.txt").arg(currentTime);

                  // 获取沙盒路径
           QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
           QString targetDir = QDir(sandboxPath).filePath("encrypted");

                  // 创建目标目录（如果不存在）
           QDir dir;
           if (!dir.exists(targetDir)) {
               dir.mkpath(targetDir); // 创建目录及其父目录
           }

                  // 构建完整文件路径
           QString filePath = QDir(targetDir).filePath(fileName);

                  // 保存最终的 UTF-8 输出到文件
           QFile file(filePath);
           if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
               QTextStream out(&file);
              out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
               file.close();
           } else {
               // 处理文件打开失败的情况
               qDebug() << "Failed to open file for writing:" << file.errorString();
           }
            }
        if(ui->Cipher_comboBox->currentIndex()==2){
            auto key =ui->keySet_textEdit->toPlainText().toStdString();
            VigenereCipher::instance().setKey(key);
          
            auto output =CipherManager::instance().encrypt("Vigenere",fileContent.toStdString());


                  
           ui->show_textEdit->setText(QString::fromStdString(output));

                   // 获取当前时间并生成文件名
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("encrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("encrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }
        }
        if(ui->Cipher_comboBox->currentIndex()==3){
        }

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

                   // 获取当前时间并生成文件名
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("encrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("encrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }
         }
        if(ui->swich_Button->text()=="当前处于:解密模式")
    {
        if(ui->Cipher_comboBox->currentIndex()==0){
            auto key=ui->keySet_textEdit->toPlainText().toInt();
            CaesarCipher::instance().setShift(key);

            auto output=CipherManager::instance().decrypt("Caesar",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));
                      // 获取当前时间并生成文件名
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("decrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("decrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }

        }
        if(ui->Cipher_comboBox->currentIndex()==1)
        {
            std::string key=(ui->keySet_textEdit->toPlainText()).toStdString();
            XorCipher::instance().setKey(key[0]);
            auto output=CipherManager::instance().decrypt("Xor",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));
QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("decrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("decrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }

        }
        if(ui->Cipher_comboBox->currentIndex()==2){
            auto key =ui->keySet_textEdit->toPlainText().toStdString();
            VigenereCipher::instance().setKey(key);
            auto output =CipherManager::instance().decrypt("Vigenere",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("decrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("decrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }

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
            auto output =CipherManager::instance().decrypt("Substitution",fileContent.toStdString());
            ui->show_textEdit->setText(QString::fromStdString(output));
            QString currentTime = QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
            QString fileName = QString("decrypted_%1.txt").arg(currentTime);

                   // 获取沙盒路径
            QString sandboxPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
            QString targetDir = QDir(sandboxPath).filePath("decrypted");

                   // 创建目标目录（如果不存在）
            QDir dir;
            if (!dir.exists(targetDir)) {
                dir.mkpath(targetDir); // 创建目录及其父目录
            }

                   // 构建完整文件路径
            QString filePath = QDir(targetDir).filePath(fileName);

                   // 保存最终的 UTF-8 输出到文件
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << QString::fromStdString(output);// 保存最终的 UTF-8 输出s
                file.close();
            } else {
                // 处理文件打开失败的情况
                qDebug() << "Failed to open file for writing:" << file.errorString();
            }

        }

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


void MainWindow::on_Cipher_comboBox_currentIndexChanged(int index)
{
    if(index==0){
         ui->keySet_textEdit->setVisible(true);

          ui->keySet_textEdit->setPlaceholderText("请输入密钥，密钥应该为一个整数");
    }
    if(index==1){
         ui->keySet_textEdit->setVisible(true);

        ui->keySet_textEdit->setPlaceholderText("请输入密钥，密钥应该为一个英文字符，超过数量将取第一个字符");

    }
    if(index==2){
        ui->keySet_textEdit->setVisible(true);

        ui->keySet_textEdit->setPlaceholderText("请输入密钥，密钥为字符串");
    }
    if(index==3){
        ui->keySet_textEdit->setVisible(false);


    }

}





void MainWindow::on_keySet_textEdit_textChanged()
{

}

