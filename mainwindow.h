#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_checkBox_autoConvert_toggled(bool checked);

    void on_pushButtonConvertDec2Hex_clicked();

    void on_pushButtonConvertHex2Dec_clicked();

    void on_lineEdit_dec_textChanged(const QString &arg1);

    void on_lineEdit_hex_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
