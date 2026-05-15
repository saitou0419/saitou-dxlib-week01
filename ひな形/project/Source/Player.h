#pragma once
#include "../Library/GameObject.h"


class Player : public GameObject
{
public:
	Player(int sx, int sy);
	~Player();
	void Update() override;
	void Draw() override;
private:
	static const int ANIM_FRAME = 4;
	int m_hImage[8];
	int m_animIndex;//¡‚Ì‰æ‘œ”Ô†
	int m_animTimer;//‘Ò‚¿ŠÔiØ‚è‘Ö‚¦jŠÔ
	//int hImage;
	float x, y;
	float velocity;
	float onGround;
	bool isCameraMode;
};