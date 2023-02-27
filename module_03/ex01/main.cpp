/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/27 14:33:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	test1("teste");
	ScavTrap	test2 = test1;

	test1.attack("Eren");
	test1.takeDamage(411);

	test1.guardGate();

	return (0);
}
