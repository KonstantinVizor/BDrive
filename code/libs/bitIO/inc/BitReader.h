#ifndef __BITREADER_H__
#define __BITREADER_H__

#include <fstream>

/// Класс, представляющий чтение из файла побитово
class BitReader
{
	private:
		std::ifstream _stream;
		char _data;
		int _rbits;

	public:
		BitReader() = delete;
		explicit BitReader(const BitReader &reader) = delete;
		BitReader(BitReader &&reader) = delete;
		~BitReader();
		explicit BitReader(const std::string &filename);

		/*! \details
		 * Считывает данные из файла побитово. Считываются
		 * nbits бит. Возвращается пара, состоящая из данных, записанных
		 * в младшие биты переменной типа long и количества считанных битов.
		 * Если это количесто меньше nbits, то чтение дошла до конца файла
		 * или дальнейшее чтение невозможно
		 * \param nbits Количество бит для чтения
		 * \result Считанные данные
		 */
		std::pair<long, int> read(int nbits);

		/*! \details
		 * Закрывает файл для чтения
		 */
		void close();

		const BitReader& operator =(const BitReader &reader) = delete;
};

#endif
