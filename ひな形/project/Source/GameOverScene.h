#pragma once
#include "../Library/SceneBase.h"

class GameOverScene :public SceneBase
{
public:
	GameOverScene();
	~GameOverScene();

	void Update();
	void Draw();

private:
	int gameoverImage;     //ゲームオーバーの画像番号
	int  TImage;           //　「T」の画像番号
	int alpha;             //透明度（ふわっと現れる演出）
};