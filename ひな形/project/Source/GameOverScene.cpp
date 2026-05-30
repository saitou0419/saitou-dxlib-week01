#include "GameOverScene.h"
#include "DxLib.h"
#include "../Library/SceneManager.h"

GameOverScene::GameOverScene()
{
	gameoverImage = LoadGraph("data/image/Game Over.png");
	TImage = LoadGraph("data/image/T.png");
	alpha = 0;
}

GameOverScene::~GameOverScene()
{
	DeleteGraph(gameoverImage);
}
void GameOverScene::Update()
{
	if (alpha < 255)
	{
		alpha += 1;
	}
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
	
}
void GameOverScene::Draw() 
{ 
	DrawBox(0, 0, 1920, 760, GetColor(170, 150, 255), TRUE);
	DrawGraph(-100, 150, gameoverImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawExtendGraph(650, 80, 1250, 680, TImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	
}
