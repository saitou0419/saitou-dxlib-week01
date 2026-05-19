#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(int sx, int sy);
    ~Enemy();

    void Update();
    void Draw();

    float GetX()
    {
        return x;
    }
   

private:
    static const int ANIM_FRAME = 6;

    int m_image[6];
    int m_animIndex;
    int m_animTimer;
    int respawnTimer;
    float x;
    float y;

    bool isAlive;

};