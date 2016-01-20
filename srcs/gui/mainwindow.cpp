#include "IPlayer.hpp"
#include "mainwindow.h"
#include "drawingArea.hpp"
#include "ui_mainwindow.h"
#include "IJudge.hpp"
#include "DoubleThree.hpp"
#include "EatThem.hpp"
#include <sstream>
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
            _gm->didClickCase(tmp->getX(), tmp->getY());
            setPlayer1Text(_gm->getGame()->getPlayer(0)->getPoints());
            setPlayer2Text(_gm->getGame()->getPlayer(1)->getPoints());
        });
        tmp->OnMouseMove( [this, tmp] (QMouseEvent*e) {
            if (_gm->getGame() && _gm->getGame()->getActivePlayer() && tmp->isEmpty())
                setButtonColor(tmp->getX(), tmp->getY(), static_cast<Case::caseContent>(_gm->getGame()->getActivePlayer()->getColor()));
            if (!tmp->isEmpty())
                for(auto button : _buttons)
                    if (button->isEmpty())
                        button->setStyleSheet(std::string("background-color:grey").c_str());
        });
        _buttons.push_back(tmp);
    }

    connect(ui->PvP, &QPushButton::clicked, [this](){

        this->_gm->createGame(IGame::PVP);
        _mode = IGame::PVP;
        this->ui->AITimeoutBox->setVisible(false);
        this->ui->AILabel->setVisible(false);
    });

    connect(ui->PvE, &QPushButton::clicked, [this](){

        this->_gm->createGame(IGame::PVE);
        _mode = IGame::PVE;
        this->ui->AITimeoutBox->setVisible(true);
        this->ui->AILabel->setVisible(true);
    });

    connect(ui->pushButton, &QPushButton::clicked, [this](){
        this->_gm->removeGame();
        this->reset();
    });

    connect(ui->doubleThree, &QCheckBox::clicked, [this](bool state) {
        if (state == false)
            this->_gm->getJudge()->addRule(new DoubleThree());
        else
            this->_gm->getJudge()->removeRule(IRule::DOUBLETHREE);
    });

    connect(ui->eatThem, &QCheckBox::clicked, [this](bool state) {
        if (state == false) {
            this->_gm->getJudge()->removeRule(IRule::EATTHEM);
        }
        else {
            this->_gm->getJudge()->addRule(new EatThem());
        }
    });

    for (auto button : _buttons)
    {
        ui->gridLayout->addWidget(button, button->getX(), button->getY());
    }
    ui->playerTurn->setStyleSheet(std::string("background-color:blue").c_str());
    ui->score1->setStyleSheet(std::string("background-color:blue").c_str());
    ui->score2->setStyleSheet(std::string("background-color:red").c_str());
}

void	MainWindow::reset()
{
    for (auto button : _buttons)
    {
        button->setStyleSheet(std::string("background-color:grey").c_str());
        button->setEmpty(false);
    }
    ui->playerTurn->setStyleSheet(std::string("background-color:blue").c_str());
    ui->playerTurn->setText("Player Turn");
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
    this->_gm->createGame(IGame::PVE);
}

void MainWindow::setButtonColor(int x, int y, Case::caseContent col)
{
    for(auto button : _buttons)
    {
        if (button->getX() == x && button->getY() == y)
        {
            button->setStyleSheet(std::string("background-color:" + _colors[col]).c_str());
        }
        else if (button->isEmpty())
        {
            button->setStyleSheet(std::string("background-color:grey").c_str());
        }
    }
}

void MainWindow::setFull(int x, int y, bool defined)
{
    for(auto button : _buttons)
    {
        if (button->getX() == x && button->getY() == y)
        {
            button->setEmpty(defined);
        }
    }
}

void MainWindow::setPlayer1Text(int score)
{
    std::stringstream ss;
    std::string scoreStr;
    std::string str;

    ss << score;
    ss >> scoreStr;
    str = scoreStr;
    ui->score1->setStyleSheet(std::string("background-color:blue").c_str());
    ui->score1->setText(str.c_str());
}

void MainWindow::setPlayer2Text(int score)
{
    std::stringstream ss;
    std::string scoreStr;
    std::string str;

    ss << score;
    ss >> scoreStr;
    str = scoreStr;
    ui->score2->setStyleSheet(std::string("background-color:red").c_str());
    ui->score2->setText(str.c_str());
}

void MainWindow::setWin(int Player)
{
    std::string str;

    if (Player == 0)
        ui->playerTurn->setStyleSheet(std::string("background-color:blue").c_str());
    if (Player == 1)
        ui->playerTurn->setStyleSheet(std::string("background-color:red").c_str());
    ui->playerTurn->setText("Winner !");
}

void MainWindow::changeTurn()
{
    static bool turn = true;

    if (ui->playerTurn->text() == "Winner !")
        return;
    if (turn)
        ui->playerTurn->setStyleSheet(std::string("background-color:red").c_str());
    else
        ui->playerTurn->setStyleSheet(std::string("background-color:blue").c_str());
    turn = !turn;
}

void MainWindow::showError(std::string const& errorText)
{
    std::string str = "";
    if (errorText != "")
        str = "<font color='red'>Error occured : " + errorText + "</font color>";
    ui->ErrorMessage->setText(str.c_str());
}

double MainWindow::getAITimeout() const
{
   return ui->AITimeoutBox->value();
}
