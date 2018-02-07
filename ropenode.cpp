#include "ropenode.h"
#include <cmath>

RopeNode::RopeNode()
{

}

RopeNode::RopeNode(double init_x, double init_y, double init_z, double init_vx, double init_vy, double init_vz, double mass)
{
    this->mPos.set_xyz(init_x, init_y, init_z);
    this->mVel.set_xyz(init_vx, init_vy, init_vz);
    this->mMass = mass;
}

RopeNode::RopeNode(Vector3 loc, Vector3 vel, double max_force, double mass)
{
    this->mPos = loc;
    this->mVel = vel;
    this->mMaxForce = max_force;
    this->mMass = mass;
}

RopeNode::set_mass(double mass)
{
    this->mMass = mass;
}

double RopeNode::get_mass()
{
    return this->mMass;
}

const RopeNode::get_vel(double &x, double &y, double &z)
{
    this->mVel.get_xyz(x, y, z);
}

Vector3 RopeNode::get_vel_vec() const
{
    return this->mVel;
}

RopeNode::set_vel(Vector3 vel)
{
    this->mVel = vel;
}

RopeNode::get_pos(double &x, double &y, double &z) const
{
    this->mPos.get_xyz(x, y, z);
}

Vector3 RopeNode::get_pos_vec() const
{
    return this->mPos;
}

double RopeNode::dist_to(const RopeNode *node2) const
{
    Vector3 pos2 = node2->get_pos_vec();
    Vector3 diff = this->mPos - pos2;
    double dist = diff.length();
    return dist;
}

double RopeNode::add_force(Vector3 force)
{
    mForces += force;
    mSumForceMag += force.length();
    double tension = ((mSumForceMag - mForces.length()) / 2);
    return tension;
}

double RopeNode::get_next_dist()
{
    return this->mNextDist;
}

void RopeNode::set_next_dist(double next_dist)
{
    this->mDeltaNextDist = next_dist - mNextDist;
    this->mNextDist = next_dist;
}

double RopeNode::get_tension()
{
    double tension = ((mSumForceMag - mForces.length()) / 2) / mMaxForce;
    if(tension > 1)
        tension = 1;
    this->mForces = Vector3();
    this->mSumForceMag = 0;
    return tension;
}

void RopeNode::clear_forces()
{
    this->mForces = Vector3();
    this->mSumForceMag = 0;
}





