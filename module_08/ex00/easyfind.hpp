/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/29 13:09:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

#include "NumberNotFoundException.hpp"
#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int number)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), number);
	if (it != container.end())
		return it;
	throw NumberNotFoundException();
}

#endif
