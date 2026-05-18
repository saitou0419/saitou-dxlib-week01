#include "Enemy.h"
#include "DxLib.h"


Enemy::Enemy(int sx, int sy)
{
	x = sx;
	y = sy;

	m_animIndex = 0;
	m_animTimer = 0;
	respawnTimer = 0;

	isAlive = true;

	LoadDivGraph("data/image/obake.png", 6, 6,1, 178, 150, m_image);
	
	
}

Enemy::~Enemy()
{
	for (int i = 0; i < 6; i++)
	{
		DeleteGraph(m_image[i]);
	}
}
void Enemy::Update()
{
	if (isAlive == false)
	{
		respawnTimer++;

		if (respawnTimer >= 180)
		{
			x = 2200;
			y = 500;

			isAlive = true;
			respawnTimer = 0;
		}
		return;
	}
	x -= 9;
	if (CheckHitKey(KEY_INPUT_S))
	{
		if (x <= 450 && x >= 150)
		{
			isAlive = false;
		}
	}
	m_animTimer++;
	if (m_animTimer >= 20)
	{
		m_animIndex++;
		if (m_animIndex >= ANIM_FRAME)
		{
			m_animIndex = 0;
		}
		m_animTimer = 0;
	}
	if (x <= -200)
	{
		respawnTimer++;
	}
	if (respawnTimer >= 180 )
	{
		if (rand() % 100 < 3)
		{
			x =2200;
			y = 500;
			respawnTimer = 0;
		}
	}
	
} 
void Enemy::Draw()
{
	if (isAlive == true)
	{
		DrawExtendGraph((int)x, (int)y, (int)x + 120, (int)y + 120, m_image[m_animIndex], TRUE);
	}
}