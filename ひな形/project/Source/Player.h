#pragma once
#include "../Library/GameObject.h"


class Player : public GameObject
{
public:
	Player();
	Player(int sx, int sy);
	~Player();
	void Update() override;
	void Draw() override;
private:
	static const int ANIN_FRAME = 3;
	int hImage;
	float x, y;
	float velocity;
	float onGround;
};