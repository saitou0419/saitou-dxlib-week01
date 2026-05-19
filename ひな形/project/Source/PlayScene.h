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

	int shakePowet;
	int shakeTimer;

};
