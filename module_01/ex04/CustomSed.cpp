/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:21:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 16:13:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomSed.hpp"

CustomSed::CustomSed(void)
{
	return ;	
}

CustomSed::~CustomSed(void)
{
	return ;
}

void	CustomSed::replace(std::string const filename, \
		std::string const s1, std::string const s2)
{
	std::cout << filename << " " << s1 << " " << s2 << std::endl;
}
