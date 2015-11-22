#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gomokuButton.hpp"
#include "GameMap.hpp"
#include "IGameManager.hpp"
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/*enum buttonColor {
    Grey = 0,
    Red,
    Blue
    };*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, IGameManager*);
    ~MainWindow();
    void setButtonColor(int x, int y, IGameMap::caseContent);
    void reset();
    void setPlayer1Text(int score);
    void setPlayer2Text(int score);
    void setWin(int Player);
    void changeTurn();
/*!
 * \brief slots : récepteurs d'events
 */

private slots:
    void on_PvE_clicked();

/*!
 * \brief signals : emetteurs d'events
 */

signals:
    void drawMap();

private:
   void getPlayerCss(int x, int y);

private:
    Ui::MainWindow *ui;
    std::vector<GomokuButton*> _buttons;
    std::string _colors[3];
    IGameManager* _gm;
};

#endif // MAINWINDOW_H
