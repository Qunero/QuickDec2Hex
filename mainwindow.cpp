#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_dec->setValidator(new QIntValidator());
    QRegExp reHex("(0[Xx])?[A-Fa-f0-9]*");
    ui->lineEdit_hex->setValidator(new QRegExpValidator(reHex));
    ui->checkBox_autoConvert->toggled(true);
    ui->pushButtonConvertDec2Hex->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_autoConvert_toggled(bool checked)
{
    ui->pushButtonConvertDec2Hex->setVisible(!checked);
    ui->pushButtonConvertHex2Dec->setVisible(!checked);
}

void MainWindow::on_pushButtonConvertDec2Hex_clicked()
{
    QString hex = QString::number(ui->lineEdit_dec->text().toLongLong(NULL, 10), 16);
    ui->lineEdit_hex->setText("0X" + hex.toUpper());
}

void MainWindow::on_pushButtonConvertHex2Dec_clicked()
{
    QString dec = QString::number(ui->lineEdit_hex->text().toLongLong(NULL, 16));
    ui->lineEdit_dec->setText(dec.toUpper());
}

void MainWindow::on_lineEdit_dec_textChanged(const QString &arg1)
{
    if (ui->checkBox_autoConvert->isChecked())
    {
        on_pushButtonConvertDec2Hex_clicked();
    }
}

void MainWindow::on_lineEdit_hex_textChanged(const QString &arg1)
{
    if (ui->checkBox_autoConvert->isChecked())
    {
        on_pushButtonConvertHex2Dec_clicked();
    }
}
