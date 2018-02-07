#ifndef WAVENODE_H
#define WAVENODE_H

#include "ropenode.h"
#include "vector3.h"


class WaveNode : public RopeNode
{
public:
    WaveNode();
    WaveNode(Vector3 loc, Vector3 vel=Vector3(), double mass=0.1);
    static void convert_to(RopeNode **node, Vector3 waveDir, float amplitude, float frequency);
    virtual void update_node(double dt);

private:
    Vector3 mDir = Vector3();
    Vector3 mPos0 = Vector3();
    float mTime{0};
    float mAmp{0};
    float mFreq{0};
};

#endif // WAVENODE_H
