#include "Field.h"
#include "DxLib.h"

Field::Field()
{
	m_bgImage = LoadGraph("date/image/mori.png");
	m_groundImage = LoadGraph("date/image/tuti02.png");
	GetGraphSize(m_bgImage, &m_bgWidth, NULL);
	m_bgScrollX = 0;
	m_groundScrollX = 0;
	

	/*ínå`*/

	for (int i = 0; i < MAP_SIZE; i++)
	{
		m_map[i] = 1;
		if (rand() % 5 == 0)
		{
			m_map[i] = 0;
		}
		if (rand() % 12 == 0)
		{
			m_map[i] = 2;
		}
	}
	
}

Field::~Field()//çÌèú
{

	DeleteGraph(m_bgImage);
	DeleteGraph(m_groundImage);

}

void Field::Update()
{
	m_bgScrollX -= 2;

	if (m_bgScrollX <= -m_bgWidth)
	{
		m_bgScrollX= 0;
	}
	m_groundScrollX -= 5;
	if (m_groundScrollX <= -64)
	{
		m_groundScrollX = 0;
	}
}

void Field::Draw()
{
	//DrawExtendGraph(0, 0, 1280, 611, m_bgImage, TRUE);//îwåi
	DrawGraph(m_bgScrollX, 0, m_bgImage, TRUE);

	DrawGraph(m_bgScrollX + m_bgWidth, 0, m_bgImage, TRUE);


	for (int i = 0; i < MAP_SIZE; i++)    //ínå`Åô
	{
		int drawX;
		 drawX = i * 64 + m_groundScrollX;

		if (m_map[i] == 1)
		{
			DrawGraph(drawX, 605, m_groundImage, TRUE);
		}

		if (m_map[i] == 0) 
		{
			
		}
		if (m_map[i] == 2)
		{
			DrawGraph(drawX, 510, m_groundImage, TRUE);
			DrawGraph(drawX, 605, m_groundImage, TRUE); 
			
		}
		

	}

}