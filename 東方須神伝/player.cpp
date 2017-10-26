#include "player.h"



player::player():m_position(0,0)
{
}

void player::updata() {
	define_i UPDATACOUNT = 15;
	if (UPDATACOUNT%plgr == 0) {
		++grnum;
	}
	++plgr;
}

void player::draw() {
		player_graphic[grnum].draw(m_position.x,m_position.y);
}

player::~player()
{
}
