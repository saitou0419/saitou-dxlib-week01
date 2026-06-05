#include "PlayScene.h"
#include "Player.h"
#include "Field.h"
#include"Enemy.h"
#include "GameOverScene.h"
#include "../Library/SceneManager.h"

int PlayScene::highScore = 0;

PlayScene::PlayScene()
{
	field = new Field();
	player = new Player(200, 420); //キャラ出現　位置
	enemy = new Enemy(10000, 500); //お化け出現　位置

	shutterSE = LoadSoundMem("data/sound/Camera.mp3");
	
	isGameOver = false;   


	//↓タイマー・スコア・スコアタイマーを最初0
	gameOverTimer = 0;   
	score = 0;
	scoreTimer = 0;

	scoreFont = CreateFontToHandle("Arial", 40, 3);//スコア表示フォント
	ruleImage = LoadGraph("data/image/ru-ru.png");
	ruleAlpha = 255;     // ルール画像　最初は完全表示　255→すべて表示　０→透明
	ruleTimer = 0;      //　ルール画像表示を数えるタイマー
	showRule = true;    //　画像表示
	shotCount = 0;      //　撮影回数　０回
	isFlash = false;    //　フラッシュ　OFF
	flashAlpha = 0;     //  フラッシュ透明　０
	

}

PlayScene::~PlayScene()
{
	//無し
}

void PlayScene::Update()
{
	//↓　背景・プレイヤー・おばけ　を動かす
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
	if (field->GetMap(playerIndex) == 2)//高台衝突
	{
		if (player->GetY() >= 380 && player->GetY() <= 420) //地面の当たり判定
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
		scoreTimer++;   //スコア計算

		if (scoreTimer >= 10)
		{
			score++;

			scoreTimer = 0;
		}

	}
	if (score > highScore)
	{
		highScore = score;
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
		if (enemy->GetX() <= 400 &&enemy->GetX() >= 200 && player->GetY() >= 350)//お化けが撮影範囲内か
		{
			if (enemy->GetScored() == false)
			{
				score += 100;//写真　＋１００
				shotCount++;
				if (shotCount >= 5)//５回以上撮影
				{
					enemy->SetSpeed(12);//速度＋12
					field->AddSpeed(1);//背景スクロール＋１
					
					isFlash = true; 
					flashAlpha = 255;
					shotCount = 0;//回数リセット
					
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
	DrawFormatStringToHandle(1570, 20, GetColor(255, 255, 0), scoreFont, "HI :%07d", highScore);//HIスコア
    DrawFormatStringToHandle(1570,70,GetColor(255, 255, 255),scoreFont,"SCORE : %05d",score);//スコア表示座標

	if (showRule == true)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ruleAlpha);
		DrawExtendGraph(410, 30,1510, 730,ruleImage,TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	if (isFlash == true)
	{
		
		SetDrawBlendMode(	DX_BLENDMODE_ALPHA,flashAlpha);

		DrawBox(0,0,1920,760,GetColor(255, 255, 255),TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,	0);
	}

}

