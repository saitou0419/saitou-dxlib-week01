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
	enemy = new Enemy(10000, 500); //出現　位置

	shutterSE = LoadSoundMem("data/sound/Camera.mp3");
	isGameOver = false;

	gameOverTimer = 0;
	score = 0;

	scoreFont = CreateFontToHandle("Arial", 40, 3);
	scoreTimer = 0;

	ruleImage = LoadGraph("data/image/ru-ru.png");
	ruleAlpha = 255;
	ruleTimer = 0;
	showRule = true;
	shotCount = 0;
	
	isFlash = false;

	flashAlpha = 0;
	

}

PlayScene::~PlayScene()
{
	//無し
}

void PlayScene::Update()
{

	field->Update();
	player->Update(field);
	enemy->Update();
	if (enemy->GetX() <= 300 && enemy->GetX() >= 120 && player->GetY() >= 350)//おばけの判定
	{
		if (player->GetY() >= 350)
		{
			SceneManager::ChangeScene("GAMEOVER");
			isGameOver = true;
		}
		if (player->GetY() >= 200 && player->GetY() <= 320)
		{
			isGameOver = true;
		}
	}
	int playerIndex = (200 + 50 - field->GetGroundScrollX()) / 150;
	if (field->GetMap(playerIndex) == 2)
	{
		if (player->GetY() >= 330 && player->GetY() <= 420) //地面の当たり判定
		{
			SceneManager::ChangeScene("GAMEOVER");
			isGameOver = true;
		}
	}
	if (isGameOver == true) 
	{
		gameOverTimer++; 
		if (gameOverTimer >= 60) 
		{
			SceneManager::ChangeScene("GAMEOVER");
		}
	}
	
	if (isGameOver == false)
	{
		scoreTimer++;

		if (scoreTimer >= 10)
		{
			score++;

			scoreTimer = 0;
		}

	}
	if (showRule == true)
	{
		ruleTimer++;

		if (ruleTimer >= 260)//ルール画像の秒数
		{
			ruleAlpha -= 5;
			if (ruleAlpha <= 0)
			{
				ruleAlpha = 0;
				showRule = false;
			}
		}
	}
	


	if (CheckHitKey(KEY_INPUT_T))
	{
		SceneManager::ChangeScene("TITLE");
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		if (enemy->GetX() <= 450 &&enemy->GetX() >= 150 && player->GetY() >= 350)
		{
			if (enemy->GetScored() == false)
			{
				score += 100;
				shotCount++;
				if (shotCount >= 5)
				{
					enemy->SetSpeed(20);
					field->AddSpeed(1);
					isFlash = true; 
					flashAlpha = 255;
					shotCount = 0;
					
				}

				enemy->SetScored(true);
				enemy->SetAlive(false);
				PlaySoundMem(shutterSE, DX_PLAYTYPE_BACK);
			}
		}
	}
	if (isFlash == true)
	{
		flashAlpha -= 10;
		if (flashAlpha <= 0)
		{
			flashAlpha = 0;
			isFlash = false;
		}
	}
}

void PlayScene::Draw()
{
	field->Draw();

	player->Draw();

	enemy->Draw();

    DrawFormatStringToHandle(1500,50,GetColor(255, 255, 255),scoreFont,"SCORE : %05d",score);//スコア表示座標

	if (showRule == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ruleAlpha);
		DrawExtendGraph(250, 50, 1650, 750, ruleImage, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (isFlash == true)
	{
		
		SetDrawBlendMode(	DX_BLENDMODE_ALPHA,flashAlpha);

		DrawBox(0,0,1920,760,GetColor(255, 255, 255),TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,	0);
	}

}

