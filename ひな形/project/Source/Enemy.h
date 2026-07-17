#pragma once
#include "../Library/GameObject.h"

class Enemy : public GameObject
{
public:
    Enemy(int sx, int sy);
    ~Enemy();

    void Update();
    void Draw();

    float GetX()     //現在のお化けのX座標
    {
        return x;
    }
    float GetY()    //お化けY座標
    {
        return y;
    }
    bool GetScored();            //　撮影済みか確
    void SetScored(bool flag);   //　撮影済み
    void SetAlive(bool flag);   
    void SetSpeed(int s);        //　お化けの速度


private:
    static const int ANIM_FRAME = 6;    //アニメーション（お化け）

    int m_image[6];      
    int m_animIndex;     
    int m_animTimer;     //　画像切り替えタイマー
    int respawnTimer;    //　（再）出現タイマー
    int speed;          //　　移動速度
    float x;           
    float y;         

    bool isAlive;       
    bool scored;       //　　撮影しているかの確認
    bool hardMode;

};