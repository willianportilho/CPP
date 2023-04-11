/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:58:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/11 20:11:31 by wportilh         ###   ########.fr       */
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
	private:
		void		_checkCharacters(std::string &argument);
		void		_checkNumbers(char **argv);
		void		_checkArgument(std::string argument);
		const char	_plus;
		const char	_minus;
};

#endif
