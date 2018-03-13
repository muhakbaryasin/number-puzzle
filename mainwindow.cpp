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
    history.clear();
    memset(locked, false, sizeof(locked));
    //memset(locked, false, sizeof(locked));

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
    unsigned int msleep = 1;
    QString order = "";

    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            std::cout << this->map[j][i].toStdString() << " ";
            order += this->map[j][i];
            this->lineedit_list.at(inc_)->setText(map[j][i]);
            this->lineedit_list.at(inc_)->repaint();
            inc_++;
        }
        std::cout << std::endl;
    }
    history.append(order);
    std::cout << "========================================================\n" << std::endl;
    sleep(msleep);
    qApp->processEvents();

}

void MainWindow::on_pushButton_clicked()
{
    this->mapToMat();
    this->printMatToConsole();
    blank = this->findPCoord(" ");
    this->movePToXY("1", 0, 0);
    this->lockCoord(0,0);
    this->movePToXY("2", 1, 2);
    this->movePToXY("3", 1, 0);
    this->movePToXY("2", 1, 1);
    this->lockCoord(1,0);
    this->lockCoord(1,1);
    this->moveBlankToXY(2, 0);
    this->movePToXY("3", 2, 0);
    this->movePToXY("2", 1, 0);
    this->lockCoord(2,0);
    this->unlockCoord(1,1);
    // step 1 selesai

    //this->movePToXY("5", 2, 2);
    this->movePToXY("7", 0, 1);
    this->movePToXY("4", 1, 1);
    this->movePToXY("7", 0, 1);
    this->lockCoord(0, 1);
    this->movePToXY("4", 1, 1);
    //this->lockCoord(1, 1);
    this->moveBlankToXY(0, 2);
    this->unlockCoord(0, 1);
    this->movePToXY("7", 0, 2);
    this->movePToXY("4", 0, 1);
    this->lockCoord(0, 1);
    this->movePToXY("8", 1, 1);
    this->movePToXY("5", 2, 1);
    this->movePToXY("8", 1, 1);
    //this->moveBlankToXY(1, 2);
    this->movePToXY("8", 1, 2);
    this->movePToXY("5", 1, 1);
    this->movePToXY("6", 2, 1);
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
    int distance;
    if (this->coordIsPossible(a) && this->coordIsPossible(b)) {
        distance = qFabs(a.x - b.x) + qFabs(a.y - b.y);
        if (a.x == b.x == P.x || a.y == b.y == P.y)
            distance += 1;
    } else
        distance = 1000000;
    std::cout << "(" << a.x << "," << a.y << ") -> ";
    std::cout << "(" << b.x << "," << b.y << ") : "<< distance << "\n" ;
    return distance;
}

bool MainWindow::coordIsPossible(MainWindow::coord c)
{
    if (c.x < 0 || c.x > 2 || c.y < 0 || c.y > 2)
        return false;

    if (c.x == P.x && c.y == P.y)
        return false;

    return true;
}

void MainWindow::movePToXY(QString p, int x, int y)
{
    std::cout << "movePToXY" << std::endl;
    P = this->findPCoord(p);

    if (P.x == x && P.y == y) {
        std::cout << "fin." << std::endl;
        return;
    }

    coord above_p = P, left_p = P, under_p = P, right_p = P;
    above_p.y = above_p.y - 1;
    left_p.x = left_p.x - 1;
    under_p.y = under_p.y + 1;
    right_p.x = right_p.x + 1;

    std::cout << p.toStdString() << " (x,y) -> " << P.x << "," << P.y << std::endl;
    std::cout << "mau ke (x,y) " << x << "," << y << std::endl;

    if (P.x == x && P.y > y) {
        // P mau ke atas
        this->moveBlankAboveP();
        this->swapBlankWithP();
    } else if (P.x == x && P.y < y) {
        // P mau ke bawah
        this->moveBlankUnderP();
        this->swapBlankWithP();
    } else if (P.x > x && P.y == y) {
        // P mau ke kiri
        this->moveBlankLeftP();
        this->swapBlankWithP();
    } else if (P.x < x && P.y == y) {
        // P mau ke kanan
        this->moveBlankRightP();
        this->swapBlankWithP();
    } else if (P.x > x && P.y > y) {
        std::cout << "masuk sini gak\n";
        // P mau pindah ke arah kiri atas
        // pilih mau ke arah kiri atau atas dulu
        if (this->hammingDistance(blank, above_p) <= this->hammingDistance(blank, left_p)) {
            // ini ke atas
            this->moveBlankAboveP();
            this->swapBlankWithP();
        } else {
            // ini ke kiri
            this->moveBlankLeftP();
            this->swapBlankWithP();
        }
    } else if (P.x > x && P.y < y) {
        std::cout << "masuk sini gak\n";
        // P mau pindah ke arah kiri atas
        // pilih mau ke arah kiri atau atas dulu
        if (this->hammingDistance(blank, under_p) <= this->hammingDistance(blank, left_p)) {
            // ini ke atas
            this->moveBlankUnderP();
            this->swapBlankWithP();
        } else {
            // ini ke kiri
            this->moveBlankLeftP();
            this->swapBlankWithP();
        }
    } else if (P.x < x && P.y < y) {
        // P mau pindah ke arah kanan bawah
        // pilih mau ke arah kanan atau bawah dulu
        if (this->hammingDistance(blank, under_p) <= this->hammingDistance(blank, right_p)) {
            // ini ke bawah
            this->moveBlankUnderP();
            this->swapBlankWithP();
        } else {
            // ini ke kanan
            this->moveBlankRightP();
            this->swapBlankWithP();
        }
    } else if (P.x < x && P.y > y) {
        // P mau pindah ke arah kanan atas
        // pilih mau ke arah kanan atau atas dulu
        if (this->hammingDistance(blank, above_p) <= this->hammingDistance(blank, right_p)) {
            // ini ke atas
            this->moveBlankAboveP();
            this->swapBlankWithP();
        } else {
            // ini ke kanan
            this->moveBlankRightP();
            this->swapBlankWithP();
        }
    }

    // recursive
    this->movePToXY(p, x, y);
}

