/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/12 22:44:15 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H

#include <string>
#include <iostream>
#include <stdlib.h>
#include <limits>
#include "Exceptions.hpp"

class	PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe	&operator=(PmergeMe const &rhs);
		void		pMergeMe(char **argv);
		template<typename T>
		void		sort(T &container, size_t begin_index, size_t end_index);
	private:
		void		_checkCharacters(std::string &argument);
		void		_checkNumbers(char **argv);
		void		_checkArgument(std::string argument);
		const char	_PLUS;
		const char	_MINUS;
};

#include "PmergeMe.tpp"

#endif
