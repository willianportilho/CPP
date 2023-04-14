/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/13 21:59:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _PLUS('+'), _MINUS('-'), _BLOCK_MIN(5)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src) : _PLUS('+'), _MINUS('-'), _BLOCK_MIN(5)
{
	*this = src;

	return ;
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this != &rhs)
	{
		this->_vector.clear();
		this->_vector = rhs._vector;
		this->_deque.clear();
		this->_deque = rhs._deque;
		return (*this);
	}

	return (*this);
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

void	PmergeMe::_checkCharacters(std::string &argument)
{
	int	amountPlus = 0;

	if (argument[0] == _MINUS)
		throw Exceptions("possible negative number(s)");
	for (int i= 0; argument[i]; i++)
	{
		if ((!isdigit(argument[i])) && (argument[i] != _PLUS))
			throw Exceptions("invalid character(s)");
		if (argument[i] == _PLUS)
			amountPlus++;
	}
	if ((amountPlus > 1)
	|| ((amountPlus == 1) && argument[0] != _PLUS)
	|| ((amountPlus == 1) && argument.size() == 1))
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

void	PmergeMe::_fillContainers(char **argv)
{
	int number;
	for (int i = 1; argv[i]; i++)
	{
		number = atoi(argv[i]);
		this->_vector.push_back(number);
		this->_deque.push_back(number);
	}

	return ;
}

void	PmergeMe::_printUnsorted(char **argv)
{
	std::cout << "Before:	";
	for (int i = 1; argv[i]; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] != _PLUS)
				std::cout << argv[i][j];
		}
		std::cout << " ";	
	}
	std::cout << std::endl;

	return ;
}

void	PmergeMe::_printSorted(void)
{
	std::cout << "After:	";
	for (unsigned int i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;

	// std::cout << "After:	";
	// for (unsigned int i = 0; i < this->_deque.size(); i++)
	// 	std::cout << this->_deque[i] << " ";
	// std::cout << std::endl;

	return ;
}

void	PmergeMe::pMergeMe(char **argv)
{
	for (int i = 1; argv[i]; i++)
		_checkArgument(argv[i]);
	_checkNumbers(argv);
	_fillContainers(argv);
	_mergeInsertSort(this->_vector, 0, this->_vector.size() - 1);
	_mergeInsertSort(this->_deque, 0, this->_deque.size() - 1);
	_printUnsorted(argv);
	_printSorted();

	return ;
}
