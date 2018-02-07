#ifndef ROPENODE_H
#define ROPENODE_H

#include <list>
#include <string>
#include "vector3.h"



class RopeNode
{
public:
    RopeNode();
    RopeNode(double init_x, double init_y, double init_z, double init_vx = 0.0, double init_vy = 0.0, double init_vz = 0.0, double mass = 0.1);
    RopeNode(Vector3 loc, Vector3 vel=Vector3(), double max_force = 1000, double mass = 0.25);
    // set the mass of the node
    set_mass(double mass);
    // get the mass of the node
    double get_mass();
    // return the x, y, z position of the node
    get_pos(double &x, double &y, double &z) const;
    // return a Vector3 representing the position of the node
    Vector3 get_pos_vec() const;
    // return the x, y, z velocity of the node
    const get_vel(double &x, double &y, double &z);
    // return the velocity vector
    Vector3 get_vel_vec() const;
    // set the velocity of the node
    set_vel(Vector3 vel);
    // calculate the distance from the node to node2
    double dist_to(const RopeNode* node2) const;
    // add forces that are acting on the node returns the current value of the tension on the node
    double add_force(Vector3 force);
    // get the current set distance to the next node
    double get_next_dist();
    // set the distance to the next node
    void set_next_dist(double next_dist);
    // perform the integration to update the position and velocity of the node
    virtual void update_node(double dt) = 0;
    // return the tension on the node
    double get_tension();
    // clear the forces on the node
    void clear_forces();
    // return the node infor
    std::string get_info();

protected:

    // mass of the node
    double mMass{0.25};

    // node position
    Vector3 mPos;

    // node velocity
    Vector3 mVel;

    // forces acting on the node
    Vector3 mForces;

    // sum of the force magnitudes action on the node
    double mSumForceMag{0};
    
    // distance to the next node
    double mNextDist{-1};
    
    // rate of change for the internode distance
    double mDeltaNextDist{-1};

    // max allowable force
    double mMaxForce{1000};

};

#endif // ROPENODE_H
