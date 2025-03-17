#include "../../inc/events/KeyPressEvent.h"
#include <algorithm>

BDrive::Events::KeyPressEvent::KeyPressEvent() :
					BaseEvent(BaseEvent()
							.setType(EventType::KEYPRESS))
{}

BDrive::Events::KeyPressEvent::KeyPressEvent(const KeyPressEvent &event) :
					BaseEvent(BaseEvent()
							.setType(EventType::KEYPRESS)),
					_key(event._key)
{}

BDrive::Events::KeyPressEvent::KeyPressEvent(KeyPressEvent &&event) :
					BaseEvent(BaseEvent()
							.setType(EventType::KEYPRESS)),
					_key(event._key)
{}

uint8_t BDrive::Events::KeyPressEvent::getKey() const
{
	return _key;
}

BDrive::Events::KeyPressEvent&& BDrive::Events::KeyPressEvent::setKey(uint8_t key)
{
	_key = key;
	return std::move(*this);
}

const BDrive::Events::KeyPressEvent& BDrive::Events::KeyPressEvent::operator =(const KeyPressEvent &event)
{
	_key = event._key;
	return *this;
}
