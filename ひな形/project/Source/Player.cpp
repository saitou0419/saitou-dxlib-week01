#include "Player.h"
#include "Field.h"

Player::Player(int sx, int sy)//初期設定
{
	x = sx; //x座標
	y = sy;
	prevSpace = false;
	velocity = 0;//移動スピード
	onGround = true;
	isCameraMode = false;
	jumpCount = 0;
	m_animIndex = 0;
	m_animTimer = 0;
	
	
	
	LoadDivGraph("data/image/Character 001.png", 8, 4, 2, 384, 512, m_hImage);
	
}



Player::~Player()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(m_hImage[i]);
	}

}

void Player::Update(Field* field)//毎フレーム
{
	m_animTimer++;


	if (m_animTimer >= 8)//　８フレーム

	{
		m_animIndex++;  //１増やす
		if (m_animIndex >= ANIM_FRAME)
		{
			m_animIndex = 0;
		}
		m_animTimer = 0;
	}

	//ジャンプ↓

	bool nowSpace = CheckHitKey(KEY_INPUT_SPACE);

	if (nowSpace == true && prevSpace == false && jumpCount < 2)
	{
		if (jumpCount == 0)
		{

			velocity = -25;
		}
		else if (jumpCount == 1)
		{
			velocity = -15;
		}
		jumpCount++;
		
	}

	prevSpace = nowSpace;

	velocity += 1.0f;//重力

	y += velocity;//移動！！

	if (y >= 900)
	{
		SceneManager::ChangeScene("GAMEOVER");
	}

	/*(仮)地面*/
	int playerIndex = (x + 50 - field->GetGroundScrollX() * -1) / 150;
	if (field->GetMap(playerIndex) == 1)
	{
		if (velocity > 0 && y + 220 >= 610)
		{
			y = 420;
			velocity = 0;
			onGround = true;

			jumpCount = 0;
		}
		
	}
	else if (field->GetMap(playerIndex) == 2)
	{
		if (velocity > 0 && y + 220 >= 460)
		{
			y = 270;
			velocity = 0;
			onGround = true;

			jumpCount = 0;
		}
	}
	if (field->GetMap(playerIndex) == 0)
	{
		onGround = false;
	}

	/*キャラのカメラアクション*/
	if (CheckHitKey(KEY_INPUT_S))
	{
		isCameraMode = true;
	}
	else
	{
		isCameraMode = false;
	}

}
	


void Player::Draw()
{
	if (isCameraMode == false)
	{
		DrawExtendGraph((int)x, (int)y,(int)x+220,(int)y+220, m_hImage[m_animIndex],TRUE);
		
		
	}
	else
	{
		DrawExtendGraph((int)x, (int)y, (int)x + 220, (int)y + 220, m_hImage[4 + m_animIndex], TRUE);
	}
}










