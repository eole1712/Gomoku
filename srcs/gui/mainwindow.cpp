#include "mainwindow.h"
#include "drawingArea.hpp"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent, IGameManager* gm) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _gm(gm)
{
  _colors[0] = "grey";
  _colors[1] = "blue";
  _colors[2] = "red";
  ui->setupUi(this);
  ui->stackedWidget->setCurrentIndex(1);
  for(int i = 0; i != 19 * 19; ++i)
    {
      GomokuButton* tmp = new GomokuButton(i - 19 * (i / 19), i / 19);

      connect(tmp, &GomokuButton::clicked, [this, tmp](){

	std::cout << "Clicked on : " << tmp->getX() << " " << tmp->getY() << std::endl;

	_gm->didClickCase(tmp->getX(), tmp->getY());


	std::cout << "Clicked on : " << tmp->getX() << " " << tmp->getY() << std::endl;

      });
      _buttons.push_back(tmp);
    }

  connect(ui->PvP, &QPushButton::clicked, [this](){

    this->_gm->createGame(IGame::PVP);

    std::cout << "Clicked on launch button" << std::endl;
  });

  connect(ui->pushButton, &QPushButton::clicked, [this](){
    this->_gm->removeGame();
    this->reset();
  });


  int x = 0;
  int y = 0;
  std::cout << x << ", " << y << std::endl;
  for (auto button : _buttons)
    {
      ui->gridLayout->addWidget(button, button->getX(), button->getY());
    }
}

void	MainWindow::reset()
{
  for (auto button : _buttons)
    {
      button->setStyleSheet(std::string("background-color:grey").c_str());
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

void MainWindow::on_PvE_clicked()
{
    ui->PvE->setText("I'm not Implemented Yet");
}

void MainWindow::setButtonColor(int x, int y, IGameMap::caseContent col)
{
    for(auto button : _buttons)
    {
        if (button->getX() == x && button->getY() == y)
	  {
            button->setStyleSheet(std::string("background-color:" + _colors[col]).c_str());
	  }
    }
}

void MainWindow::setPlayer1Text(std::string const& str)
{
    ui->score1->setText(str.c_str());
}

void MainWindow::setPlayer2Text(std::string const& str)
{
    ui->score2->setText(str.c_str());
}
