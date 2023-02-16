/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:45 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 14:24:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie	leon("Leon Kennedy");
	leon.announce();

	Zombie	*ada;
	ada = newZombie("Ada Wong");
	ada->announce();
	delete	ada;

	randomChump("Ashley Graham");

	return (0);
}
