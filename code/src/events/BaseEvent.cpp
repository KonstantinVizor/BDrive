#include "../../inc/events/BaseEvent.h"
#include <algorithm>

BDrive::Events::BaseEvent::BaseEvent(const BaseEvent &event) :
						_type(event._type)
{}

BDrive::Events::BaseEvent::BaseEvent(BaseEvent &&event) :
						_type(event._type)
{}

BDrive::Events::EventType BDrive::Events::BaseEvent::getType() const
{
	return _type;
}

BDrive::Events::BaseEvent&& BDrive::Events::BaseEvent::setType(EventType type)
{
	_type = type;
	return std::move(*this);
}
