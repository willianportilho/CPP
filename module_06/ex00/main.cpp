/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/15 21:16:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	ScalarConverter	scalar_converter;

	if (argc != 2)
	{
		std::cerr << "convert: error: invalid number of arguments" << std::endl;
		return (1);
	}
	scalar_converter.detect_type(argv[1]);
	scalar_converter.convert(argv[1]);
	return (0);
}
