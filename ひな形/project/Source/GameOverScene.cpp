#include "GameOverScene.h"
#include "DxLib.h"
#include "../Library/SceneManager.h"

GameOverScene::GameOverScene()
{
	gameoverImage = LoadGraph("data/image/Game Over.png");
}

GameOverScene::~GameOverScene()
{
	DeleteGraph(gameoverImage);
}
void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}
void GameOverScene::Draw() 
{ 
	DrawBox(0, 0, 1920, 760, GetColor(170, 100, 255), TRUE);
	DrawGraph(-100, 150, gameoverImage, TRUE);
//	DrawExtendGraph(260,55, 1400, 705, gameoverImage, TRUE);
}
