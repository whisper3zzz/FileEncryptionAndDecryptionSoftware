#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

  private slots:
    void on_fileReader_Button_clicked();

    void on_swich_Button_clicked();

    void on_Cipher_comboBox_currentIndexChanged(int index);

    void on_keySet_textEdit_textChanged();

  private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
