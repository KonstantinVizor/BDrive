#include "../../inc/algorithms/Haffman.h"
#include <cassert>
#include <iostream>

int main(void)
{
	BDrive::Haffman haffman;
	std::map<uint64_t, uint32_t> map1 = {{0, 5}, {1, 5}, {2, 5}, {3, 5}};
	std::map<uint64_t, uint32_t> map2 = {{0, 1}, {1, 1}, {2, 2}, {3, 4}};
	std::map<uint64_t, std::pair<uint64_t,uint32_t>> res1;
	std::map<uint64_t, std::pair<uint64_t,uint32_t>> res2;

	res1 = haffman.createAlphabet(map1);
	for (uint32_t i = 0; i < (uint32_t)res1.size(); i++)
		assert(res1[i].second == 2);

	res2 = haffman.createAlphabet(map2);
	assert(res2[0].second == 3);
	assert(res2[1].second == 3);
	assert(res2[2].second == 2);
	assert(res2[3].second == 1);
	return 0;
}
