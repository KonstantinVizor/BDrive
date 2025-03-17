#ifndef __KEYPRESSEVENTHANDLER_H__
#define __KEYPRESSEVENTHANDLER_H__

#include "BaseEventHandler.h"

namespace BDrive
{
namespace EventHandler
{
	/// Класс, представляющий из себя базовый
	/// класс для событий нажатия клавиши
	class KeyPressEventHandler : public BaseEventHandler
	{
		public:
			~KeyPressEventHandler() = default;
			KeyPressEventHandler() = default;

			/// \details Является переопределением метода BaseEventHandler::isValid
			virtual bool isValid(const std::shared_ptr<Events::BaseEvent> &event) override;
	};
}
}

#endif
