#ifndef __BASEEVENTHANDLER_H__
#define __BASEEVENTHANDLER_H__

#include "../visControls/BaseControl.h"
#include "../events/BaseEvent.h"
#include <memory>

namespace BDrive
{
	class Container;
namespace EventHandler
{
	/// Класс, представляющий из себя базовый класс для обработчиков событий
	/*!
	 * От данного класса необходимо наследоваться
	 * для создания своих обработчиков событий.
	 * Для каждого созданного контрола создается свой обработчик
	 */
	class BaseEventHandler
	{
		protected:
			std::shared_ptr<VisualControls::BaseControl> _control;

		public:
			~BaseEventHandler() = default;
			BaseEventHandler() = default;

			/// \details Возвращает контрол
			const std::shared_ptr<VisualControls::BaseControl> getControl() const;

			/*! \details
			 * Данный метод устанавливает контрол.
			 * \param control Указатель на контрол
			 * \return Ссылку на себя
			 */
			BaseEventHandler&& setControl(const std::shared_ptr<VisualControls::BaseControl> &control);

			/*! \details
			 * Данный метод проверяет, подходит ли
			 * событие для выполнения данным обработчиком
			 * \param event Событие
			 * \return true, если обработчик может бытб запущен. false иначе
			 */
			virtual bool isValid(const std::shared_ptr<Events::BaseEvent> &event) = 0;

			/*! \details
			 * Данный метод необходим для выполнения
			 * обработки
			 * \param event Событие
			 * \param facade Указатель на фасад
			 */
			virtual void process(const std::shared_ptr<Events::BaseEvent> &event,
						const std::shared_ptr<Container> &facade) = 0;
	};
}
}

#endif
