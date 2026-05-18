#include "Field.h"
#include "DxLib.h"

Field::Field()
{
	m_bgImage = LoadGraph("data/image/mori.png");
	m_groundImage = LoadGraph("data/image/tuti02.png");
	GetGraphSize(m_bgImage, &m_bgWidth, NULL);
	m_bgScrollX = 0;
	m_groundScrollX = 0;
	m_timer = 0;
	

	/*地形*/

	for (int i = 0; i < MAP_SIZE; i++)
	{
		
		{
			m_map[i] = 1;
		}
		
	}
	
}

Field::~Field()//削除
{

	DeleteGraph(m_bgImage);
	DeleteGraph(m_groundImage);

}
int Field::GetMap(int index)
{
	return m_map[index];
}
int Field::GetGroundScrollX()
{
	return m_groundScrollX;
}

void Field::Update()

{
	m_timer++;
	m_bgScrollX -= 2;

	if (m_bgScrollX <= -m_bgWidth)
	{
		m_bgScrollX = 0;
	}
	m_groundScrollX -= 9; //地面　1フレーム
	if (m_groundScrollX <= -150)
	{
		m_groundScrollX = 0;
		for (int i = 0; i < MAP_SIZE - 1; i++)
		{
			m_map[i] = m_map[i + 1];
		}
		if (m_timer < 120)//地形（地面）の速さ
			m_map[MAP_SIZE - 1] = 1;
	}
	else
	{
		int r = rand() % 10;


		if (r == 0)
		{
			m_map[MAP_SIZE - 1] = 2;
		}
		else
		{
			m_map[MAP_SIZE - 1] = 1;
		}
	}
}

	

void Field::Draw()
{
	
	DrawGraph(m_bgScrollX, 0, m_bgImage, TRUE);

	DrawGraph(m_bgScrollX + m_bgWidth, 0, m_bgImage, TRUE);


	for (int i = 0; i < MAP_SIZE; i++)    //地形☆
	{
		int drawX;
		 drawX = i * 150 + m_groundScrollX;

		if (m_map[i] == 1)
		{
			DrawGraph(drawX, 610, m_groundImage, TRUE);
		}

		if (m_map[i] == 0) 
		{
			
		}
		if (m_map[i] == 2)
		{
			DrawGraph(drawX, 460, m_groundImage, TRUE);
			
			
		}
		

	}

}