# include <Siv3D.hpp>

void Main()
{
	const int defaultx = 320;
	const int defaulty = 240;
	int x = defaultx;
	int y = defaulty;
	while (System::Update())
	{
		if (Input::KeyRight.pressed) {
			x++;
		}
		else if (Input::KeyLeft.pressed) {
			x--;
		}
		if (Input::KeyUp.pressed) {
			y--;
		}
		else if (Input::KeyDown.pressed) {
			y++;
		}
		if (Input::KeyR.pressed) {
			x = defaultx;
			y = defaulty;
		}
		Circle(x, y, 150).draw();
	}
}
