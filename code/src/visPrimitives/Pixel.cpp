#include "../../inc/visPrimitives/Pixel.h"

BDrive::Pixel::Pixel(const Pixel &pixel) :
				_color(pixel._color),
				_x(pixel._x),
				_y(pixel._y)
{}

BDrive::Pixel::Pixel(Pixel &&pixel) :
				_color(pixel._color),
				_x(pixel._x),
				_y(pixel._y)
{}

BDrive::Pixel& BDrive::Pixel::setColor(const Color &color)
{
	_color = color;
	return *this;
}

BDrive::Pixel& BDrive::Pixel::setX(uint16_t x)
{
	_x = x;
	return *this;
}

BDrive::Pixel& BDrive::Pixel::setY(uint16_t y)
{
	_y = y;
	return *this;
}

const BDrive::Color& BDrive::Pixel::getColor() const
{
	return _color;
}

uint16_t BDrive::Pixel::getX() const
{
	return _x;
}

uint16_t BDrive::Pixel::getY() const
{
	return _y;
}

const BDrive::Pixel& BDrive::Pixel::operator =(const Pixel &pixel)
{
	_color = pixel._color;
	_x = pixel._x;
	_y = pixel._y;
	return *this;
}
