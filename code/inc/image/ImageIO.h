#ifndef __IMAGEIO_H__
#define __IMAGEIO_H__

#include <string>
#include "Image.h"

namespace BDrive
{
	/// Класс, представляющий чтение и запись изображений
	/*!
	 * \todo
	 * Класс является оберткой для библиотеки
	 * OpemImageIO
	 */
	class ImageIO
	{
		public:
			ImageIO() = default;
			~ImageIO() = default;
			explicit ImageIO(const ImageIO &) = default;
			ImageIO(ImageIO &&) = default;

			/*! \details
			 * Производит чтение изображения из файла
			 * и возвращает в виде объекта типа Image
			 * \param filename Имя файла для чтения
			 * \result Считанное изображение
			 */
			Image read(const std::string &filename) const;

			/*! \details
			 * Производит запись изображения в файл
			 * \param filename Имя файла для записи
			 * \param image Изображение для записи
			 */
			void write(const std::string &filename, const Image &image) const;

			const ImageIO& operator =(const ImageIO &);
	};
}

#endif
