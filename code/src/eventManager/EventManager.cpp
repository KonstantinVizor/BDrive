#include "../../inc/eventManager/EventManager.h"
#include "../../inc/facade/Container.h"
#include <vector>

BDrive::EventManager::EventManager(const EventManager &manager) :
					_handlerMap(manager._handlerMap),
					_container(manager._container)
{}

BDrive::EventManager::EventManager(EventManager &&manager) :
					_handlerMap(manager._handlerMap),
					_container(manager._container)
{}

BDrive::EventManager&& BDrive::EventManager::setContainer(const std::shared_ptr<Container> &container)
{
	_container = container;
	return std::move(*this);
}

BDrive::EventManager&& BDrive::EventManager::addHandler(Events::EventType type,
			const std::shared_ptr<EventHandler::BaseEventHandler> &handler)
{
	_handlerMap[type].push_back(handler);
	return std::move(*this);
}

void BDrive::EventManager::process()
{
	std::shared_ptr<Events::BaseEvent> event;
	std::vector<std::shared_ptr<EventHandler::BaseEventHandler>> handlers;
	while (_container->getRunning())
	{
		_container->getQueueMutex().lock();
		if (_container->getEventQueue().size() == 0)
		{
			_container->getQueueMutex().unlock();
			continue;
		}
		event = _container->getEventQueue().front();
		_container->getEventQueue().pop();
		_container->getQueueMutex().unlock();
		handlers = _handlerMap[event->getType()];
		for (uint16_t i = 0; i < (uint16_t)handlers.size(); i++)
			if (handlers[i]->isValid(event))
				handlers[i]->process(event, _container);
	}
}

const BDrive::EventManager& BDrive::EventManager::operator =(const EventManager &manager)
{
	_handlerMap = manager._handlerMap;
	_container = manager._container;
	return *this;
}
