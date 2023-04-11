/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/11 20:51:12 by wportilh         ###   ########.fr       */
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
	else if (argument.size() > 11)
		throw Exceptions("overflow detected");

	return ;
}

void	PmergeMe::_checkArgument(std::string argument)
{
	if (argument.empty())
		throw Exceptions("empty argument(s)");
	_checkCharacters(argument);

	return ;
}

void	PmergeMe::_checkNumbers(char **argv)
{
	long int number;
	for (int i = 1; argv[i]; i++)
	{
		number = atol(argv[i]);
		if (number > std::numeric_limits<int>::max())
			throw Exceptions("overflow detected");
		for (int j = (i + 1); argv[j]; j++)
		{
			if (number == atol(argv[j]))
				throw Exceptions("duplicate number detected");
		}
	}

	return ;
}

void	PmergeMe::pMergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
		_checkArgument(argv[i]);
	_checkNumbers(argv);

	return ;
}
