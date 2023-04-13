/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:59:23 by wportilh          #+#    #+#             */
/*   Updated: 2023/04/12 22:26:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

int main(int argc, char **argv)
{
	try
	{
		if (argc == 1)
			throw Exceptions("invalid number of arguments");
		PmergeMe	merge;
		merge.pMergeMe(argv);

		std::vector<int> vector;
		merge.sort(vector);
	}
	catch(std::exception const &e)
	{
		std::cerr << "PmergeMe: Error: " << e.what() << std::endl;
	}
	return (0);
}
