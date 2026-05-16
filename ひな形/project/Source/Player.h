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
private:
	static const int ANIM_FRAME = 4;
	int m_hImage[8];
	int m_animIndex;//今の画像番号
	int m_animTimer;//待ち時間（切り替え）時間
	int jumpCount;//2段ジャンプ
	float x, y;
	float velocity;

	bool onGround;
	bool isCameraMode;
	bool prevSpace;
};