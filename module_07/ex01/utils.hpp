/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 08:14:26 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/24 08:17:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <iostream>
#include <string>

template<typename T>
void	printElement(T &arg)
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
	std::cout << "error: type not accepted: ";
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
	std::cout << "error: type not accepted: ";
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
