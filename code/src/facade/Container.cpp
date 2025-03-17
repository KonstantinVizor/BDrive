#include "../../inc/facade/Container.h"
#include <memory>

BDrive::Container::Container(const Container &container) :
					_running(container._running),
					_canvas(container._canvas),
					_layers(container._layers),
					_eventQueue(container._eventQueue),
					_eventManager(container._eventManager),
					_renderManager(container._renderManager)
{}

BDrive::Container::Container(Container &&container) :
					_running(container._running),
					_canvas(container._canvas),
					_layers(container._layers),
					_eventQueue(container._eventQueue),
					_eventManager(container._eventManager),
					_renderManager(container._renderManager)
{}

bool& BDrive::Container::getRunning()
{
	return _running;
}

BDrive::Canvas& BDrive::Container::getCanvas()
{
	return _canvas;
}

std::vector<BDrive::ScreenLayer>& BDrive::Container::getLayers()
{
	return _layers;
}

std::mutex& BDrive::Container::getQueueMutex()
{
	return _queueMutex;
}

std::queue<std::shared_ptr<BDrive::Events::BaseEvent>>& BDrive::Container::getEventQueue()
{
	return _eventQueue;
}

BDrive::EventManager& BDrive::Container::getEventManager()
{
	return _eventManager;
}

BDrive::RenderManager& BDrive::Container::getRenderManager()
{
	return _renderManager;
}

BDrive::Container& BDrive::Container::addEvent(const std::shared_ptr<Events::BaseEvent> &event)
{
	_eventQueue.push(event);
	return *this;
}

BDrive::Container& BDrive::Container::addLayer(const ScreenLayer &layer)
{
	_layers.push_back(layer);
	return *this;
}

BDrive::Container& BDrive::Container::addHandler(Events::EventType type,
			const std::shared_ptr<EventHandler::BaseEventHandler> &handler)
{
	_eventManager.addHandler(type, handler);
	return *this;
}

BDrive::Container& BDrive::Container::addRender(VisualControls::ControlType type,
			const std::shared_ptr<Render::BaseRender> &render)
{
	_renderManager.addRender(type, render);
	return *this;
}

BDrive::Container& BDrive::Container::setContainer(const std::shared_ptr<Container> &container)
{
	_renderManager.setContainer(container);
	_eventManager.setContainer(container);
	return *this;
}

const BDrive::Container& BDrive::Container::operator =(const Container &container)
{
	_running = container._running;
	_canvas = container._canvas;
	_layers = container._layers;
	_eventQueue = container._eventQueue;
	_eventManager = container._eventManager;
	_renderManager = container._renderManager;
	return *this;
}
