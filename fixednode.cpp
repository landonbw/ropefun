#include "fixednode.h"

FixedNode::FixedNode()
{}

FixedNode::FixedNode(Vector3 pos, Vector3 vel, double mass) : RopeNode(pos, vel, mass)
{}

FixedNode::~FixedNode()
{

}

void FixedNode::convert_to(RopeNode **node)
{
    FixedNode *new_node = new FixedNode((*node)->get_pos_vec(), (*node)->get_vel_vec(), (*node)->get_mass());
    RopeNode *temp = *node;
    delete temp;
    *node = new_node;
}

void FixedNode::update_node(double dt)
{
    this->mForces = Vector3();
    this->mSumForceMag = 0;
}
