#include "../../inc/facade/Facade.h"
#include <memory>

BDrive::Facade::Facade()
{
	_container = std::make_shared<Container>();
	_container->setContainer(_container);
}

BDrive::Facade::Facade(const Facade &facade) :
				_container(facade._container)
{}

BDrive::Facade::Facade(Facade &&facade) :
				_container(facade._container)
{}

BDrive::Facade& BDrive::Facade::addLayer(const ScreenLayer &layer)
{
	_container->addLayer(layer);
	return *this;
}

BDrive::Facade& BDrive::Facade::addHandler(Events::EventType type,
			const std::shared_ptr<EventHandler::BaseEventHandler> &handler)
{
	_container->addHandler(type, handler);
	return *this;
}

BDrive::Facade& BDrive::Facade::addRender(VisualControls::ControlType type,
			const std::shared_ptr<Render::BaseRender> &render)
{
	_container->addRender(type, render);
	return *this;
}

void BDrive::Facade::process()
{}

const BDrive::Facade& BDrive::Facade::operator =(const Facade &facade)
{
	_container = facade._container;
	return *this;
}
