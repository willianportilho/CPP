/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:32:38 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/22 20:57:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstddef>
#include <iostream>
#include <string>

template<typename T>
void	iter(T *array, size_t lenght, void (*f)(T &arg))
{
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
	return ;
}

template<typename T>
void	iter(T const *array, size_t lenght, void (*f)(T const &arg))
{
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
	return ;
}

template<typename T>
void	print(T &arg)
{
	std::cout << arg << " ";
	return ;
}

template<typename T>
void	increment(T &arg)
{
	arg++;
	return ;
}

template<typename T>
void	decrement(T &arg)
{
	arg--;
	return ;
}

template<typename T>
void	toLowerCase(T &arg)
{
	(void)arg;
	std::cout << "type not accepted = ";
	return ;
}

template<>
void	toLowerCase(std::string &arg)
{
	for (int i = 0; arg[i]; i++)
		arg[i] = std::tolower(arg[i]);
	return ;
}

template<typename T>
void	toUpperCase(T &arg)
{
	(void)arg;
	std::cout << "type not accepted = ";
	return ;
}

template<>
void	toUpperCase(std::string &arg)
{
	for (int i = 0; arg[i]; i++)
		arg[i] = std::toupper(arg[i]);
	return ;
}

#endif
