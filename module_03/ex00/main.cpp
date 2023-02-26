/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/25 21:38:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	test;

	test.attack("Eren");
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);
	test.beRepaired(1000);

	return (0);
}
