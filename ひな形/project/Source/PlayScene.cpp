#include "PlayScene.h"
#include "Player.h"
#include "Field.h"
#include"Enemy.h"
#include "../Library/SceneManager.h"

PlayScene::PlayScene()
{
	field = new Field();
	player = new Player(200, 420);
	enemy = new Enemy(3000, 500);//oŒ»@ˆÊ’u
}

PlayScene::~PlayScene()
{
	
}

void PlayScene::Update()
{

	field->Update();
	player->Update(field);
	enemy->Update();
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
