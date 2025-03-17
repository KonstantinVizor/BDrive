#ifndef __TICKEVENTHANDLER_H__
#define __TICKEVENTHANDLER_H__

#include "BaseEventHandler.h"

namespace BDrive
{
namespace EventHandler
{
	/// Класс, представляющий из себя базовый
	/// класс для событий тика таймера
	class TickEventHandler : public BaseEventHandler
	{
		public:
			~TickEventHandler() = default;
			TickEventHandler() = default;

			/// \details Является переопределением метода BaseEventHandler::isValid
			virtual bool isValid(const std::shared_ptr<Events::BaseEvent> &event) override;
	};
}
}

#endif
