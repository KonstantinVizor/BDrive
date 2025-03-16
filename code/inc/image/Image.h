#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <vector>
#include "../visPrimitives/Color.h"

namespace BDrive
{
	/// Класс, представляющий изображение
	class Image
	{
		private:
			std::vector<std::vector<Color>> _table;
			uint16_t _width;
			uint16_t _height;

		public:
			Image() = default;
			~Image() = default;
			explicit Image(const Image &image);
			Image(Image &&image);
			Image(uint16_t height, uint16_t width);

			/*! \details
			 * Возвращает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param y Положение пикселя по вертикали
			 * \param x Положение пикселя по горизонтали
			 * \result Цвет пикселя
			 */
			const Color& getPixel(uint16_t y, uint16_t x) const;

			/*! \details
			 * Возвращает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param u Положение пикселя по вертикали
			 * \param v Положение пикселя по горизонтали
			 * \result Цвет пикселя
			 */
			const Color& getPixel(double u, double v) const;

			/// \details Возвращает ширину избражения (в пикселях)
			uint16_t getWidth() const;

			/// \details Возвращает высоту избражения (в пикселях)
			uint16_t getHeight() const;

			/*! \details
			 * Задает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param x Положение пикселя по вертикали
			 * \param y Положение пикселя по горизонтали
			 * \param color Цвет пикселя
			 * \result Ссылку на себя
			 */
			Image& setPixel(uint16_t x, uint16_t y, const Color &color);

			/*! \details
			 * Задает цвет пикселя.
			 * Началом координат принимается верхний
			 * левый угол экрана.
			 * \param u Положение пикселя по вертикали
			 * \param v Положение пикселя по горизонтали
			 * \param color Цвет пикселя
			 * \result Ссылку на себя
			 */
			Image& setPixel(double u, double v, const Color &color);
			
			const Image& operator =(const Image &image);
	};
}

#endif
