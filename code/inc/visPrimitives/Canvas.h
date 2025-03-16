#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <vector>
#include "Color.h"

namespace BDrive
{
	/// Класс, представляющий из себя область пикселей
	class Canvas
	{
		private:
			std::vector<std::vector<Color>> _table;

		public:
			Canvas() = default;
			~Canvas() = default;
			explicit Canvas(const Canvas &canvas);
			Canvas(Canvas &&canvas);
			Canvas(uint16_t height, uint16_t width);

			/*! \details
			 * Устанавливает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param x Положение пикселя по вертикали
			 * \param y Положение пикселя по горизонтали
			 * \param color Цвет пикселя
			 * \return Ссылку на себя
			 */
			Canvas& setPixel(uint16_t x, uint16_t y, const Color &color);

			/// \details Возвращает размер области по вертикали
			uint16_t getHeight() const;

			/// \details Возвращает размер области по горизонтали
			uint16_t getWidth() const;

			/*! \details
			 * Возвращает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param x Положение пикселя по вертикали
			 * \param y Положение пикселя по горизонтали
			 * \return Цвет пикселя
			 */
			const Color& getPixel(uint16_t x, uint16_t y) const;

			const Canvas& operator =(const Canvas &canvas);
	};
}

#endif
