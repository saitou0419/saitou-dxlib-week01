#pragma once
#include "../Library/GameObject.h"

class Field;
class Player : public GameObject
{
public:
	Player(int sx, int sy);
	~Player();
	void Update(Field* field);
	void Draw() override;
	float GetY()
	{
		return y;
	}

private:
	static const int ANIM_FRAME = 4;   //アニメーション
	int m_hImage[8];    //画像を保存する
	int m_animIndex;    //今の画像番号
	int m_animTimer;    //待ち時間（切り替え）時間
	int jumpCount      ;//2段ジャンプ

	float x, y;         //プレイヤー位置
	float velocity;     //縦方向の速さ

	
	bool onGround;      //地面
	bool isCameraMode;  //カメラ
	bool prevSpace;     //スペース
};