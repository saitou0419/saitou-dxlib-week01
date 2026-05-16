#include "PlayScene.h"
#include "Player.h"
#include "Field.h"
#include "../Library/SceneManager.h"

PlayScene::PlayScene()
{
	field = new Field();
	player = new Player(200, 420);
}

PlayScene::~PlayScene()
{
	
}

void PlayScene::Update()
{

	field->Update();
	player->Update(field);

	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
}

void PlayScene::Draw()
{
	/*DrawString(0, 0, "TEST", GetColor(255, 255, 255));

	field->Draw();
	player->Draw();*/
}
