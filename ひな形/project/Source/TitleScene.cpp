#include "TitleScene.h"
#include "../Library/SceneManager.h" //¡‚Ç‚Ì‰æ–Ê‚ğ•\¦‚·‚é‚©ŠÇ—

TitleScene::TitleScene()
{
	m_titleImage = LoadGraph("data/image/Game Logo01.png");
	m_logoImage = LoadGraph("data/image/START.png");
	m_haikeiImage = LoadGraph("data/image/haikei.png");
	startSE = LoadSoundMem("data/sound/botan.mp3");
}

TitleScene::~TitleScene()  //ƒV[ƒ“Ø‚è‘Ö‚¦@ƒƒ‚ƒŠÁ‹
{   
	DeleteGraph(m_titleImage);
	DeleteGraph(m_logoImage);
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE)) 
	{
		PlaySoundMem(startSE, DX_PLAYTYPE_BACK);
		SceneManager::ChangeScene("PLAY");
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}
}


void TitleScene::Draw()
{

	DrawExtendGraph(0, 0, 1920, 760, m_haikeiImage,TRUE);
	DrawExtendGraph(570, 80, 1350, 680, m_titleImage, TRUE);//‰æ‘œ‚ÌŠg‘åk¬@–½—ß

	DrawExtendGraph(590, 600, 1315, 710, m_logoImage, TRUE);//ƒƒS(Start)‚ÌŠg‘åk¬@–½—ß
}
