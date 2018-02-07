#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "rope.h"
#include "ropecreate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void update_rope_list();
    RopeCreate *mCreateWindow{nullptr};

private slots:
    void on_actionQuit_triggered();

    void on_mButtonRun_clicked();

    void on_mButtonStop_clicked();

    void updateRope();

    void on_mButtonClear_clicked();

    void on_mAddButton_clicked();

    void on_mSimSpeedSlider_valueChanged(int value);

private:
    void draw_ropes();
    void break_rope(Rope *rope, std::list<RopeNode*>::iterator break_node);

    Ui::MainWindow *ui;
    std::list<Rope*> mRopes;
    std::list<Rope*> mInitRopes;
    QTimer *mRopeUpdateTimer = new QTimer(this);
    int mTimerTic{75};


};

#endif // MAINWINDOW_H
