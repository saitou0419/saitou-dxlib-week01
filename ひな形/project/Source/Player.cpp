#include "Player.h"
#include "Field.h"

Player::Player(int sx, int sy)//初期設定
{
	x = sx; //x座標
	y = sy;

	velocity = 0;//移動スピード
	onGround = true;
	isCameraMode = false;

	m_animIndex = 0;
	m_animTimer = 0;

	//m_animIndex = LoadGraph("deta/image/Character 001.png");

	LoadDivGraph("date/image/Character 001.png",8, 4, 2, 384, 384, m_hImage);
}

Player::~Player()
{
	for (int i = 0; i < 8; i++)
	{
		DeleteGraph(m_hImage[i]);
	}

}

void Player::Update()//毎フレーム
{
	if (m_animTimer >= 8)//タイマー　８秒

	{
		m_animIndex++;  //１増やす
		if (m_animIndex >= ANIM_FRAME)
		{
			m_animIndex = 0;
		}
		m_animTimer = 0;


		//ジャンプ↓
		if (CheckHitKey(KEY_INPUT_SPACE) && onGround)
		{
			velocity = -18;
			onGround = false;
		}
		velocity += 0.9f;//重力

		y += velocity;//移動！！


			/*(仮)地面*/
			if (y >= 500)
			{
				y = 500;

				velocity = 0;

				onGround = true;
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
}

void Player::Draw()
{
	if (isCameraMode == false)
	{
		DrawExtendGraph((int)x, (int)y,(int)x+180,(int)y+180, m_hImage[m_animIndex],TRUE);
		
		
	}
	else
	{
		DrawExtendGraph((int)x, (int)y, (int)x + 180, (int)y + 180, m_hImage[4 + m_animIndex], TRUE);
	}

}





