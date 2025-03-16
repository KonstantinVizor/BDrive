#ifndef __BLIMDECODER_H__
#define __BLIMDECODER_H__

#include <string>
#include "Image.h"
#include "../algorithms/Haffman.h"
#include "../../libs/bitIO/inc/BitReader.h"

namespace BDrive
{
	/// Класс, представляющий декодирощик изображения из формата .blim
	/*!
	 * \deprecated
	 */
	class BlimDecoder
	{
		private:
			/*
			Haffman::Alphabet _rAlphabet;
			Haffman::Alphabet _gAlphabet;
			Haffman::Alphabet _bAlphabet;
			Haffman::Alphabet _alphaAlphabet;
			*/
			std::map<uint8_t, uint64_t> _rAlphabet;
			std::map<uint8_t, uint64_t> _gAlphabet;
			std::map<uint8_t, uint64_t> _bAlphabet;
			std::map<uint8_t, uint64_t> _alphaAlphabet;
			uint16_t _rCount;
			uint16_t _gCount;
			uint16_t _bCount;
			uint16_t _alphaCount;
			uint16_t _height;
			uint16_t _width;

			void _readHeader(BitReader &reader);
			void _readAlphabet(std::map<uint8_t, uint64_t> &alphabet, uint16_t count, BitReader &reader);
			Image _readImage(uint16_t height, uint16_t width, BitReader &reader);
			uint8_t _readHaffmanCode(const std::map<uint8_t, uint64_t> &alphabet, BitReader &reader);

		public:
			BlimDecoder() = default;
			~BlimDecoder() = default;
			explicit BlimDecoder(const BlimDecoder &) = default;
			BlimDecoder(BlimDecoder &&) = default;

			/*! \details
			 * Декодирует изображение из формата .blim в объект Image
			 * \param filename Имя входного файла
			 * \return Выходное изображение
			 */
			Image decode(const std::string &filename);

			const BlimDecoder& operator =([[maybe_unused]]const BlimDecoder &decoder);
	};
}

#endif
