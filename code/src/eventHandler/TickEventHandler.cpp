#include "../../inc/eventHandler/TickEventHandler.h"

bool BDrive::EventHandler::TickEventHandler::isValid([[maybe_unused]]const std::shared_ptr<Events::BaseEvent> &event)
{
	return true;
}
