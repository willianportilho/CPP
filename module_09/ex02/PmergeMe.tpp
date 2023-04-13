/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:10:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/13 19:33:09 by wportilh         ###   ########.fr       */
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

	return ;
}

template<typename T>
void	PmergeMe::_merge(T &container, int beginIndex, int middleIndex, int endIndex)
{
	int	sizeL = middleIndex - beginIndex + 1;
	int	sizeR = endIndex - middleIndex;
	int indexL = 0, indexR = 0, index = beginIndex;
	T	containerL(sizeL), containerR(sizeR);

	while (index <= endIndex)
	{
		if (index <= middleIndex)
			containerL[indexL++] = container[index++];
		else
			containerR[indexR++] = container[index++];
	}

	indexL = 0, indexR = 0, index = beginIndex;
	while ((indexL < sizeL) && (indexR < sizeR))
	{
		if (containerL[indexL] < containerR[indexR])
			container[index++] = containerL[indexL++];
		else
			container[index++] = containerR[indexR++];
	}
	while(indexL < sizeL)
		container[index++] = containerL[indexL++];
	while(indexR < sizeR)
		container[index++] = containerR[indexR++];

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
