#ifndef __BLIMENCODER_H__
#define __BLIMENCODER_H__

#include <string>
#include "Image.h"
#include "../algorithms/Haffman.h"
//#include "../../libs/bitIO/inc/BitWriter.h"

namespace BDrive
{
	/// Класс, представляющий кодирощик изображения в формат .blim
	/*!
	 * \deprecated
	 */
	class BlimEncoder
	{
		private:
			void _createAlphabets(const Image &image);
//			void _writeHeader(uint8_t headerString[5], uint16_t height, uint16_t width, BitWriter &writer) const;
//			void _writeData(const Image &image, BitWriter &writer) const;

			Haffman::Alphabet _rAlphabet;
			Haffman::Alphabet _gAlphabet;
			Haffman::Alphabet _bAlphabet;
			Haffman::Alphabet _alphaAlphabet;

		public:
			BlimEncoder() = default;
			~BlimEncoder() = default;
			explicit BlimEncoder(const BlimEncoder &) = default;
			BlimEncoder(BlimEncoder &&) = default;

			/*! \details
			 * Кодирует изображение в формат .blim и сохраняет в файл
			 * \param filename Имя выходного файла
			 * \param image Изображение
			 */
			void encode(const std::string &filename, const Image &image);

			const BlimEncoder& operator =([[maybe_unused]]const BlimEncoder &encoder);
	};
}

#endif
