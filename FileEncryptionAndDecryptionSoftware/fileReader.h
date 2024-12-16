#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QObject>
#include <optional>
#include "Singleton.h"

class FileReader :  public QObject ,public Singleton<FileReader>{
    Q_OBJECT

  public:
    std::optional<QString> readTextFile();


    explicit FileReader(QObject *parent = nullptr);
};

#endif // FILEREADER_H
