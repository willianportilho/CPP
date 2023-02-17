/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 16:15:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomSed.hpp"

int	main(int argc, char *argv[])
{
	CustomSed	replace;

	if (argc != 4)
		std::cerr << "replace: error: four arguments are required" << std::endl;
	replace.replace(argv[1], argv[2], argv[3]);
	return (0);
}
