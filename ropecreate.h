#ifndef ROPECREATE_H
#define ROPECREATE_H

#include <QDialog>
#include "rope.h"

namespace Ui {
class RopeCreate;
}

class RopeCreate : public QDialog
{
    Q_OBJECT

public:
    explicit RopeCreate(QWidget *parent = 0, std::list<Rope *> *ropes = nullptr);
    ~RopeCreate();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::RopeCreate *ui;
    std::list<Rope*> *mRopes;
};

#endif // ROPECREATE_H
