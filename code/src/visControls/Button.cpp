#include "../../inc/visControls/Button.h"

BDrive::VisualControls::Button::Button() :
				BaseControl(BaseControl()
						.setType(ControlType::BUTTON)
						.setX(0)
						.setY(0)
						.setWidth(0)
						.setHeight(0))
{}

BDrive::VisualControls::Button::Button(const Button &button) :
				BaseControl(BaseControl()
						.setType(ControlType::BUTTON)
						.setX(button._x)
						.setY(button._y)
						.setWidth(button._width)
						.setHeight(button._height)),
				_backgroundTransparent(button._backgroundTransparent),
				_backgroundColor(button._backgroundColor),
				_backgroundImage(button._backgroundImage)
{}

BDrive::VisualControls::Button::Button(Button &&button) :
				BaseControl(BaseControl()
						.setType(ControlType::BUTTON)
						.setX(button._x)
						.setY(button._y)
						.setWidth(button._width)
						.setHeight(button._height)),
				_backgroundTransparent(button._backgroundTransparent),
				_backgroundColor(button._backgroundColor),
				_backgroundImage(button._backgroundImage)
{}

bool BDrive::VisualControls::Button::hasBackgroundColor() const
{
	return _backgroundColor.has_value();
}

bool BDrive::VisualControls::Button::hasBackgroundImage() const
{
	return _backgroundImage.has_value();
}

const BDrive::Color& BDrive::VisualControls::Button::getBackgroundColor() const
{
	return _backgroundColor.value();
}

const BDrive::Image& BDrive::VisualControls::Button::getBackgroundImage() const
{
	return _backgroundImage.value();
}

uint8_t BDrive::VisualControls::Button::getBackgroundTransparent() const
{
	return _backgroundTransparent;
}

BDrive::VisualControls::Button& BDrive::VisualControls::Button::setBackgoundColor(const Color &color)
{
	_backgroundColor = color;
	return *this;
}

BDrive::VisualControls::Button& BDrive::VisualControls::Button::setBackgoundImage(const Image &image)
{
	_backgroundImage = image;
	return *this;
}

BDrive::VisualControls::Button& BDrive::VisualControls::Button::setBackgoundTransparent(uint8_t transparent)
{
	_backgroundTransparent = transparent;
	return *this;
}

BDrive::VisualControls::Button& BDrive::VisualControls::Button::setClickHandler(const ControlHandler &handler)
{
	_clickHandler = handler;
	return *this;
}

void BDrive::VisualControls::Button::click(std::vector<std::shared_ptr<ScreenLayer>> &layers,
					std::vector<std::shared_ptr<ScreenLayer>> &curLayers)
{
	_clickHandler(layers, curLayers);
}


const BDrive::VisualControls::Button& BDrive::VisualControls::Button::operator =(const Button &button)
{
	_x = button._x;
	_y = button._y;
	_width = button._width;
	_height = button._height;
	_backgroundTransparent = button._backgroundTransparent;
	_backgroundColor = button._backgroundColor;
	_backgroundImage = button._backgroundImage;
	return *this;
}
