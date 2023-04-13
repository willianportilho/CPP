#include "PmergeMe.hpp"

template<typename T>
void	PmergeMe::_sort(T &container, size_t beginIndex, size_t endIndex)
{
	if ((endIndex - beginIndex) > _BLOCK_MIN)
	{
		size_t middleIndex = (beginIndex + endIndex) / 2;
		_sort(container, beginIndex, middleIndex);
		_sort(container, (middleIndex + 1), endIndex);
		std::cout << "merge" << std::endl;
	}
	else
		std::cout << "insert" << std::endl;
	return ;
}
