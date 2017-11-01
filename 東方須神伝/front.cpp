#include "front.h"



front::front()
{
	front_t = Texture(L"picture/front/front_front.png");
	front_p.x = 0, front_p.y = 0;
}

void front::data() {

}

void front::draw() {
	front_t.draw(front_p.x, front_p.y);
}

void front::updata() {
	data();
	draw();
}

front::~front()
{
}
