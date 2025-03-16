#ifndef __HAFFMAN_H__
#define __HAFFMAN_H__

#include <memory>
#include <map>

namespace BDrive
{
	/// Класс, представляет алгоритм Хаффмана
	/*!
	 * \deprecated
	 */
	class Haffman
	{
		public:
			using Alphabet = std::map<uint64_t, std::pair<uint64_t, uint32_t>>;

		private:
			struct Node
			{
				std::shared_ptr<Node> _left;
				std::shared_ptr<Node> _right;
				uint64_t _value;
				uint32_t _count;

				Node(const std::shared_ptr<Node> &left,
					const std::shared_ptr<Node> &right,
					uint64_t value,
					uint32_t count);
			};

			Alphabet _alhpabet;

			void _recCode(std::shared_ptr<Node> node, uint64_t code, uint32_t count);

		public:
			Haffman() = default;
			~Haffman() = default;
			explicit Haffman(const Haffman &) = default;
			Haffman(Haffman &&) = default;

			/*! \details
			 * Создает алфавит, состоящий из символа и пары, задающей
			 * код символа и количесто бит  этом коде.
			 * \param table Таблица, содержащая символы и количество их
			 * повторений
			 * \result Созданный алфавит
			 */
			 Alphabet createAlphabet(const std::map<uint64_t, uint32_t> &table);
			
			const Haffman& operator =([[maybe_unused]] const Haffman &haffman);
	};
}

#endif
