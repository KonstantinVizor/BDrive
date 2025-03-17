#ifndef __RENDERMANAGER_H__
#define __RENDERMANAGER_H__

#include "../render/BaseRender.h"
#include "../visControls/BaseControl.h"
#include <memory>
#include <map>

namespace BDrive
{
	class Container;
	/// Класс, представляющий из себя менеджер отрисовки контролов
	class RenderManager
	{
		private:
			std::shared_ptr<Container> _container;
			std::map<VisualControls::ControlType, std::shared_ptr<Render::BaseRender>> _renderMap;

		public:
			~RenderManager() = default;
			RenderManager() = default;
			explicit RenderManager(const RenderManager &manager);
			RenderManager(RenderManager &&manager);

			/*! \details
			 * Устанавливает контейнер
			 * \rapam container контейнер
			 * \return Ссылку на себя
			 */
			RenderManager&& setContainer(const std::shared_ptr<Container> &container);

			/*! \details
			 * Добавляет новый рендер
			 * \rapam type Типа контрола
			 * \rapam render Рендер
			 * \return Ссылку на себя
			 */
			RenderManager&& addRender(VisualControls::ControlType type,
						const std::shared_ptr<Render::BaseRender> &render);

			/*! \details
			 * Производит отрисовку всех контролов
			 */
			void render();
		
			const RenderManager& operator =(const RenderManager &manager);
	};
}

#endif
