#ifndef __TICKEVENT_H__
#define __TICKEVENT_H__

#include "BaseEvent.h"
#include <cinttypes>

namespace BDrive
{
namespace Events
{
	/// Класс, представляющий событие тика таймера
	class TickEvent : public BaseEvent
	{
		public:
			~TickEvent() = default;
			explicit TickEvent(const TickEvent &) = default;
			TickEvent(TickEvent &&) = default;
			TickEvent();
			
			const TickEvent& operator =(const TickEvent &event);	
	};
}
}

#endif
