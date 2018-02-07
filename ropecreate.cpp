#include "ropecreate.h"
#include "ui_ropecreate.h"
#include "rope.h"
#include "vector3.h"
#include "fixednode.h"

RopeCreate::RopeCreate(QWidget *parent, std::list<Rope *> *ropes) :
    QDialog(parent),
    ui(new Ui::RopeCreate)
{
    ui->setupUi(this);
    this->mRopes = ropes;
}

RopeCreate::~RopeCreate()
{
    delete ui;
}


void RopeCreate::on_buttonBox_accepted()
{
    // create the rope
    Rope *new_rope = new Rope(Vector3(ui->mXStart->value(), ui->mYStart->value(), ui->mZStart->value()),
                              Vector3(ui->mXEnd->value(), ui->mYEnd->value(), ui->mZEnd->value()));
    std::list<RopeNode*> *nodes = new_rope->getNodes();
    // get the front node
    RopeNode *front = *nodes->begin();
    // get the end node
    std::list<RopeNode*>::iterator it = nodes->end();
    it--;
    RopeNode *end = *it;

    // make any necessary changes
    // update the masses if needed
    if(ui->mDefineStartMass->isChecked())
    {
        front->set_mass(ui->mStartMass->value());
    }
    if(ui->mDefineEndMass->isChecked())
    {
        end->set_mass(ui->mEndMass->value());
    }

    // convert the start note where needed
    if(ui->mStartFixed->isChecked())
    {
        // fix the start node
        FixedNode::convert_to(&front);
    }

    else if(ui->mStartInitVel->isChecked())
    {
        // set the initial velocity
        front->set_vel(Vector3(ui->mXVelStart->value(), ui->mYVelStart->value(), ui->mZVelStart->value()));
    }

    // convert the end node where needed.
    if(ui->mEndFixed->isChecked())
    {
        // fix the end
        FixedNode::convert_to(&end);
    }
    else if(ui->mEndInitVel->isChecked())
    {
        // set the initial velocity
        end->set_vel(Vector3(ui->mXVelEnd->value(), ui->mYVelEnd->value(), ui->mZVelEnd->value()));
    }
    nodes->pop_front();
    nodes->push_front(front);
    nodes->pop_back();
    nodes->push_back(end);

    // add the rope to the ropes list
    mRopes->push_back(new_rope);
    this->close();
}
