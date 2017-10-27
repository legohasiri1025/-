# include <Siv3D.hpp>
#include "player.h"
#define PL01

void Main()
{
	player test;
	while (System::Update())
	{
		test.updata();
	}
}
