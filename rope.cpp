#include "rope.h"
#include "wavenode.h"
#include "inertialnode.h"
#include "fixednode.h"
#include <iterator>
#include <iostream>


Rope::Rope()
{

}

Rope::Rope(Vector3 startLoc, Vector3 endLoc)
{
    // calculate unit vector for rope direction
    Vector3 direction = (endLoc - startLoc);
    direction.normalize();
    Vector3 stepVec = direction * this->mNodeDist;

    //Store nodes in a list
    InertialNode *startNode = new InertialNode(startLoc, Vector3(), mMaxforce, mNodeMass);
    startNode->set_next_dist(this->mNodeDist);
    InertialNode *endNode = new InertialNode(endLoc, Vector3(), mMaxforce, mNodeMass);
    mNodes->push_back(startNode);
    while(this->mNodes->back()->dist_to(dynamic_cast<RopeNode*>(endNode)) > this->mNodeDist)
    {
        // take a step toward the end
        Vector3 newLoc = this->mNodes->back()->get_pos_vec() + stepVec;
        // add to the list
        InertialNode *newNode = new InertialNode(newLoc, Vector3(), mMaxforce, mNodeMass);
        newNode->set_next_dist(this->mNodeDist);
        this->mNodes->push_back(newNode);
    }
    mNodes->back()->set_next_dist(mNodes->back()->dist_to(dynamic_cast<RopeNode*>(endNode)));
    this->mNodes->push_back(endNode);

}

Rope::~Rope()
{
    for(RopeNode* node : *this->mNodes)
    {
        delete node;
    }
}

std::list<RopeNode*>* Rope::getNodes()
{
    return this->mNodes;
}

void Rope::add_node(RopeNode *node)
{
    this->mNodes->push_front(node);
}

bool Rope::calculate_forces()
{
    // calculate the distance -> force between each node
    for(std::list<RopeNode*>::iterator it = this->mNodes->begin(); it != this->mNodes->end(); ++it)
    {
        double tension;
        // add gravity to the node
        Vector3 gravity = Vector3(0, 0, -9.8 * (*it)->get_mass());
        (*it)->add_force(gravity);
        // find the distance to the next node if it exists
        std::list<RopeNode*>::iterator next = std::next(it, 1);
        if(next != mNodes->end())
        {
            // find the direction
            Vector3 interNodeDir = (*next)->get_pos_vec() - (*it)->get_pos_vec();
            // find the unit vector direction
            interNodeDir.normalize();
            // calculate the distance to the node
            double dist = (*it)->dist_to(dynamic_cast<RopeNode*>(*next));
            // find the corresponding force
            double deltaL = dist - this->mNodeDist;
//            double deltaL = dist - (*it)->get_next_dist();
            Vector3 interNodeForce = this->mStiffness * deltaL * interNodeDir;
            // add the force to the nodes
            tension = (*it)->add_force(interNodeForce);
            (*next)->add_force(-interNodeForce);
        }
        if (tension >= this->mMaxforce)
        {
            this->mBreakCount += 1;
            if(this->mBreakCount > mBreakCountMax)
            {
//                for(std::list<RopeNode*>::iterator it = this->mNodes->begin(); it != this->mNodes->end(); ++it)
//                {
//                    //(*it)->get_tension();
//                }
                this->mBreakNode = it;
                this->mBreakCount = -40;
                return true;
            }
        }
    }
    this->mBreakCount = 0;
    return false;
}

Rope::update(double dt)
{
    for(RopeNode *node : *this->mNodes)
    {
        node->update_node(dt);
    }
}

Rope::print()
{
    for(RopeNode *node : *this->mNodes)
    {
        node->get_pos_vec().print();
    }
}

std::list<RopeNode*>::iterator Rope::get_break_node()
{
    return this->mBreakNode;

}

int Rope::get_break_count()
{
    return this->mBreakCount;
}
