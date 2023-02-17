/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:21:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 14:25:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomSed.hpp"

CustomSed::CustomSed(std::string filename, std::string s1, std::string s2)
{
	std::cout << filename << std::endl << s1 << std::endl << s2 << std::endl;
	return ;	
}

CustomSed::~CustomSed(void)
{
	return ;
}
