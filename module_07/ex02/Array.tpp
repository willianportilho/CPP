/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:20:36 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/23 16:51:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _elements(NULL), _size(0)
{
	std::cout << "default constructor Array called whith no parameter: size(0)" << std::endl;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n): _elements(new T[n]()), _size(n)
{
	std::cout << "custom constructor Array called whith size parameter: size(" << this->_size << ")" << std::endl;
	return ;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] this->_elements;
	std::cout << "destructor Array called" << std::endl;
	return;
}

template<typename T>
Array<T>::Array(Array const &src): _elements(NULL)
{
	*this = src;
	std::cout << "copy Array constructor called" << std::endl;
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array<T> const &rhs)
{
	if (this != &rhs)
	{
		if (this->_elements)
			delete[] this->_elements;
		this->_size = rhs.size();
		this->_elements = new T[rhs.size()]();
		for (size_t i = 0; i < rhs.size(); i++)
		 	this->_elements[i] = rhs._elements[i];
	}
	std::cout << "assignment copy Array called" << std::endl;
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](size_t index)
{
	if (index >= this->size())
		 throw Array::outOfRangeException();
	return (this->_elements[index]);
}

template<typename T>
T const	&Array<T>::operator[](size_t index) const
{
	if (index >= this->size())
		 throw Array::outOfRangeException();
	return (this->_elements[index]);
}

template<typename T>
size_t	Array<T>::size(void) const
{
	return (this->_size);
}

template<typename T>
const char	*Array<T>::outOfRangeException::what(void) const throw()
{
	return ("array: error: out of range exception 💥");
}
