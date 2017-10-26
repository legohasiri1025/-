#pragma once
#include "define.h"
#include<Siv3D.hpp>


class player{
private:
	point m_position;
	//Array<player>playergraphic;
	graphic player_graphic[16];
public:
	int grnum = 0;
	count plgr = 0;

	player();

	void updata();
	void draw();

	~player();
};

