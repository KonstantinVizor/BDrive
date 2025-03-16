#ifndef __BITWRITER_H__
#define __BITWRITER_H__

#include <fstream>

/// Класс, представляющий запись в файл побитово
class BitWriter
{
	private:
		std::ofstream _stream;
		char _data;
		int _rbits;

	public:
		BitWriter() = delete;
		explicit BitWriter(const BitWriter &writer) = delete;
		BitWriter(BitWriter &&writer) = delete;
		~BitWriter();
		explicit BitWriter(const std::string &filename);

		/*! \details
		 * Записывает данные в файл побитово. Записывваются
		 * младшие nbits бита из data
		 * \param data Данные для записи
		 * \param nbits Количество бит для записи
		 */
		void write(long data, int nbits);

		/*! \details
		 * Закрывает файл для записи
		 */
		void close();

		const BitWriter& operator =(const BitWriter &writer) = delete;
};

#endif
