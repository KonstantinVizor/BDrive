#include "../../inc/visPrimitives/Canvas.h"
#include <memory>

BDrive::Canvas::Canvas(const Canvas &canvas) :
				_table(canvas._table)
{}

BDrive::Canvas::Canvas(Canvas &&canvas) :
				_table(canvas._table)
{}

BDrive::Canvas::Canvas(uint16_t height, uint16_t width) :
				_table(std::vector<std::vector<Color>>(height))
{
	for (int i = 0; i < height; i++)
		_table[i] = std::vector<Color>(width);
}

BDrive::Canvas& BDrive::Canvas::setPixel(uint16_t x, uint16_t y, const Color &color)
{
	_table[x][y] = color;
	return *this;
}

uint16_t BDrive::Canvas::getHeight() const
{
	return _table.size();
}

uint16_t BDrive::Canvas::getWidth() const
{
	if (_table.size() == 0)
		return 0;
	return _table[0].size();
}

const BDrive::Color& BDrive::Canvas::getPixel(uint16_t x, uint16_t y) const
{
	return _table[x][y];
}

const BDrive::Canvas& BDrive::Canvas::operator =(const Canvas &canvas)
{
	_table = canvas._table;
	return *this;
}
