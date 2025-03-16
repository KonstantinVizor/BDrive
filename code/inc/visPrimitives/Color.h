#ifndef __COLOR_H__
#define __COLOR_H__

#include <cinttypes>

namespace BDrive
{
	/// Класс, представвляющий цвет в формате RGBA
	class Color
	{
		private:
			uint8_t _r;
			uint8_t _g;
			uint8_t _b;
			uint8_t _alpha;

		public:
			~Color() = default;
			Color();
			explicit Color(const Color &color);
			Color(Color &&color);

			/*! \details
			 * Задает красный канал
			 * \param r Значение красного канала от 0 до 255
			 * \return Ссылку на себя
			 */
			Color& setR(uint8_t r);

			/*! \details
			 * Задает зеленый канал
			 * \param g Значение зеленого канала от 0 до 255
			 * \return Ссылку на себя
			 */
			Color& setG(uint8_t g);

			/*! \details
			 * Задает синий канал
			 * \param b Значение синего канала от 0 до 255
			 * \return Ссылку на себя
			 */
			Color& setB(uint8_t b);

			/*! \details
			 * Задает альфа канал
			 * \param alpha Значение альфа канала от 0 до 255
			 * \return Ссылку на себя
			 */
			Color& setAlpha(uint8_t alpha);

			/// \details Возвращает значение красного канала
			uint8_t getR() const;

			/// \details Возвращает значение зеленого канала
			uint8_t getG() const;

			/// \details Возвращает значение синего канала
			uint8_t getB() const;

			/// \details Возвращает значение альфа канала
			uint8_t getAlpha() const;

			Color operator +(const Color &color) const;
			Color operator *(double number) const;
			const Color& operator =(const Color &color);
	};
}

#endif
