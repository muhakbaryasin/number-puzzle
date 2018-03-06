#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->pushButton->setEnabled(false);
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
    this->ui->pushButton->setEnabled(false);
    this->updateUILineEditRegex();
    this->lineedit_list.at(0)->setFocus();
}

void MainWindow::updateUILineEditRegex()
{
    QString regStr("[12345678 ]+");
    int list_len = this->lineedit_list.length();

    for (int iter=0; iter < list_len; iter++)
        regStr.replace(this->lineedit_list.at(iter)->text(), "");

    if (regStr == "[]+" || regStr == "[ ]+") {
        if (regStr == "[ ]+")
            this->ui->lineEdit_9->setText(" ");

        this->disabledAllLineEdit(true);
        this->ui->pushButton->setEnabled(true);
        return;
    }

    QRegExp anu(regStr);
    QRegExpValidator *valid_numeric = new QRegExpValidator(anu);

    for (int iter=0; iter < list_len; iter++)
        this->lineedit_list.at(iter)->setValidator(valid_numeric);

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

void MainWindow::mapToMat()
{
    int inc_ = 0;

    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            this->map[j][i] = this->lineedit_list.at(inc_)->text();
            inc_++;
        }
    }
}

void MainWindow::printMatToConsole()
{
    int inc_ = 0;

    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            std::cout << this->map[j][i].toStdString() << " ";
            this->lineedit_list.at(inc_)->setText(map[j][i]);
            inc_++;
        }
        std::cout << std::endl;
    }
    std::cout << "========================================================\n" << std::endl;
}

void MainWindow::on_pushButton_clicked()
{
    this->mapToMat();
    this->printMatToConsole();
    this->movePToXY("1", 0, 0);
    // 1 in the right place
}

MainWindow::coord MainWindow::findPCoord(QString p)
{
    coord p_coord;

    bool found_ = false;

    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            if (this->map[i][j] == p) {
                p_coord.x = i;
                p_coord.y = j;
                found_ = true;
                break;
            }
        }
        if (found_) break;
    }

    return p_coord;
}

int MainWindow::hammingDistance(MainWindow::coord a, MainWindow::coord b)
{
    return qFabs(a.x - b.x) + qFabs(a.y - b.y);
}

void MainWindow::movePToXY(QString p, int x, int y)
{
    std::cout << "movePToXY\n";
    coord p_coord = this->findPCoord(p);

    if (p_coord.x == x && p_coord.y == y)
        return;

    std::cout << p.toStdString() << " (x,y) -> " << p_coord.x << "," << p_coord.y << std::endl;
    std::cout << "mau ke (x,y) " << x << "," << y << std::endl;

    int x_direction = p_coord.x - x;

    if (p_coord.y > y) {
        std::cout << "masuk sini" << std::endl;
        this->moveBlankAboveP(p_coord, x_direction);
    }

    std::cout << "x_direction -> " << x_direction << std::endl;

    if (x_direction > 0) {
        std::cout << "masuk sana" << std::endl;
        this->moveBlankLeftP(p_coord);
    }

    this->switchBlankWithP(p);
    this->movePToXY(p, x, y);
}

void MainWindow::moveBlankAboveP(coord p_coord, int x_direction)
{
    std::cout << "moveBlankAboveP\n";
    coord blank_coord = this->findPCoord(" ");
    std::cout << "blank x,y -> " << blank_coord.x << "," << blank_coord.y << std::endl;

    coord temp_;
    temp_.x = p_coord.x;
    temp_.y = p_coord.y - 1;

    if (blank_coord.y > temp_.y) {
        if (blank_coord.x == p_coord.x) {
            if (x_direction > 0)
                this->switchBlankToLeft(blank_coord);
           else this->switchBlankToRight(blank_coord);
        } else {
            this->switchBlankToUpper(blank_coord);
        }
        this->moveBlankAboveP(p_coord, x_direction);
    }

    blank_coord = this->findPCoord(" ");
    int tmp_x_direction = blank_coord.x - temp_.x;

    // x_direction < 0 berarti ke kanan
    if (tmp_x_direction == 0) {
        return;
    }

    if (tmp_x_direction < 0) {
        this->switchBlankToRight(blank_coord);
    } else if (tmp_x_direction > 0) {
        this->switchBlankToLeft(blank_coord);
    }

    this->moveBlankAboveP(p_coord, x_direction);
}

void MainWindow::moveBlankLeftP(MainWindow::coord p_coord)
{
    // std::cout << "moveBlankLeftP\n";
    coord blank_coord = this->findPCoord(" ");
    std::cout << "blank x,y -> " << blank_coord.x << "," << blank_coord.y << std::endl;

    coord temp_;
    temp_.x = p_coord.x - 1;
    temp_.y = p_coord.y;

    if (blank_coord.y > temp_.y) {
        if (blank_coord.x == p_coord.x) {
            this->switchBlankToLeft(blank_coord);
        } else {
            this->switchBlankToUpper(blank_coord);
        }
        this->moveBlankLeftP(p_coord);
    }
}

void MainWindow::switchBlankToUpper(MainWindow::coord blank_coord)
{
    // std::cout << "swtichBlankToUpper\n";
    std::cout << "si blank gerak ke atas" << std::endl;
    coord target;

    target.x = blank_coord.x;
    target.y = blank_coord.y - 1;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank_coord.x][blank_coord.y] = temp_;

    this->printMatToConsole();
}

void MainWindow::switchBlankToLeft(MainWindow::coord blank_coord)
{
    // std::cout << "switchBlankToLeft\n";
    std::cout << "si blank gerak ke kiri" << std::endl;
    coord target;
    target.x = blank_coord.x - 1;
    target.y = blank_coord.y;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank_coord.x][blank_coord.y] = temp_;

    this->printMatToConsole();
}

void MainWindow::switchBlankToRight(MainWindow::coord blank_coord)
{
    // std::cout << "switchBlankToRight\n";
    std::cout << "si blank gerak ke kanan" << std::endl;
    coord target;
    target.x = blank_coord.x + 1;
    target.y = blank_coord.y;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank_coord.x][blank_coord.y] = temp_;

    this->printMatToConsole();
}

void MainWindow::switchBlankToUnder(MainWindow::coord blank_coord)
{
    // std::cout << "swtichBlankToUpper\n";
    std::cout << "si blank gerak ke bawah" << std::endl;
    coord target;

    target.x = blank_coord.x;
    target.y = blank_coord.y + 1;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank_coord.x][blank_coord.y] = temp_;

    this->printMatToConsole();
}

void MainWindow::switchBlankWithP(QString p)
{
    // std::cout << "switchBlankWithP\n";
    std::cout << "si blank tukeran sama " << p.toStdString() << std::endl;
    coord p_coord = this->findPCoord(p);
    coord blank_coord = this->findPCoord(" ");

    map[p_coord.x][p_coord.y] = " ";
    map[blank_coord.x][blank_coord.y] = p;
    this->printMatToConsole();
}
