#include "PmergeMe.hpp"

template<typename T>
void	PmergeMe::_insertionSort(T &container, int beginIndex, int endIndex)
{
	for (int i = beginIndex; i < endIndex; i++)
	{
		int tempValue = container[i + 1];
		int j = i + 1;
		while ((j > beginIndex) && container[j - 1] > tempValue)
		{
			container[j] = container[j - 1];
			j--;
		}
		container[j] = tempValue;
	}
	for (int k = beginIndex; k <= endIndex; k++)
		std::cout << container[k] << " ";
	std::cout << std::endl;

	return ;
}

template<typename T>
void	PmergeMe::_sort(T &container, int beginIndex, int endIndex)
{
	if ((endIndex - beginIndex) > _BLOCK_MIN)
	{
		int middleIndex = (beginIndex + endIndex) / 2;
		_sort(container, beginIndex, middleIndex);
		_sort(container, (middleIndex + 1), endIndex);
	}
	else
		_insertionSort(container, beginIndex, endIndex);

	return ;
}
