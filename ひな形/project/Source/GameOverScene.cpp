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
void GameOverScene::Draw() { DrawGraph(0, 0, gameoverImage, TRUE); }
