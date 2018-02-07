#include "wavenode.h"
#include <cmath>
#include <iostream>

WaveNode::WaveNode()
{
}

WaveNode::WaveNode(Vector3 loc, Vector3 vel, double mass) : RopeNode(loc, vel, mass)
{
}

void WaveNode::convert_to(RopeNode **node, Vector3 waveDir, float amplitude, float frequency)
{
    WaveNode *new_node = new WaveNode((*node)->get_pos_vec(), (*node)->get_vel_vec(), (*node)->get_mass());
    RopeNode *temp = *node;
    delete temp;
    *node = new_node;
    new_node->mAmp = amplitude;
    new_node->mFreq = frequency;
    waveDir.normalize();
    new_node->mDir = waveDir;
    new_node->mPos0 = new_node->mPos;
}

void WaveNode::update_node(double dt)
{
    this->mTime += dt;
    double wave = this->mAmp * sin(this->mFreq * this->mTime);
    this->mPos = this->mPos0 + wave * this->mDir;
}

