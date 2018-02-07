#ifndef ROPE_H
#define ROPE_H

#include "vector3.h"
#include "ropenode.h"
#include <list>

class Rope
{
public:
    Rope();
    Rope(Vector3 startLoc, Vector3 endLoc);
    ~Rope();
    std::list<RopeNode *> *getNodes();
    // adds a node to the back of the ropenode list
    void add_node(RopeNode* node);
    // set the stiffness of the rope

    // set the inter-node distance

    // set the rope mass

    // set the damping of the rope

    // calculate the forces on each node
    bool calculate_forces();

    // update each node
    update(double dt);

    // print the rope
    print();

    std::list<RopeNode*>::iterator get_break_node();

    int get_break_count();


private:
    // list to hold rope nodes

    std::list<RopeNode*> *mNodes = new std::list<RopeNode*>;
    double mStiffness{4000};
    double mNodeDist{0.75};
    double mNodeMass{0.3};
    double mMaxforce{500};
    std::list<RopeNode*>::iterator mBreakNode;
    int mBreakCount{0};
    int mBreakCountMax{15};
    int mResetCounter{0};
    int mResetCounterMax{30};
};

#endif // ROPE_H
