/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/13 12:56:11 by wportilh         ###   ########.fr       */
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
		void				_sort(T &container, size_t beginIndex, size_t endIndex);
		void				_checkCharacters(std::string &argument);
		void				_checkNumbers(char **argv);
		void				_checkArgument(std::string argument);
		void				_fillContainers(char **argv);
		const char			_PLUS;
		const char			_MINUS;
		const size_t		_BLOCK_MIN;
		std::vector<int>	_vector;
};

#include "PmergeMe.tpp"

#endif
