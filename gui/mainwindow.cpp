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

	IGameMap::caseContent cc = _gm->didClickCase(tmp->getX(), tmp->getY());
	std::cout << cc << std::endl;
	setButtonColor(tmp->getX(), tmp->getY(), cc);

	std::cout << "Clicked on : " << tmp->getX() << " " << tmp->getY() << std::endl;

      });
      _buttons.push_back(tmp);
    }

  connect(ui->PvP, &QPushButton::clicked, [this](){
    this->_gm->createGame(IGame::PVP);
    std::cout << "Clicked on launch button" << std::endl;
  });


  int x = 0;
  int y = 0;
  std::cout << x << ", " << y << std::endl;
  for (auto button : _buttons)
    {
      ui->gridLayout->addWidget(button, button->getX(), button->getY());
    }
}

MainWindow::~MainWindow()
{
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

//deprecated
void MainWindow::getPlayerCss(int x, int y)
{
  std::cerr << "deprecated function" << std::endl;
    // static bool player = true;

    // player = !player;
    // setButtonColor(x, y, (player) ? RED : );
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
