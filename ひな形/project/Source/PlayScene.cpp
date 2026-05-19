#include "PlayScene.h"
#include "Player.h"
#include "Field.h"
#include"Enemy.h"
#include "GameOverScene.h"
#include "../Library/SceneManager.h"

PlayScene::PlayScene()
{
	field = new Field();
	player = new Player(200, 420);
	enemy = new Enemy(10000, 500);//出現　位置
}

PlayScene::~PlayScene()
{
	
}

void PlayScene::Update()
{

	field->Update();
	player->Update(field);
	enemy->Update();
	if (enemy->GetX() <= 350 && enemy->GetX() >= 150 && player->GetY() >= 350)//おばけの判定
	{
		if (player->GetY() >= 350)
		{
			SceneManager::ChangeScene("GAMEOVER");
		}
		if (player->GetY() >= 200 && player->GetY() <= 320)
		{
			SceneManager::ChangeScene("GAMEOVER");
		}
	}
	int playerIndex = (200 + 50 - field->GetGroundScrollX()) / 150;
	if (field->GetMap(playerIndex) == 2)
	{
		if (player->GetY() >= 330 && player->GetY() <= 420) //地面の当たり判定
		{
			SceneManager::ChangeScene("GAMEOVER");
		}
	}
	
	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	field->Draw();

	player->Draw();

	enemy->Draw();

	
}
