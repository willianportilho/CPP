/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/11 19:23:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _plus('+'), _minus('-')
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src) : _plus('+'), _minus('-')
{
	*this = src;

	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
		return (*this);

	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

void	PmergeMe::_checkCharacters(std::string &argument)
{
	int	amount_plus = 0;

	if (argument[0] == _minus)
		throw Exceptions("possible negative number(s)");
	for (int i= 0; argument[i]; i++)
	{
		if ((!isdigit(argument[i])) && (argument[i] != _plus))
			throw Exceptions("invalid character(s)");
		if (argument[i] == _plus)
			amount_plus++;
	}
	if ((amount_plus > 1)
	|| ((amount_plus == 1) && argument[0] != _plus)
	|| ((amount_plus == 1) && argument.size() == 1))
		throw Exceptions("invalid character(s)");

	return ;
}

void	PmergeMe::_duplicateNumbers(std::string &argument)
{
	(void)argument;

	return ;
}

void	PmergeMe::_checkArgument(std::string argument)
{
	if (argument.empty())
		throw Exceptions("empty argument(s)");
	_checkCharacters(argument);
	_duplicateNumbers(argument);

	return ;
}

void	PmergeMe::pMergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
		_checkArgument(argv[i]);

	return ;
}
