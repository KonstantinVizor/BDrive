#include "../../inc/eventHandler/MouseClickEventHandler.h"
#include "../../inc/visControls/Button.h"
#include "../../inc/events/MouseClickEvent.h"

bool BDrive::EventHandler::MouseClickEventHandler::isValid(const std::shared_ptr<Events::BaseEvent> &event)
{
	VisualControls::Button button(_control->cast<VisualControls::Button>());
	Events::MouseClickEvent mevent(event->cast<Events::MouseClickEvent>());
	bool result = mevent.getX() > button.getX() &&
			mevent.getY() > button.getY() &&
			mevent.getX() < (button.getX() + button.getWidth()) &&
			mevent.getY() < (button.getY() + button.getHeight());
	return result;
}
