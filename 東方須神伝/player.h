#pragma once
#include "define.h"
#include<Siv3D.hpp>
#include "front.h"


extern int32 score;
extern int32 player_num;
extern int32 bomb;
extern double power;
extern int32 point_i;
extern int32 graze;


class player{
private:
	
	speed plspeed;
	int grnum = 0;
	count plgr = 0;
	Texture playergraphic;
	Texture sloweff;
	speed slow, firsr;
	bool l, r, u, d, s;
	point p_position;


	point pshot_r[PSHOT_MAX];
	point pshot_l[PSHOT_MAX];
	speed pshot_speed;
	bool shot_b_r[PSHOT_MAX];
	bool shot_b_l[PSHOT_MAX];

	Texture pshot;
	count shotcount;
	Sound shotse;
	Color color;
	Font font;

public:
	player();

	virtual void data();
	virtual void draw();
	virtual void shot();
	virtual void updata();

	~player();
};
