#pragma once
#include "common.h"
#include "SphereCollider.h"
#include "BulletsBase.h"
class CharBase : public SphereCollider
{
private:
    //bullets(�|�C���^�z��p)
    T_Location speed;
    

protected:
    int* image;
    BulletsBase** bullets;

public:
    CharBase(T_Location location, float radius, T_Location speed);

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;
    BulletsBase** GetBullets();
    //GetBullets
};

