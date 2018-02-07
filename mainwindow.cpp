#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wavenode.h"
#include "fixednode.h"
#include "inertialnode.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(mRopeUpdateTimer, SIGNAL(timeout()), this, SLOT(updateRope()));
    this->mRopeUpdateTimer->setTimerType(Qt::PreciseTimer);
    this->mCreateWindow = new RopeCreate(this, &(this->mRopes));
    ui->graphics->drawOrigin();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->mCreateWindow;
}

void MainWindow::update_rope_list()
{
    this->ui->mRopeListWidget->clear();
    for(Rope *rope: this->mRopes)
    {
        QString info = QString();
        Vector3 start = rope->getNodes()->front()->get_pos_vec();
        Vector3 end = rope->getNodes()->back()->get_pos_vec();
        info.append("Start: ");
        info.append(start.get_info());
        info.append("\tEnd: ");
        info.append(end.get_info());

        this->ui->mRopeListWidget->addItem(info);
    }
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_mButtonRun_clicked()
{
    mRopeUpdateTimer->start(mTimerTic);
}

void MainWindow::updateRope()
{
    bool breaks_rope = false;
    for(Rope* rope : mRopes)
    {
        for(int i = 0; i<15; i++)
        {
            breaks_rope = rope->calculate_forces();
            if(breaks_rope)
            {
                std::list<RopeNode*>::iterator break_node = rope->get_break_node();
                this->break_rope(rope, break_node);
                break;
            }
            else
            {
                rope->update(0.005);
            }
            this->draw_ropes();
        }
    }
}

void MainWindow::on_mButtonStop_clicked()
{
    mRopeUpdateTimer->stop();
}

//void MainWindow::on_mResetButton_clicked()
//{
//    this->on_mButtonStop_clicked();
//    // clear out the current ropes
//    for(Rope* rope : mRopes)
//    {
//        delete rope;
//    }
//    Rope* newRope = new Rope(Vector3(), Vector3(20, 0, 0));
//    Rope* newRope2 = new Rope(Vector3(0, 5, 0), Vector3(25, 5, 0));
//    mRopes.clear();
//    mRopes.push_back(newRope);
//    mRopes.push_back(newRope2);
//    ui->graphics->clear();
//    this->draw_ropes();
//}

void MainWindow::draw_ropes()
{
    this->ui->graphics->clear();
    for(Rope* rope : mRopes)
    {
        ui->graphics->drawRope(*rope->getNodes(), this->ui->mShowTension->isChecked());
    }
    this->ui->graphics->drawOrigin();
}

void MainWindow::break_rope(Rope *rope, std::list<RopeNode*>::iterator break_node)
{
    Rope* new_rope = new Rope();

    std::list<RopeNode*> *rope_nodes = rope->getNodes();

    while(break_node != --rope_nodes->end())
    {
        RopeNode* last_node = rope_nodes->back();
        new_rope->add_node(last_node);
        rope_nodes->pop_back();
    }
    if(new_rope->getNodes()->size() > 0)
    {
        this->mRopes.push_back(new_rope);
    }
    else
    {
        delete new_rope;
    }
    //this->on_mButtonStop_clicked();
}

void MainWindow::on_mButtonClear_clicked()
{
    while(!this->mRopes.empty())
    {
        delete this->mRopes.front();
        this->mRopes.pop_front();
    }
    this->draw_ropes();
    this->update_rope_list();
}

void MainWindow::on_mAddButton_clicked()
{
    this->on_mButtonStop_clicked();
    this->mCreateWindow->exec();
    this->draw_ropes();
    this->update_rope_list();
}

void MainWindow::on_mSimSpeedSlider_valueChanged(int value)
{
    this->mTimerTic = value;
    if(this->mRopeUpdateTimer->isActive())
    {
        this->on_mButtonStop_clicked();
        this->on_mButtonRun_clicked();
    }
}
