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
    float GetY()
    {
        return y;
    }
    bool GetScored();
    void SetScored(bool flag);
    void SetAlive(bool flag);
    void SetSpeed(int s);

private:
    static const int ANIM_FRAME = 6;

    int m_image[6];
    int m_animIndex;
    int m_animTimer;
    int respawnTimer;
    int speed;
    float x;
    float y;

    bool isAlive;
    bool scored;

};