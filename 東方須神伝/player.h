#pragma once
#include "define.h"
#include<Siv3D.hpp>


class player{
private:
	point p_position;
	speed plspeed;
	int grnum = 0;
	count plgr = 0;
	Texture playergraphic;
	Texture sloweff;
	speed slow, firsr;
	bool l, r, u, d, s;
public:
	player();

	void data();
	void draw();
	void updata();

	~player();
};

