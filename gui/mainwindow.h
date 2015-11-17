#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gomokuButton.hpp"
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

enum buttonColor {
    Grey = 0,
    Red,
    Blue
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setButtonColor(int x, int y, buttonColor);

/*!
 * \brief slots : récepteurs d'events
 */

private slots:
    void on_PvP_clicked();

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
};

#endif // MAINWINDOW_H
