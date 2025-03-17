#include "../../inc/events/MouseClickEvent.h"
#include <algorithm>

BDrive::Events::MouseClickEvent::MouseClickEvent() :
					BaseEvent(BaseEvent()
							.setType(EventType::MOUSECLICK))
{}

BDrive::Events::MouseClickEvent::MouseClickEvent(const MouseClickEvent &event) :
					BaseEvent(BaseEvent()
							.setType(EventType::MOUSECLICK)),
					_buttonNumber(event._buttonNumber)
{}

BDrive::Events::MouseClickEvent::MouseClickEvent(MouseClickEvent &&event) :
					BaseEvent(BaseEvent()
							.setType(EventType::MOUSECLICK)),
					_buttonNumber(event._buttonNumber)
{}

uint8_t BDrive::Events::MouseClickEvent::getButtonNumber() const
{
	return _buttonNumber;
}

uint16_t BDrive::Events::MouseClickEvent::getX() const
{
	return _x;
}

uint16_t BDrive::Events::MouseClickEvent::getY() const
{
	return _y;
}

BDrive::Events::MouseClickEvent&& BDrive::Events::MouseClickEvent::setButtonNumber(uint8_t buttonNumber)
{
	_buttonNumber = buttonNumber;
	return std::move(*this);
}

BDrive::Events::MouseClickEvent&& BDrive::Events::MouseClickEvent::setX(uint16_t x)
{
	_x = x;
	return std::move(*this);
}

BDrive::Events::MouseClickEvent&& BDrive::Events::MouseClickEvent::setY(uint16_t y)
{
	_y = y;
	return std::move(*this);
}

const BDrive::Events::MouseClickEvent& BDrive::Events::MouseClickEvent::operator =(const MouseClickEvent &event)
{
	_buttonNumber = event._buttonNumber;
	return *this;
}
