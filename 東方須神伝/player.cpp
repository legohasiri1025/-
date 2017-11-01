#include "define.h"
#include "playerdata.h"
#include "player.h"
#define PL01

player::player() :p_position(FIELD_CENTER_X, (FIELD_CENTER_Y + FIELD_MAX_Y) / 2)
{
	/*p_position = defaultpoint;
	player_graphic(L"../picture/pl0/player.png");
	playergraphic = pl;*/
#ifdef PL01
	playergraphic = Texture(L"picture/player/pl0/player.png");
	pshot = Texture(L"picture/player/pl0/shot.png");
	slow = PL01_SPEED_SLOW;
	firsr = PL01_SPEED_FIRST;
#elif PL02
	playergraphic = Texture(L"picture/player/pl1/player.png");
	slow = PL02_SPEED_SLOW;
	firsr = PL02_SPEED_FIRST;
#else PL03
	playergraphic = Texture(L"picture/player/pl2/player.png");
	slow = PL02_SPEED_SLOW;
	firsr = PL02_SPEED_FIRST;
#endif // PL01
	sloweff = Texture(L"picture/player/sloweff.png");
	shotse = Sound(L"sound/player/shot.wav");
	pshot_speed = PSHOT_SPEED;
	font = Font(12);
	shotcount = 9;
	for (int i=0; i < PSHOT_MAX; ++i) {
		shot_b_l[i] = false;
		shot_b_r[i] = false;
	}
}

void player::data() {//更新関数
	define_i UPDATACOUNT = 15;
	++plgr;
	if (UPDATACOUNT%plgr == 0) {
		++grnum;
	}

	if (Input::KeyLShift.pressed) {
		s = true;
	}
	else {
		s = false;
	}
	plspeed = s ? slow : firsr;//スピードの代入


	if (Input::KeyLeft.pressed || Input::KeyNum4.pressed) {
		if (Input::KeyUp.pressed || Input::KeyNum8.pressed) {
			u = true;
			d = false;
		}
		else if(Input::KeyDown.pressed || Input::KeyNum2.pressed) {
			d = true;
			u = false;
		}
		else {
			d = false;
			u = false;
		}
		l = true;
		r = false;
	}

	else if (Input::KeyRight.pressed || Input::KeyNum6.pressed) {
		if (Input::KeyUp.pressed || Input::KeyNum8.pressed) {
			u = true;
			d = false;
		}
		else if (Input::KeyDown.pressed || Input::KeyNum2.pressed) {
			d = true;
			u = false;
		}
		else {
			d = false;
			u = false;
		}
		r = true;;
		l = false;
	}

	else if(Input::KeyDown.pressed || Input::KeyNum2.pressed) {
		if (Input::KeyLeft.pressed || Input::KeyNum4.pressed) {
			l= true;
			r = false;
		}
		else if (Input::KeyRight.pressed || Input::KeyNum6.pressed) {
			r = true;
			l = false;
		}
		else {
			r = false;
			l = false;
		}
		d = true;
		u = false;
	}

	else if(Input::KeyUp.pressed || Input::KeyNum8.pressed) {
		if (Input::KeyLeft.pressed || Input::KeyNum4.pressed) {
			l = true;
			r = false;
		}
		else if (Input::KeyRight.pressed || Input::KeyNum6.pressed) {
			r = true;
			l = false;
		}
		else {
			r = false;
			l = false;
		}
		u = true;
		d = false;
	}
	
	else if (Input::KeyNum7.pressed) {
		u = true;
		l = true;
		r = false;
		d = false;
	}

	else if (Input::KeyNum9.pressed) {
		u = true;
		r = true;
		l = false;
		d = false;
	}

	else if (Input::KeyNum1.pressed) {
		d = true;
		l = true;
		r = false;
		u = false;
	}

	else if (Input::KeyNum3.pressed) {
		d= true;
		r = true;
		l= false;
		u = false;
	}

	else {
		d = false;
		r = false;
		l = false;
		u = false;
	}

	
	if (l) {
		p_position.x -= plspeed;
	}
	else if (r) {
		p_position.x += plspeed;
	}
	if (u) {
		p_position.y -= plspeed;
	}
	else if (d) {
		p_position.y += plspeed;
	}

	if (p_position.x < FIELD_MIN_X+16) {
		p_position.x = FIELD_MIN_X + 16;
	}
	if (p_position.x > FIELD_MAX_X - 16) {
		p_position.x = FIELD_MAX_X - 16;
	}
	if (p_position.y < FIELD_MIN_Y+ 16) {
		p_position.y = FIELD_MIN_Y + 16;
	}
	if (p_position.y > FIELD_MAX_Y - 16) {
		p_position.y = FIELD_MAX_Y - 16;
	}

	}
void player::shot() {
	
	bool debagz = false;

	if (Input::KeyZ.pressed || shotcount % 10 == 0) {

		for (int i = 0; i < PSHOT_MAX; ++i) {
			shotcount+=1;
			if (!shot_b_l[i]) {
				shot_b_l[i] = true;
				pshot_l[i].x = p_position.x + 16;
				pshot_l[i].y = p_position.y - 16;
			}
			if (!shot_b_r[i]) {
				shot_b_r[i] = true;
				pshot_r[i].x = p_position.x - 16;
				pshot_r[i].y = p_position.y - 16;
				debagz = true;
			}
		}
	}
	else {
		shotcount=9;
		
	}
	for (int i=0; i < PSHOT_MAX; ++i) {
		if (shot_b_l[i]) {
			pshot_l[i].y -= pshot_speed;
		}
		if (shot_b_r[i]) {
			pshot_r[i].y -= pshot_speed;
		}
	}


	//デバッグ
	/*for (int i = 0; i < PSHOT_MAX; ++i) {
		
		if (shot_b_l[i]) {
			color=Color{ 255,0,0 };
		}
		else {
			color=Color{ 255,255,255 };
		}
		font(L"■").draw(FIELD_MAX_X, i * 20, color);
	}*/
	font(L"count=", shotcount).draw({ 440,64 });
	if (!debagz) {
		font(L"z").draw({ 440,80 });
	}
}

void player::draw() {//描画関数
	playergraphic.drawAt(p_position);
	double rad;
	for (count c = 0; c < 36; ++c) {
		rad = Radians(c * 10 + System::FrameCount()*2);
	}
	if (s) {
		sloweff.rotate(rad).drawAt(p_position);
	}

	for (int i = 0; i < PSHOT_MAX; ++i) {
		pshot.draw(pshot_l[i].x, pshot_l[i].y);
		pshot.draw(pshot_r[i].x, pshot_r[i].y);
	}


}
void player::updata() {
	data();
	shot();
	draw();
}

player::~player(){

}
