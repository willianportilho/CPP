/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:21:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 18:36:45 by wportilh         ###   ########.fr       */
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
	std::ifstream	infile;

	if (filename.empty() || s1.empty())
	{
		std::cerr << "replace: error: filename or fisrt argument empty"
		<< std::endl;
		return ;
	}
	infile.open(filename);
	if (!infile.is_open())
	{
		std::cerr << "replace: error: cannot open the file" << std::endl;
		return ;
	}
}
