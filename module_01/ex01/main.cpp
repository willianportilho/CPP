/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:45 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 17:06:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	int		number_of_daryl = 10;
	Zombie	*daryl;
	daryl = zombieHorde(number_of_daryl, "Daryl Dixon");
	std::cout << std::endl;
	for (int i = 0; i < number_of_daryl; i++)
	{
		std::cout << "Zombie: " << (i + 1) << std::endl;
		daryl[i].announce();
	}
	std::cout << std::endl;
	delete [] daryl;
	return (0);
}
