#ifndef __MOUSECLICKEVENT_H__
#define __MOUSECLICKEVENT_H__

#include "BaseEvent.h"
#include <cinttypes>

namespace BDrive
{
namespace Events
{
	/// Класс, представляющий событие нашатия кнопки мыши
	/*!
	 * Тип кнопки определяется номером
	 * - 0 (ЛКМ)
	 * - 1 (ПКМ)
	 */
	class MouseClickEvent : public BaseEvent
	{
		private:
			uint8_t _buttonNumber;
			uint16_t _x;
			uint16_t _y;
			
		public:
			~MouseClickEvent() = default;
			MouseClickEvent();
			explicit MouseClickEvent(const MouseClickEvent &event);
			MouseClickEvent(MouseClickEvent &&event);

			/// \details Возвращает номер нажатой кнопки
			uint8_t getButtonNumber() const;

			/// \details Возвращает положение курсора по X
			uint16_t getX() const;

			/// \details Возвращает положение курсора по Y
			uint16_t getY() const;

			/*! \details
			 * Устанавливает номер кнопки
			 * \param buttonNumber Номер кнопки
			 * \return Ссылку на себя
			 */
			MouseClickEvent&& setButtonNumber(uint8_t buttonNumber);

			/*! \details
			 * Устанавливает положение курсора по X
			 * \param x Положение курсора
			 * \return Ссылку на себя
			 */
			MouseClickEvent&& setX(uint16_t x);

			/*!
			 * Устанавливает положение курсора по Y
			 * \param x Положение курсора
			 * \return Ссылку на себя
			 */
			MouseClickEvent&& setY(uint16_t y);

			const MouseClickEvent& operator =(const MouseClickEvent &event);
	};
}
}

#endif
