#include "../../inc/algorithms/Haffman.h"
#include <vector>

BDrive::Haffman::Node::Node(const std::shared_ptr<Node> &left, const std::shared_ptr<Node> &right, uint64_t value, uint32_t count) :
														_left(left),
														_right(right),
														_value(value),
														_count(count)
{}

void BDrive::Haffman::_recCode(std::shared_ptr<Node> node, uint64_t code, uint32_t count)
{
	if (node->_left == NULL && node->_right == NULL)
		_alhpabet[node->_value] = {code, count};
	else
	{
		_recCode(node->_left, (code << 1), count + 1);
		_recCode(node->_right, (code << 1) | 0b1, count + 1);
	}
	return;
}

BDrive::Haffman::Alphabet BDrive::Haffman::createAlphabet(const std::map<uint64_t, uint32_t> &table)
{
	std::vector<std::shared_ptr<Node>> vector;
	std::shared_ptr<Node> min[2];
	std::map<uint64_t, uint32_t>::const_iterator it;
	std::vector<std::shared_ptr<Node>>::const_iterator vit;
	std::vector<std::shared_ptr<Node>>::const_iterator minIt;
	_alhpabet.clear();
	for (it = table.begin(); it != table.end(); it++)
		vector.push_back(std::make_shared<Node>(std::shared_ptr<Node>(NULL), std::shared_ptr<Node>(NULL), it->first, it->second));
	while (vector.size() != 1)
	{
		for (uint32_t j = 0; j < 2; j++)
		{
			minIt = vector.begin();
			for (vit = vector.begin(); vit != vector.end(); vit++)
			{
				if ((*minIt)->_count > (*vit)->_count)
					minIt = vit;
			}
			min[j] = *minIt;
			vector.erase(minIt);
		}
		vector.push_back(std::make_shared<Node>(min[0], min[1], 0, min[0]->_count + min[1]->_count));
	}
	_recCode(vector[0], 0, 0);
	return _alhpabet;
}

const BDrive::Haffman& BDrive::Haffman::operator =([[maybe_unused]] const Haffman &haffman)
{
	return *this;
}
