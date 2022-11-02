#pragma once
#include "common.h"
#include "SphereCollider.h"
#include "BulletsBase.h"
class CharBase : public SphereCollider
{
private:
    //bullets(ポインタ配列用)
    
    

protected:
    int* image;
    BulletsBase** bullets;
    T_Location speed;

public:
    CharBase(T_Location location, float radius, T_Location speed);

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit(int damage) = 0;
    BulletsBase** GetBullets();
    //GetBullets
    void DeleteBullet(int nulletNum);

};