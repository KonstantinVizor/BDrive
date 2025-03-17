#include "../../inc/renderManager/RenderManager.h"
#include "../../inc/facade/Container.h"

BDrive::RenderManager::RenderManager(const RenderManager &manager) :
						_container(manager._container),
						_renderMap(manager._renderMap)
{}

BDrive::RenderManager::RenderManager(RenderManager &&manager) :
						_container(manager._container),
						_renderMap(manager._renderMap)
{}

BDrive::RenderManager&& BDrive::RenderManager::setContainer(const std::shared_ptr<Container> &container)
{
	_container = container;
	return std::move(*this);
}

BDrive::RenderManager&& BDrive::RenderManager::addRender(VisualControls::ControlType type,
			const std::shared_ptr<Render::BaseRender> &render)
{
	_renderMap[type] = render;
	return std::move(*this);
}

void BDrive::RenderManager::render()
{
	std::shared_ptr<VisualControls::BaseControl> control;
	for (uint16_t i = 0; i < (uint16_t)_container->getLayers().size(); i++)
		if (_container->getLayers()[i].isShowed())
			for (uint16_t j = 0; j < _container->getLayers()[i].getControlsCount(); j++)
			{
				control = _container->getLayers()[i].getControl(j);
				_renderMap[control->getType()]->render(_container->getCanvas(), j, _container->getLayers()[i]);
			}
}

const BDrive::RenderManager& BDrive::RenderManager::operator =(const RenderManager &manager)
{
	_container = manager._container;
	_renderMap = manager._renderMap;
	return *this;
}
