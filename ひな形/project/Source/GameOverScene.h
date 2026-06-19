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
	int  TImage;           
	int alpha;             //透明度（ふわっとゆっくり現れる演出）
	int selectSE;
};