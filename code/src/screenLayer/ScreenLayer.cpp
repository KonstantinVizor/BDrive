#include "../../inc/screenLayer//ScreenLayer.h"

BDrive::ScreenLayer::ScreenLayer() :
				_controls(),
				_width(0),
				_height(0),
				_xpos(0),
				_ypos(0)
{}

BDrive::ScreenLayer::ScreenLayer(const ScreenLayer &layer) :
						_controls(layer._controls),
						_width(layer._width),
						_height(layer._height),
						_xpos(layer._xpos),
						_ypos(layer._ypos)
{}

BDrive::ScreenLayer::ScreenLayer(ScreenLayer &&layer) :
						_controls(layer._controls),
						_width(layer._width),
						_height(layer._height),
						_xpos(layer._xpos),
						_ypos(layer._ypos)
{}

BDrive::ScreenLayer& BDrive::ScreenLayer::addControl(const std::shared_ptr<VisualControls::BaseControl> &control)
{
	_controls.push_back(control);
	return *this;
}

BDrive::ScreenLayer& BDrive::ScreenLayer::removeControl(uint32_t index)
{
	_controls.erase(_controls.begin() + index);
	return *this;
}

const std::shared_ptr<BDrive::VisualControls::BaseControl>& BDrive::ScreenLayer::getControl(uint32_t index) const
{
	return _controls[index];
}

uint32_t BDrive::ScreenLayer::getControlsCount() const
{
	return _controls.size();
}

BDrive::ScreenLayer& BDrive::ScreenLayer::setWidth(uint16_t width)
{
	_width = width;
	return *this;
}

BDrive::ScreenLayer& BDrive::ScreenLayer::setHeight(uint16_t height)
{
	_height = height;
	return *this;
}

BDrive::ScreenLayer& BDrive::ScreenLayer::setXpos(uint16_t xpos)
{
	_xpos = xpos;
	return *this;
}

BDrive::ScreenLayer& BDrive::ScreenLayer::setYpos(uint16_t ypos)
{
	_ypos = ypos;
	return *this;
}

uint16_t BDrive::ScreenLayer::getWidth() const
{
	return _width;
}

uint16_t BDrive::ScreenLayer::getHeight() const
{
	return _height;
}

uint16_t BDrive::ScreenLayer::getXpos() const
{
	return _xpos;
}

uint16_t BDrive::ScreenLayer::getYpos() const
{
	return _ypos;
}

const BDrive::ScreenLayer& BDrive::ScreenLayer::operator =(const ScreenLayer &layer)
{
	_controls = layer._controls;
	_width = layer._width;
	_height = layer._height;
	_xpos = layer._xpos;
	_ypos = layer._ypos;
	return *this;
}
