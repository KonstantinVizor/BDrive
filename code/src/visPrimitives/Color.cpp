#include "../../inc/visPrimitives/Color.h"

BDrive::Color::Color() :
		_r(0),
		_g(0),
		_b(0),
		_alpha(255)
{}

BDrive::Color::Color(const Color &color) :
			_r(color._r),
			_g(color._g),
			_b(color._b),
			_alpha(color._alpha)
{}

BDrive::Color::Color(Color &&color) :
			_r(color._r),
			_g(color._g),
			_b(color._b),
			_alpha(color._alpha)
{}

BDrive::Color& BDrive::Color::setR(uint8_t r)
{
	_r = r;
	return *this;
}

BDrive::Color& BDrive::Color::setG(uint8_t g)
{
	_g = g;
	return *this;
}

BDrive::Color& BDrive::Color::setB(uint8_t b)
{
	_b = b;
	return *this;
}

BDrive::Color& BDrive::Color::setAlpha(uint8_t alpha)
{
	_alpha = alpha;
	return *this;
}

uint8_t BDrive::Color::getR() const
{
	return _r;
}

uint8_t BDrive::Color::getG() const
{
	return _g;
}

uint8_t BDrive::Color::getB() const
{
	return _b;
}

uint8_t BDrive::Color::getAlpha() const
{
	return _alpha;
}

BDrive::Color BDrive::Color::operator +(const Color &color) const
{
	Color result;
	result._r = _r + color._r;
	result._g = _g + color._g;
	result._b = _b + color._b;
	result._alpha = _alpha > color._alpha ? _alpha : color._alpha;
	return result;
}

BDrive::Color BDrive::Color::operator *(double number) const
{
	Color result;
	result._r = _r * number;
	result._g = _g * number;
	result._b = _b * number;
	result._alpha = _alpha;
	return result;
}

const BDrive::Color& BDrive::Color::operator =(const Color &color)
{
	_r = color._r;
	_g = color._g;
	_b = color._b;
	_alpha = color._alpha;
	return *this;
}
