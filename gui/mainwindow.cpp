#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}
