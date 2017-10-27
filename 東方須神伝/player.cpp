#include "define.h"
#include "playerdata.h"
#include "player.h"
#define PL01

player::player():p_position(228, 405)
{
	/*p_position = defaultpoint;
	player_graphic(L"../picture/pl0/player.png");
	playergraphic = pl;*/
#ifdef PL01
	playergraphic = Texture(L"picture/player/pl0/player.png");
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
}

void player::draw() {//描画関数
	playergraphic.drawAt(p_position);
	count c=0;
	++c;
	if (s) {
		sloweff.rotate(c).drawAt(p_position);
	}
}
void player::updata() {
	data();
	draw();
}

player::~player(){

}
