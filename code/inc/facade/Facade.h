#ifndef __FACADE_H__
#define __FACADE_H__

#include "Container.h"
#include <memory>

namespace BDrive
{
	/// Класс, представляющий фасад для библиотеки BDrive
	class Facade
	{
		private:
			std::shared_ptr<Container> _container;
		
		public:
			~Facade() = default;
			Facade();
			explicit Facade(const Facade &facade);
			Facade(Facade &&facade);

			/*! \details
			 * Добавляет в массив слой
			 * \rapam layer Слой 
			 * \return Ссылку на себя
			 */
			Facade& addLayer(const ScreenLayer &layer);

			/*! \details
			 * Добавляет новый обработчик события
			 * \rapam type Тип события
			 * \rapam handler Обработчик события
			 * \return Ссылку на себя
			 */
			Facade& addHandler(Events::EventType type,
						const std::shared_ptr<EventHandler::BaseEventHandler> &handler);

			/*! \details
			 * Добавляет новый рендер
			 * \rapam type Типа контрола
			 * \rapam render Рендер
			 * \return Ссылку на себя
			 */
			Facade& addRender(VisualControls::ControlType type,
						const std::shared_ptr<Render::BaseRender> &render);

			/// \details Запускает выполнение программы
			void process();

			const Facade& operator =(const Facade &facade);
	};
}

#endif
