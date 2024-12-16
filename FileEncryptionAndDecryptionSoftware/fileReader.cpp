#include "FileReader.h"

FileReader::FileReader(QObject *parent) : QObject(parent) {}

std::optional<QString> FileReader::readTextFile() {

    QString fileName = QFileDialog::getOpenFileName(nullptr, "选择文本文件", "", "文本文件 (*.txt)");
    if (fileName.isEmpty()) {
        return std::nullopt; // 取消选择
    }

           // 读取文件内容
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return std::nullopt; // 打开文件失败
    }

    QTextStream in(&file);
    QString fileContent = in.readAll();
    file.close();

    return fileContent; // 返回文件内容
}
