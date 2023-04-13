/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:10:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/13 17:22:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "insert: ";
	for (int k = beginIndex; k <= endIndex; k++)
		std::cout << container[k] << " ";
	std::cout << std::endl;

	return ;
}

template<typename T>
void	PmergeMe::_merge(T &container, int beginIndex, int middleIndex, int endIndex)
{
	T	containerLeft;
	T	containerRight;

	
	for (int i = beginIndex; i <= endIndex; i++)
	{
		if (i <= middleIndex)
			containerLeft.push_back(container[i]);
		else
			containerRight.push_back(container[i]);
	}

	
	for (int i = 0; i <= endIndex; i++)
		std::cout << container[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i <= middleIndex; i++)
		std::cout << containerLeft[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < middleIndex; i++)
		std::cout << containerRight[i] << " ";
	std::cout << std::endl;
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
		_merge(container, beginIndex, middleIndex, endIndex);
	}
	else
		_insertionSort(container, beginIndex, endIndex);

	return ;
}
