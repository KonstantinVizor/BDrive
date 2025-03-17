#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "../screenLayer/ScreenLayer.h"
#include "../visPrimitives/Canvas.h"
#include "../events/BaseEvent.h"
#include "../eventManager/EventManager.h"
#include "../renderManager/RenderManager.h"
#include <mutex>
#include <queue>
#include <vector>

namespace BDrive
{
	/// Класс, предствляющий из себя хранилище всех очновных структур
	class Container
	{
		private:
			bool _running;
			Canvas _canvas;
			std::vector<ScreenLayer> _layers;
			std::mutex _queueMutex;
			std::queue<std::shared_ptr<Events::BaseEvent>> _eventQueue;
			EventManager _eventManager;
			RenderManager _renderManager;

		public:
			~Container() = default;
			Container() = default;
			explicit Container(const Container &container);
			Container(Container &&container);

			/// \details Возвращает флаг работы программы
			bool& getRunning();

			/// \details Возвращает холст
			Canvas& getCanvas();

			/// \details Возвращает массив слоев
			std::vector<ScreenLayer>& getLayers();

			/// \details Возвращает мьютекс
			std::mutex& getQueueMutex();

			/// \details Возвращает очередь событий
			std::queue<std::shared_ptr<Events::BaseEvent>>& getEventQueue();

			/// \details Возвращает менеджер событий
			EventManager& getEventManager();

			/// \details Возвращает менеджер отрисовки
			RenderManager& getRenderManager();

			/*! \details
			 * Добавляет в очередь событие
			 * \param event Событие
			 * \return Ссылку на себя
			 */
			Container& addEvent(const std::shared_ptr<Events::BaseEvent> &event);

			/*! \details
			 * Добавляет в массив слой
			 * \param layer Слой 
			 * \return Ссылку на себя
			 */
			Container& addLayer(const ScreenLayer &layer);

			/*! \details
			 * Добавляет новый обработчик события
			 * \param type Тип события
			 * \param handler Обработчик события
			 * \return Ссылку на себя
			 */
			Container& addHandler(Events::EventType type,
						const std::shared_ptr<EventHandler::BaseEventHandler> &handler);

			/*! \details
			 * Добавляет новый рендер
			 * \param type Типа контрола
			 * \param render Рендер
			 * \return Ссылку на себя
			 */
			Container& addRender(VisualControls::ControlType type,
						const std::shared_ptr<Render::BaseRender> &render);

			/*! \details
			 * Устанавливает указатель на себя
			 * \param container Указатель на себя
			 * \return Ссылку на себя
			 */
			Container& setContainer(const std::shared_ptr<Container> &container);

			const Container& operator =(const Container &container);
	};
}

#endif