void MainWindow::moveBlankToXY(int x, int y)
{
    std::cout << "moveBlankToXY\n";
    std::cout << "blank x,y -> " << blank.x << "," << blank.y << std::endl;

    if (blank.x == x && blank.y == y)
        return;

    QList <struct possible_move> pbm = this->blankPossibleMoveTo(x, y);

    for (int i = 0; i < pbm.length(); i++ ) {
        if (pbm.at(i).num == 1)
            this->swapBlankToUpper();
        else if (pbm.at(i).num == 2)
            this->swapBlankToUnder();
        else if (pbm.at(i).num == 3)
            this->swapBlankToLeft();
        else if (pbm.at(i).num == 4)
            this->swapBlankToRight();
        break;
    }
    this->moveBlankToXY(x, y);
}

QList<MainWindow::possible_move> MainWindow::blankPossibleMoveTo(int x, int y)
{
    QList<struct possible_move> priority_direction;

    coord T;
    T.x = x;
    T.y = y;

    coord tmp = blank;
    tmp.y = tmp.y - 1;

    if (this->coordIsPossible(tmp) && swapBlankIsValid(tmp.x, tmp.y) && !locked[tmp.x][tmp.y]) {
        possible_move up;
        up.num = 1;
        up.distance = this->hammingDistance(tmp, T);
        //std::cout << "up : " << up.distance << std::endl;
        priority_direction.append(up);
    }

    tmp = blank;
    tmp.y = tmp.y + 1;

    if (this->coordIsPossible(tmp) && swapBlankIsValid(tmp.x, tmp.y) && !locked[tmp.x][tmp.y]) {
        possible_move down;
        down.num = 2;
        down.distance = this->hammingDistance(tmp, T);
        priority_direction.append(down);
    }

    tmp = blank;
    tmp.x = tmp.x - 1;

    if (this->coordIsPossible(tmp) && swapBlankIsValid(tmp.x, tmp.y) && !locked[tmp.x][tmp.y]) {
        possible_move left;
        left.num = 3;
        left.distance = this->hammingDistance(tmp, T);
        priority_direction.append(left);
    }

    tmp = blank;
    tmp.x = tmp.x + 1;

    if (this->coordIsPossible(tmp) && swapBlankIsValid(tmp.x, tmp.y) && !locked[tmp.x][tmp.y]) {
        possible_move right;
        right.num = 4;
        right.distance = this->hammingDistance(tmp, T);
        priority_direction.append(right);
    }

    if (priority_direction.length() < 1) {
        this->deleteHistoryB4();
        this->blankPossibleMoveTo(x, y);
    }

    for (int i=0; i < priority_direction.length(); i++) {
        for (int j=0; j < priority_direction.length(); j++) {
            if (priority_direction.at(j).distance > priority_direction.at(i).distance ) {
                //std::cout << priority_direction.at(j).distance << " < " << priority_direction.at(i).distance << std::endl;
                priority_direction.swap(i, j);
            }
        }
    }

    //for (int k=0; k < priority_direction.length(); k++) {
    //    std::cout << priority_direction.at(k).num << ": " << priority_direction.at(k).distance << std::endl;
    //}

    return priority_direction;

}

void MainWindow::moveBlankAboveP()
{
    std::cout << "moveBlankAboveP\n";
    std::cout << "blank x,y -> " << blank.x << "," << blank.y << std::endl;

    if (blank.x == P.x && blank.y == P.y - 1)
        return;

    QList <struct possible_move> pbm = this->blankPossibleMoveTo(P.x, P.y - 1);

    for (int i = 0; i < pbm.length(); i++ ) {
        if (pbm.at(i).num == 1)
            this->swapBlankToUpper();
        else if (pbm.at(i).num == 2)
            this->swapBlankToUnder();
        else if (pbm.at(i).num == 3)
            this->swapBlankToLeft();
        else if (pbm.at(i).num == 4)
            this->swapBlankToRight();
        break;
    }
    this->moveBlankAboveP();

}

