#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->lineedit_list.append(ui->lineEdit);
    this->lineedit_list.append(ui->lineEdit_2);
    this->lineedit_list.append(ui->lineEdit_3);
    this->lineedit_list.append(ui->lineEdit_4);
    this->lineedit_list.append(ui->lineEdit_5);
    this->lineedit_list.append(ui->lineEdit_6);
    this->lineedit_list.append(ui->lineEdit_7);
    this->lineedit_list.append(ui->lineEdit_8);
    this->lineedit_list.append(ui->lineEdit_9);
    this->updateUILineEditRegex();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::disabledAllLineEdit(bool condition) {
    int list_len = this->lineedit_list.length();

    for (int iter=0; iter < list_len; iter++)
        this->lineedit_list.at(iter)->setDisabled(condition);
}

void MainWindow::autoFocus()
{
    int list_len = this->lineedit_list.length();
    for (int iter=0; iter < list_len; iter++) {
        if (this->lineedit_list.at(iter)->text() == "") {
            this->lineedit_list.at(iter)->setFocus();
            return;
        }

    }

}

void MainWindow::updateUILineEditRegex()
{
    QString regStr("[12345678]+");
    int list_len = this->lineedit_list.length();

    for (int iter=0; iter < list_len; iter++)
        regStr.replace(this->lineedit_list.at(iter)->text(), "");

    if (regStr == "[]+") {
        this->disabledAllLineEdit(true);
        return;
    }

    QRegExp anu(regStr);
    QRegExpValidator *valid_numeric = new QRegExpValidator(anu);

    for (int iter=0; iter < list_len; iter++)
        this->lineedit_list.at(iter)->setValidator(valid_numeric);

}

void MainWindow::on_lineEdit_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_2_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_2->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_3_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_3->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_4_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_4->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_5_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_5->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_6_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_6->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_7_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_7->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_8_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_8->text() != "")
        this->autoFocus();
}

void MainWindow::on_lineEdit_9_textChanged()
{
    this->updateUILineEditRegex();
    if (this->ui->lineEdit_9->text() != "")
        this->autoFocus();
}

void MainWindow::on_pushButton_2_clicked()
{
    int list_len = this->lineedit_list.length();

    for (int iter=0; iter < list_len; iter++)
        this->lineedit_list.at(iter)->setText("");

    this->disabledAllLineEdit(false);
    this->updateUILineEditRegex();
    this->lineedit_list.at(0)->setFocus();
}

void MainWindow::on_pushButton_clicked()
{

}
