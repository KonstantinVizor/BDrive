#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include "../events/BaseEvent.h"
#include "../eventHandler/BaseEventHandler.h"
#include <map>
#include <memory>
#include <vector>

namespace BDrive
{
	/// Класс, представляющий из себя менеджер событий
	/*! Данный класс обработывает все события, пришедшие
	 * из окна
	 */
	class EventManager
	{
		private:
			std::map<Events::EventType, std::vector<std::shared_ptr<EventHandler::BaseEventHandler>>> _handlerMap;
			std::shared_ptr<Container> _container;

		public:
			~EventManager() = default;
			EventManager() = default;
			explicit EventManager(const EventManager &manager);
			EventManager(EventManager &&manager);
			
			/*! \details
			 * Устанавливает контейнер
			 * \rapam container контейнер
			 * \return Ссылку на себя
			 */
			EventManager&& setContainer(const std::shared_ptr<Container> &container);

			/*! \details
			 * Добавляет новый обработчик события
			 * \rapam type Тип события
			 * \rapam handler Обработчик события
			 * \return Ссылку на себя
			 */
			EventManager&& addHandler(Events::EventType type,
						const std::shared_ptr<EventHandler::BaseEventHandler> &handler);

			/*! \details
			 * Данный метод обрабатывает все события,
			 * пришедшие из окна. Его необходимо запускать
			 * в отдельном потоке
			 */
			void process();

			const EventManager& operator =(const EventManager &manager);
	};
}

#endif
