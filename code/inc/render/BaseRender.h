#ifndef __BASERENDER_H__
#define __BASERENDER_H__

#include <memory>
#include "../visPrimitives/Canvas.h"
#include "../screenLayer/ScreenLayer.h"

namespace BDrive
{
namespace Render
{
	enum RenderType
	{
		BUTTONRENDER
	};

	/// Класс, представляющий базовый класс для создания своего рендера контролов
	class BaseRender
	{
		protected:
			RenderType _type;

		public:
			~BaseRender() = default;
			BaseRender() = default;
			explicit BaseRender(RenderType type);

			/*! \details
			 * Задает тип рендера
			 * \param type Тип рендера
			 * \return Ссылку на себя
			 */
			BaseRender& setType(RenderType type);

			/// \details Возвращает тип рендера
			RenderType getType() const;

			/*! \details
			 * Является виртуальным методом для отрисовки контрола.
			 * \param canvas Область на которую будет происходить отрисовка
			 * \param index Индекс контрола, который будет отрисован
			 * \param layer Слой, из которого будет взят контрол
			 */
			virtual void render(Canvas &canvas, uint32_t index, ScreenLayer &layer) = 0;

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
