/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NumberNotFoundException.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/28 14:23:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NumberNotFoundException.hpp"

const char *NumberNotFoundException::what(void) const throw()
{
	return ("easyfind: error: number not found exception 🔎❓❓❓");
}
