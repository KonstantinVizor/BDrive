#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "BaseControl.h"
#include "../visPrimitives/Color.h"
#include "../image/Image.h"
#include <optional>

namespace BDrive
{
namespace VisualControls
{
	/// Класс, представляющий кнопку
	class Button : public BaseControl
	{
		private:
			uint8_t _backgroundTransparent;
			std::optional<Color> _backgroundColor;
			std::optional<Image> _backgroundImage;

		public:
			~Button() = default;

			Button();
			explicit Button(const Button &button);
			Button(Button &&button);

			/*! \details
			 * Возвращает true, если установлен
			 * цвет фона, false иначе.
			 */
			bool hasBackgroundColor() const;

			/*! \details
			 * Возвращает true, если установлено
			 * фоновое изображение, false иначе.
			 */
			bool hasBackgroundImage() const;

			/// \details Возвращает цвет фона кнопки
			const Color& getBackgroundColor() const;

			/// \details Возвращает фоновое изображение
			const Image& getBackgroundImage() const;

			/// \details Возвращает прозрачность фона кнопки (от 0 до 255)
			uint8_t getBackgroundTransparent() const;

			/*! \details
			 * Задает цвет фона кнопки
			 * \param color Цвет фона
			 * \result Ссылку на себя
			 */
			Button& setBackgoundColor(const Color &color);

			/*! \details
			 * Задает фоновое изображение кнопки
			 * \param image Фоновое изображение
			 * \result Ссылку на себя
			 */
			Button& setBackgoundImage(const Image &image);

			/*! \details
			 * Задает прозрачность фона кнопки (от 0 до 255)
			 * \param transparent Прозрачность фона
			 * \result Ссылку на себя
			 */
			Button& setBackgoundTransparent(uint8_t transparent);

			const Button& operator =(const Button &button);
	};
}
}

#endif
