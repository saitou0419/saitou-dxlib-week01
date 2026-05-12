#include "TitleScene.h"

TitleScene::TitleScene()
{
	m_titleImage = LoadGraph("date/image/Game Logo01.png");
	m_logoImage = LoadGraph("date/image/START.png");
}

TitleScene::~TitleScene()
{   
	DeleteGraph(m_titleImage);
	DeleteGraph(m_logoImage);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{
	DrawExtendGraph//âÊëúÇÃägëÂèkè¨Å@ñΩóﬂ
	(200, 50, 1080, 650, m_titleImage, TRUE);

	DrawExtendGraph//ÉçÉS(Start)ÇÃägëÂèkè¨Å@ñΩóﬂ
	(240, 540, 950, 630, m_logoImage, TRUE);
}
