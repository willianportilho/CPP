/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/21 20:59:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template<typename T, typename U>
void	swap(T &a, U &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;

	return ;
}

template<typename T, typename U>
T const	&min(T const &a, const U &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T, typename U>
T const	&max(T const &a, U const &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif
