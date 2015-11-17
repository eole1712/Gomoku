#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gomokuButton.hpp"
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

/*!
 * \brief slots : récepteurs d'events
 */

private slots:
    void on_PvP_clicked();
   // void buttonClicked(int, int);

/*!
 * \brief signals : emetteurs d'events
 */

signals:
    void drawMap();

private:
    std::string getPlayerCss();

private:
    Ui::MainWindow *ui;
    std::vector<GomokuButton*> _buttons;
};

#endif // MAINWINDOW_H
