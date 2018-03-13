#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <iostream>
#include "qdebug.h"
#include <QtMath>
#include <unistd.h>
#include <QApplication>

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
    void on_lineEdit_textChanged();

    void on_lineEdit_2_textChanged();

    void on_lineEdit_3_textChanged();

    void on_lineEdit_4_textChanged();

    void on_lineEdit_5_textChanged();

    void on_lineEdit_6_textChanged();

    void on_lineEdit_7_textChanged();

    void on_lineEdit_8_textChanged();

    void on_lineEdit_9_textChanged();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QList<QLineEdit*> lineedit_list;
    static const int dimension = 3;
    QString map[dimension][dimension];
    bool locked[dimension][dimension] = {};
    QList<QString> history;

    void updateUILineEditRegex();
    void disabledAllLineEdit(bool condition);
    void autoFocus();
    void mapToMat();
    void printMatToConsole();
    void movePToXY(QString p, int x, int y);
    void moveBlankToXY(int x, int y);

    struct coord {
        int x = 0;
        int y = 0;
    };

    struct possible_move{
        int num;
        int distance;
    };


    coord blank, P;

    void moveBlankAboveP();
    void moveBlankLeftP();
    void moveBlankUnderP();
    void moveBlankRightP();
    struct coord findPCoord(QString p);
    int hammingDistance(struct coord a, struct coord b);
    bool coordIsPossible(struct coord c);
    void swapBlankToUpper();
    void swapBlankToLeft();
    void swapBlankToRight();
    void swapBlankToUnder();
    void lockCoord(int x, int y);
    void unlockCoord(int x, int y);
    QList<struct possible_move> blankPossibleMoveTo(int x, int y);
    void swapBlankWithP();
    bool swapBlankIsValid(int x, int y);
    void deleteHistoryB4();
};

#endif // MAINWINDOW_H
