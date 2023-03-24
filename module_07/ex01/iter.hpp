/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:32:38 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/24 08:17:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H

#include <cstddef>

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

#endif
