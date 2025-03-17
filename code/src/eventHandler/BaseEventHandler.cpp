#include "../../inc/eventHandler/BaseEventHandler.h"

const std::shared_ptr<BDrive::VisualControls::BaseControl> BDrive::EventHandler::BaseEventHandler::getControl() const
{
	return _control;
}

BDrive::EventHandler::BaseEventHandler&& BDrive::EventHandler::BaseEventHandler::setControl(const std::shared_ptr<VisualControls::BaseControl> &control)
{
	_control = control;
	return std::move(*this);
}
