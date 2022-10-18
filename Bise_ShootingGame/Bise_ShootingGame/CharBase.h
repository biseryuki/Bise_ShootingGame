#pragma once
#include "common.h"
#include "SphereCollider.h"
class CharBase : public SphereCollider
{
private:
    //bullets(ポインタ配列用)
    T_Location speed;

protected:
    int* image;

public:
    CharBase(T_Location location, float radius, T_Location speed);

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;
    //GetBullets
};

