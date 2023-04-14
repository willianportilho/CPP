/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/14 00:10:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : _PLUS('+'), _MINUS('-'), _BLOCK_MIN(5), _VECTOR(1), _DEQUE(2)
{
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &src) : _PLUS('+'), _MINUS('-'), _BLOCK_MIN(5), _VECTOR(1), _DEQUE(2)
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

long int	PmergeMe::_elapsedTime(struct timeval start, struct timeval end)
{
	return (((end.tv_sec - start.tv_sec) + 1000000) + (end.tv_usec - start.tv_usec));
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

void	PmergeMe::_fillContainer(char **argv, const int container)
{
	int number;
	if(container == _VECTOR)
	{	
		for (int i = 1; argv[i]; i++)
		{
			number = atoi(argv[i]);
			this->_vector.push_back(number);
		}
	}
	else
	{
		for (int i = 1; argv[i]; i++)
		{
			number = atoi(argv[i]);
			this->_deque.push_back(number);
		}
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

void	PmergeMe::_sortVector(char **argv)
{
	gettimeofday(&this->_startVec, NULL);
	for (int i = 1; argv[i]; i++)
		_checkArgument(argv[i]);
	_checkNumbers(argv);
	_fillContainer(argv, _VECTOR);
	_mergeInsertSort(this->_vector, 0, this->_vector.size() - 1);
	gettimeofday(&this->_endVec, NULL);

	return ;
}

void	PmergeMe::_sortDeque(char **argv)
{
	gettimeofday(&this->_startDeq, NULL);
	for (int i = 1; argv[i]; i++)
		_checkArgument(argv[i]);
	_checkNumbers(argv);
	_fillContainer(argv, _DEQUE);
	_mergeInsertSort(this->_deque, 0, this->_deque.size() - 1);
	gettimeofday(&this->_endDeq, NULL);

	return ;
}

void	PmergeMe::_printTimeToProcess(void)
{
	std::cout << "Time to process a range of " << std::setw(3)
	<< this->_vector.size() << " elements with std::vector : "
	<< _elapsedTime(this->_startVec, this->_endVec) << " us" << std::endl;

	std::cout << "Time to process a range of " << std::setw(3)
	<< this->_deque.size() << " elements with std::deque : "
	<< _elapsedTime(this->_startDeq, this->_endDeq) << " us" << std::endl;

	return ;
}

void	PmergeMe::pMergeMe(char **argv)
{
	_sortVector(argv);
	_sortDeque(argv);
	_printUnsorted(argv);
	_printSorted();
	_printTimeToProcess();

	return ;
}
