#pragma once
#include "../Library/GameObject.h"

class Field : public GameObject
{
public:
	Field();
	~Field();

	void Update();
	void Draw();

	int GetMap(int index);        // 指定した場所の地形　（MAP全管理）
	int GetGroundScrollX();       //フィールドのスクロール
	void AddSpeed(int value);    //速度を増やす
	

private:
	 
	static const int MAP_SIZE = 60;  //マップの大きさ　固定

	int m_bgImage;         //背景 画像
	int m_groundImage;     //地面　画像
	int m_map[MAP_SIZE];   //マップ情報配列
	int m_bgWidth;         //サイズ
	int m_bgScrollX;       //背景スクロール
	int m_groundScrollX ; //地面スクロール
	int speed;            //背景の速さ
	int m_timer;          //時間を数えるタイマー
};