#include "mainwindow.h"

#include <QApplication>
#include <QPixmap>
#include <QPalette>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;

    w.setFixedSize(1080, 720);

           // 加载图片
    QPixmap background(":/Media/Media/Texture/bk.jpg");

           // 根据窗口大小缩放图片
    QPixmap scaledBackground = background.scaled(w.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

           // 设置背景
    QPalette palette = w.palette();
    palette.setBrush(QPalette::Window, scaledBackground);
    w.setPalette(palette);

    w.show();
    return a.exec();
}
