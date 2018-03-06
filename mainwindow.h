#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <iostream>
#include "qdebug.h"
#include <QtMath>

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

    void updateUILineEditRegex();
    void disabledAllLineEdit(bool condition);
    void autoFocus();
    void mapToMat();
    void printMatToConsole();
    void movePToXY(QString p, int x, int y);


    struct coord {
        int x = 0;
        int y = 0;
    };

    void moveBlankAboveP(struct coord p_coord, int x_direction);
    void moveBlankLeftP(struct coord p_coord, int x_direction);
    struct coord findPCoord(QString p);
    int hammingDistance(struct coord a, struct coord b);
    void switchBlankToUpper(struct coord blank_coord);
    void switchBlankToLeft(struct coord blank_coord);
    void switchBlankToRight(struct coord blank_coord);
    void switchBlankToUnder(struct coord blank_coord);


    void switchBlankWithP(QString p);
};

#endif // MAINWINDOW_H
