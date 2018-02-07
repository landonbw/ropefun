#include "inertialnode.h"
#include "ropenode.h"

InertialNode::InertialNode()
{}

InertialNode::InertialNode(Vector3 pos, Vector3 vel, double max_force, double mass) : RopeNode(pos, vel, max_force, mass)
{}

void InertialNode::update_node(double dt)
{
    Vector3 accel;
    // if there are no forces acceleration is 0
    if (mForces.length() != 0)
    {
        // find the acceleration of the node
        accel = mForces / this->mMass;
    }
    // update node velocity
    this->mVel += accel * dt;
    this->mVel = this->mVel * mDampingFactor;
    // update node position
    this->mPos += this->mVel * dt;
}
