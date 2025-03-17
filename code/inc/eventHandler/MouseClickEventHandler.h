#ifndef __MOUSECLICKEVENTHANDLER_H__
#define __MOUSECLICKEVENTHANDLER_H__

#include "BaseEventHandler.h"

namespace BDrive
{
namespace EventHandler
{
	/// Класс, представляющий из себя базовый
	/// класс для событий нажатия кнопок мыши
	class MouseClickEventHandler : public BaseEventHandler
	{
		public:
			~MouseClickEventHandler() = default;
			MouseClickEventHandler() = default;

			/// \details Является переопределением метода BaseEventHandler::isValid
			virtual bool isValid(const std::shared_ptr<Events::BaseEvent> &event) override;
	};
}
}

#endif
