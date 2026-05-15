#pragma once
#include "../Library/GameObject.h"

class Field : public GameObject
{
public:
	Field();
	~Field();

	void Update();
	void Draw();

private:
	 
	static const int MAP_SIZE = 60;  //マップの大きさ　固定

	int m_bgImage;  //背景 画像
	int m_groundImage; //地面　画像
	int m_map[MAP_SIZE];  //マップ情報配列
	int m_bgWidth; //サイズ
	int m_bgScrollX;//背景スクロール
	int m_groundScrollX;//地面スクロール
};