#ifndef FIXEDNODE_H
#define FIXEDNODE_H

#include "vector3.h"
#include "ropenode.h"


class FixedNode : public RopeNode
{
public:
    FixedNode();
    FixedNode(Vector3 pos, Vector3 vel=Vector3(), double mass=1.5);
    ~FixedNode();
    void static convert_to(RopeNode **node);
    void update_node(double dt);
};

#endif // FIXEDNODE_H
