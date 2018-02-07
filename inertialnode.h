#ifndef INERTIALNODE_H
#define INERTIALNODE_H

#include "vector3.h"
#include "ropenode.h"


class InertialNode : public RopeNode
{
public:
    InertialNode();
    InertialNode(Vector3 pos, Vector3 vel=Vector3(), double max_force=1000, double mass=0.5);
    void update_node(double dt);

private:
    double mDampingFactor{0.999};
//    double mDampingFactor{1};
};

#endif // INERTIALNODE_H
