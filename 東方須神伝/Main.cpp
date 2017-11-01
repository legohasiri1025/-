# include <Siv3D.hpp>
#include "player.h"
#include "front.h"
#define PL01

void Main()
{
	player test;
	front test_f;
	while (System::Update())
	{
		
		test_f.updata();
		test.updata();
	}
}
