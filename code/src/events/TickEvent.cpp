#include "../../inc/events/TickEvent.h"

BDrive::Events::TickEvent::TickEvent() :
				BaseEvent(BaseEvent()
						.setType(EventType::TICK))
{}

const BDrive::Events::TickEvent& BDrive::Events::TickEvent::operator =([[maybe_unused]]const TickEvent &event)
{
	return *this;
}
