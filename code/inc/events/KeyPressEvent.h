#ifndef __KEYPRESSEVENT_H__
#define __KEYPRESSEVENT_H__

#include "BaseEvent.h"
#include <cinttypes>

namespace BDrive
{
namespace Events
{
	/// Класс, представляющий событие нашатия клавиши на клавиатуре
	class KeyPressEvent : public BaseEvent
	{
		private:
			uint8_t _key;

		public:
			~KeyPressEvent() = default;
			KeyPressEvent();
			explicit KeyPressEvent(const KeyPressEvent &event);
			KeyPressEvent(KeyPressEvent &&event);

			/// \details Возвращает символ нажатой кнопки
			uint8_t getKey() const;

			/*! \details
			 * Устанавливает символ нажатой кнопки
			 * \param key Символ
			 * \result Ссылку на себя
			 */
			KeyPressEvent&& setKey(uint8_t key);
	
			const KeyPressEvent& operator =(const KeyPressEvent &event);
	};
}
}

#endif
