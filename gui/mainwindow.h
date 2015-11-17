#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_PvP_clicked();

signals:
    void changeLabel(QString msg);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
