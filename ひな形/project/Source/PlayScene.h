#pragma once
#include "../Library/SceneBase.h"

/// <summary>
/// ゲームプレイのシーンを制御する
/// </summary>

class Field;
class Player;
class Enemy;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene();
	void Update() override;
	void Draw() override;
private:
	
	Field* field;
	Player* player;
	Enemy* enemy;
	bool isGameOver;       //ゲームオーバー
	int gameOverTimer;    //ゲームオーバー待ち時間
	int score;           // スコア
	static int highScore; // HI
	int scoreFont;       //スコアフォント
	int scoreTimer;     //スコア増加速度
	int flashAlpha;    //途中のフラッシュ（白）

	int ruleImage;     //画像（ルール）
	int ruleAlpha;    //ルール　途中の透明度
	int ruleTimer;    //ルール表示の時間
	int shutterSE;    //シャッター音のSE
	int shotCount;    //撮影（お化けの数）
	int bgm;
	bool showRule;    //ルール表示管理
	bool isFlash;     //フラッシュ表示管理

};
