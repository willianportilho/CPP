/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/14 00:10:53 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>
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
		void				_sortVector(char **argv);
		void				_sortDeque(char **argv);
		void				_checkCharacters(std::string &argument);
		void				_checkNumbers(char **argv);
		void				_checkArgument(std::string argument);
		void				_fillContainer(char **argv, const int container);
		void				_printUnsorted(char **argv);
		void				_printSorted(void);
		long int			_elapsedTime(struct timeval start, struct timeval end);
		void				_printTimeToProcess(void);
		const char			_PLUS;
		const char			_MINUS;
		const int			_BLOCK_MIN;
		const int			_VECTOR;
		const int			_DEQUE;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		struct timeval		_startVec;
		struct timeval		_endVec;
		struct timeval		_startDeq;
		struct timeval		_endDeq;
};

#include "PmergeMe.tpp"

#endif
