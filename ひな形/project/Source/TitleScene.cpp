#include "TitleScene.h"
#include "../Library/SceneManager.h" //¡‚Ç‚Ì‰æ–Ê‚ğ•\¦‚·‚é‚©ŠÇ—

TitleScene::TitleScene()
{
	m_titleImage = LoadGraph("date/image/Game Logo01.png");
	m_logoImage = LoadGraph("date/image/START.png");
}

TitleScene::~TitleScene()  //ƒV[ƒ“Ø‚è‘Ö‚¦@ƒƒ‚ƒŠÁ‹
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
	DrawBox(0, 0, 1920, 760, GetColor(170, 100, 255), TRUE);//”wŒiƒJƒ‰[
	DrawExtendGraph(570, 80, 1350, 680, m_titleImage, TRUE);//‰æ‘œ‚ÌŠg‘åk¬@–½—ß

	DrawExtendGraph(605, 620, 1315, 710, m_logoImage, TRUE);//ƒƒS(Start)‚ÌŠg‘åk¬@–½—ß
}
