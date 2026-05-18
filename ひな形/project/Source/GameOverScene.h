#pragma once
#include "../Library/SceneBase.h"

class GameOverScene :public SceneBase
{
public:
	GameOverScene();
	~GameOverScene();

//	void Update();
	void Draw();

private:
	int gameoverImage;
};