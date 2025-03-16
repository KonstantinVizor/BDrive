#include "../../inc/visControls/BaseControl.h"

BDrive::VisualControls::BaseControl::BaseControl() :
				_x(0),
				_y(0),
				_width(0),
				_height(0)
{}

BDrive::VisualControls::BaseControl::BaseControl(const BaseControl &control) :
						_type(control._type),
						_x(control._x),
						_y(control._y),
						_width(control._width),
						_height(control._height)
{}

BDrive::VisualControls::BaseControl::BaseControl(BaseControl &control) :
						_type(control._type),
						_x(control._x),
						_y(control._y),
						_width(control._width),
						_height(control._height)
{}

uint16_t BDrive::VisualControls::BaseControl::getX() const
{
	return _x;
}

uint16_t BDrive::VisualControls::BaseControl::getY() const
{
	return _y;
}

uint16_t BDrive::VisualControls::BaseControl::getWidth() const
{
	return _width;
}

uint16_t BDrive::VisualControls::BaseControl::getHeight() const
{
	return _height;
}

BDrive::VisualControls::ControlType BDrive::VisualControls::BaseControl::getType() const
{
	return _type;
}

BDrive::VisualControls::BaseControl& BDrive::VisualControls::BaseControl::setType(ControlType type)
{
	_type = type;
	return *this;
}

BDrive::VisualControls::BaseControl& BDrive::VisualControls::BaseControl::setX(uint16_t x)
{
	_x = x;
	return *this;
}

BDrive::VisualControls::BaseControl& BDrive::VisualControls::BaseControl::setY(uint16_t y)
{
	_y = y;
	return *this;
}


BDrive::VisualControls::BaseControl& BDrive::VisualControls::BaseControl::setWidth(uint16_t width)
{
	_width = width;
	return *this;
}

BDrive::VisualControls::BaseControl& BDrive::VisualControls::BaseControl::setHeight(uint16_t height)
{
	_height = height;
	return *this;
}
