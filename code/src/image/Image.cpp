#include "../../inc/image/Image.h"

BDrive::Image::Image(const Image &image) :
				_table(image._table),
				_width(image._width),
				_height(image._height)
{}

BDrive::Image::Image(Image &&image) :
				_table(image._table),
				_width(image._width),
				_height(image._height)
{}

BDrive::Image::Image(uint16_t height, uint16_t width) :
					_table(std::vector<std::vector<Color>>(height)),
					_width(width),
					_height(height)
{
	for (uint16_t i = 0; i < height; i++)
		_table[i] = std::vector<Color>(width);
}

const BDrive::Color& BDrive::Image::getPixel(uint16_t y, uint16_t x) const
{
	return _table[y][x];
}

const BDrive::Color& BDrive::Image::getPixel(double u, double v) const
{
	return _table[_height * u][_width *v];
}

uint16_t BDrive::Image::getWidth() const
{
	return _width;
}

uint16_t BDrive::Image::getHeight() const
{
	return _height;
}

BDrive::Image& BDrive::Image::setPixel(uint16_t x, uint16_t y, const Color &color)
{
	_table[x][y] = color;
	return *this;
}

BDrive::Image& BDrive::Image::setPixel(double u, double v, const Color &color)
{
	_table[_height * u][_width * v] = color;
	return *this;
}

const BDrive::Image& BDrive::Image::operator =(const Image &image)
{
	_table = image._table;
	_width = image._width;
	_height = image._height;
	return *this;
}
