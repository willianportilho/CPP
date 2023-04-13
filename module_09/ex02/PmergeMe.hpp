/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/13 20:03:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include "Exceptions.hpp"

class	PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe			&operator=(PmergeMe const &rhs);
		void				pMergeMe(char **argv);
	private:
		template<typename T>
		void				_merge(T &container, int beginIndex, int middleIndex, int endIndex);
		template<typename T>
		void				_insertionSort(T &container, int beginIndex, int endIndex);
		template<typename T>
		void				_mergeInsertSort(T &container, int beginIndex, int endIndex);
		void				_checkCharacters(std::string &argument);
		void				_checkNumbers(char **argv);
		void				_checkArgument(std::string argument);
		void				_fillContainers(char **argv);
		void				_printUnsorted(char **argv);
		void				_printSorted(void);
		const char			_PLUS;
		const char			_MINUS;
		const int			_BLOCK_MIN;
		std::vector<int>	_vector;
};

#include "PmergeMe.tpp"

#endif
