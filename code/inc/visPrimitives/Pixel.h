#ifndef __PIXEL_H__
#define __PIXEL_H__

#include "Color.h"

namespace BDrive
{
	/// Класс, представляющий собой пиксель
	/*!
	 * \deprecated
	 */
	class Pixel
	{
		private:
			Color _color;
			uint16_t _x;
			uint16_t _y;

		public:
			Pixel() = default;
			~Pixel() = default;
			explicit Pixel(const Pixel &pixel);
			Pixel(Pixel &&pixel);

			/*! \details
			 * Задает цвет пикселя
			 * \param color Значение цвета
			 * \return Ссылку на себя
			 */
			Pixel& setColor(const Color &color);

			/*! \details
			 * Задает положение пикселя по вертикали
			 * Началом координат принимается верхний левый угол экрана
			 * \param x Положение пикселя по вертикали
			 * \return Ссылку на себя
			 */
			Pixel& setX(uint16_t x);

			/*! \details
			 * Задает положение пикселя по горизонтали
			 * Началом координат принимается верхний левый угол экрана
			 * \param x Положение пикселя по горизонтали
			 * \return Ссылку на себя
			 */
			Pixel& setY(uint16_t y);

			/// \details Возвращает цвет пикселя
			const Color& getColor() const;

			/// \details Возвращает положение пикселя по вертикали
			uint16_t getX() const;

			/// \details Возвращает положение пикселя по горизонтали
			uint16_t getY() const;

			const Pixel& operator =(const Pixel &pixel);
	};
}

#endif