void MainWindow::moveBlankLeftP()
{
    std::cout << "moveBlankLeftP\n";
    std::cout << "blank x,y -> " << blank.x << "," << blank.y << std::endl;

    if (blank.x == P.x - 1 && blank.y == P.y)
        return;

    QList <struct possible_move> pbm = this->blankPossibleMoveTo(P.x - 1, P.y);

    for (int i = 0; i < pbm.length(); i++ ) {
        if (pbm.at(i).num == 1)
            this->swapBlankToUpper();
        else if (pbm.at(i).num == 2)
            this->swapBlankToUnder();
        else if (pbm.at(i).num == 3)
            this->swapBlankToLeft();
        else if (pbm.at(i).num == 4)
            this->swapBlankToRight();
        break;
    }
    this->moveBlankLeftP();
}

void MainWindow::moveBlankUnderP()
{
    std::cout << "moveBlankUnderP\n";
    std::cout << "blank x,y -> " << blank.x << "," << blank.y << std::endl;

    if (blank.x == P.x && blank.y == P.y + 1)
        return;

    QList <struct possible_move> pbm = this->blankPossibleMoveTo(P.x, P.y + 1);

    for (int i = 0; i < pbm.length(); i++ ) {
        if (pbm.at(i).num == 1)
            this->swapBlankToUpper();
        else if (pbm.at(i).num == 2)
            this->swapBlankToUnder();
        else if (pbm.at(i).num == 3)
            this->swapBlankToLeft();
        else if (pbm.at(i).num == 4)
            this->swapBlankToRight();
        break;
    }
    this->moveBlankUnderP();
}

void MainWindow::moveBlankRightP()
{
    std::cout << "moveBlankRightP\n";
    std::cout << "blank x,y -> " << blank.x << "," << blank.y << std::endl;

    if (blank.x == P.x + 1 && blank.y == P.y)
        return;

    QList <struct possible_move> pbm = this->blankPossibleMoveTo(P.x + 1, P.y);

    for (int i = 0; i < pbm.length(); i++ ) {
        if (pbm.at(i).num == 1)
            this->swapBlankToUpper();
        else if (pbm.at(i).num == 2)
            this->swapBlankToUnder();
        else if (pbm.at(i).num == 3)
            this->swapBlankToLeft();
        else if (pbm.at(i).num == 4)
            this->swapBlankToRight();
        break;
    }
    this->moveBlankRightP();
}

void MainWindow::swapBlankToUpper()
{
    // std::cout << "swtichBlankToUpper\n";
    std::cout << "si blank gerak ke atas" << std::endl;
    coord target;

    target.x = blank.x;
    target.y = blank.y - 1;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank.x][blank.y] = temp_;
    blank = this->findPCoord(" ");
    this->printMatToConsole();
}

void MainWindow::swapBlankToLeft()
{
    // std::cout << "swapBlankToLeft\n";
    std::cout << "si blank gerak ke kiri" << std::endl;
    coord target;
    target.x = blank.x - 1;
    target.y = blank.y;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank.x][blank.y] = temp_;
    blank = this->findPCoord(" ");
    this->printMatToConsole();
}

void MainWindow::swapBlankToRight()
{
    // std::cout << "swapBlankToRight\n";
    std::cout << "si blank gerak ke kanan" << std::endl;
    coord target;
    target.x = blank.x + 1;
    target.y = blank.y;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank.x][blank.y] = temp_;
    blank = this->findPCoord(" ");
    this->printMatToConsole();
}

void MainWindow::swapBlankToUnder()
{
    // std::cout << "swtichBlankToUpper\n";
    std::cout << "si blank gerak ke bawah" << std::endl;
    coord target;

    target.x = blank.x;
    target.y = blank.y + 1;

    std::cout << "target blank x,y -> " << target.x << "," << target.y << " = " << map[target.x][target.y].toStdString() << std::endl;

    QString temp_ = map[target.x][target.y];
    map[target.x][target.y] = " ";
    map[blank.x][blank.y] = temp_;
    blank = this->findPCoord(" ");
    this->printMatToConsole();
}

void MainWindow::swapBlankWithP()
{
    // std::cout << "swapBlankWithP\n";
    // std::cout << "si blank tukeran sama " << p.toStdString() << std::endl;
    QString p = map[P.x][P.y];
    map[P.x][P.y] = " ";
    map[blank.x][blank.y] = p;
    blank = this->findPCoord(" ");
    this->printMatToConsole();
}

bool MainWindow::swapBlankIsValid(int x, int y)
{
    QString temp_map[dimension][dimension] = map;
    QString sw = temp_map[x][y];
    temp_map[x][y] = " ";
    temp_map[blank.x][blank.y] = sw;

    QString key_ = "";

    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            key_ += temp_map[j][i];
        }
    }

    for (int k=0; k < history.length(); k++){
        if (history.at(k) == key_)
            return false;
    }

    return true;
}

void MainWindow::deleteHistoryB4()
{
    QString last_history = history.last();
    std::cout << "clear history before this -> " << last_history.toStdString() << std::endl;
    history.clear();
    history.append(last_history);
}

void MainWindow::lockCoord(int x, int y)
{
    this->locked[x][y] = true;
}

void MainWindow::unlockCoord(int x, int y)
{
    this->locked[x][y] = false;
}
