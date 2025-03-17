#ifndef __BASEEVENT_H__
#define __BASEEVENT_H__

namespace BDrive
{
namespace Events
{
	enum EventType
	{
		MOUSECLICK,
       		KEYPRESS,
		TICK
	};

	/// Класс, представляющий базовое событие
	/*!
	 * Этот класс необходимо использовать в
	 * качестве родительского класса для создания
	 * своих событий.
	 */
	class BaseEvent
	{
		protected:
			EventType _type;

		public:
			~BaseEvent() = default;
			BaseEvent() = default;
			explicit BaseEvent(const BaseEvent &event);
			BaseEvent(BaseEvent &&event);

			/// \details Возвращает тип события
			EventType getType() const;

			/*! \details
			 * Задает тип контрола
			 * \param type Тип контрола
			 * \return Ссылку на себя
			 */
			BaseEvent&& setType(EventType type);

			/*! \details
			 * Приводит объект к дочернему типу
			 * Используется для приведения объекта
			 * типа BaseControl к дочернему типу.
			 * Необходимо соблюдать два условия:
			 * - Тип Type обязательно должен быть дочерним;
			 * - Объект, означально должен быть создан как объект
			 *   типа Type, или типа дочернего к Type.
			 *
			 * \result Ссылку на себя типа Type
			 */
			template<typename Type>
			Type& cast()
			{
				return *((Type *)this);
			}	
	};
}
}

#endif
