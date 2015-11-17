#include "mainwindow.h"
#include "drawingArea.hpp"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(this, &MainWindow::drawMap, ui->graphicsView, &drawingArea::drawSomething);
    for(int i = 0; i != 19 * 20; ++i)
    {
        GomokuButton* tmp = new GomokuButton();
        connect(tmp, &GomokuButton::clicked, [this, tmp](){tmp->setStyleSheet(getPlayerCss().c_str());});
        _buttons.push_back(tmp);
    }
    int x = 0;
    int y = 0;
    std::cout << x << ", " << y << std::endl;
    for (auto button : _buttons)
    {
        ui->gridLayout->addWidget(button, x, y);
        ++x;
        if (x == 20) {
            y += 1;
            x = 0;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief MainWindow::on_PvP_clicked
 * Autre méthode plus rapide pour pouvoir set un event : on ne passe pas parun slot de widget mais on appelle des méthodes des widgets de la fenêtre
 * \warning Non réutilisable, et surement moins "propre"
 */

void MainWindow::on_PvP_clicked()
{
    ui->PvP->setText("Will Player win ?");

    //emit drawMap();
}

std::string MainWindow::getPlayerCss()
{
    static bool player = true;

    player = !player;
    return (player) ? "background-color:red" : "background-color:blue";
}
