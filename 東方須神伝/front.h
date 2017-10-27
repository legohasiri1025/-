#pragma once
#include <Siv3D.hpp>
#include "define.h"
class front{
private:
	Array<Texture> front_t, hiscore_t, score_t, player_t, bomb_t, graze_t, power_t, point_t, num_b_t, num_s_t;
	Array<Vec2> front_p, hiscore_p, score_p, player_p, bomb_p, graze_p, power_p, point_p, num_b_p, num_s_p;
public:
	front();

	~front();
};

