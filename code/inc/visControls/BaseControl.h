#ifndef __BASECONTROL_H__
#define __BASECONTROL_H__

#include <functional>
#include <memory>
#include <vector>

namespace BDrive
{
	class ScreenLayer;

namespace VisualControls
{
	using ControlHandler = std::function<void(std::vector<std::shared_ptr<ScreenLayer>>&,
						std::vector<std::shared_ptr<ScreenLayer>>&)>;
	enum ControlType
	{
		BUTTON
	};

	/// Класс, представляющий базовый контрол
	/*!
	 * Этот класс необходимо использовать в
	 * качестве родительского класса для создания
	 * своих контролов.
	 * Контрол - элемент управления, отобращающийся
	 * на Canvas. Например, кнопка, текстовое поле,
	 * надпись и т.д.
	 */
	class BaseControl
	{
		protected:
			ControlType _type;
			uint16_t _x;
			uint16_t _y;
			uint16_t _width;
			uint16_t _height;

		public:
			~BaseControl() = default;
			BaseControl();
			explicit BaseControl(const BaseControl &control);
			BaseControl(BaseControl &control);

			/// \details Возвращает положение контрола по вертикали
			uint16_t getY() const;

			/// \details Возвращает положение контрола по горизонтали
			uint16_t getX() const;

			/// \details Возвращает ширину контрола
			uint16_t getWidth() const;

			/// \details Возвращает высоту контрола
			uint16_t getHeight() const;

			/// \details Возвращает тип контрола
			ControlType getType() const;

			/*! \details
			 * Задает тип контрола
			 * \param type Тип контрола
			 * \return Ссылку на себя
			 */
			BaseControl& setType(ControlType type);

			/*! \details
			 * Задает положение контрола по горизонтали
			 * Началом координат принимается верхний левый угол экрана
			 * \param x Положение контрола по горизонтали
			 * \return Ссылку на себя
			 */
			BaseControl& setX(uint16_t x);

			/*! \details
			 * Задает положение контрола по вертикали
			 * Началом координат принимается верхний левый угол экрана
			 * \param y Положение контрола по вертикали
			 * \return Ссылку на себя
			 */
			BaseControl& setY(uint16_t y);

			/*! \details
			 * Задает ширину конрола
			 * \param width Ширина контрола
			 * \return Ссылку на себя
			 */
			BaseControl& setWidth(uint16_t width);

			/*! \details
			 * Задает высоту контрола
			 * \param height Высота контрола
			 * \return Ссылку на себя
			 */
			BaseControl& setHeight(uint16_t height);

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
