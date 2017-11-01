#pragma once
#include<Siv3D.hpp>

using define_i = const int;
using define_d = const double;
using define_f = const float;
using graphic = const Texture;
using point = Point;
using count = int;
using speed = int32;

define_i FIELD_MAX_X = 415;
define_i FIELD_MAX_Y = 464;
define_i FIELD_MIN_X = 32;
define_i FIELD_MIN_Y = 16;

define_i FIELD_CENTER_X = (415 + 32) / 2;
define_i FIELD_CENTER_Y = (464 + 16) / 2;

define_i PSHOT_MAX = 20;
define_i PSHOT_SPEED = 16;