/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/27 16:45:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	balrog;
	ClapTrap	gandalf("🧙‍♂️ Gandalf");

	// CONSTRUCTORS AND OVERLOAD
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << "CONSTRUCTORS AND OVERLOAD:"
	<< std::endl << std::endl;

	std::cout << "test default" << std::endl;
	ClapTrap	default_constructor;
	default_constructor.beRepaired(100);
	std::cout << "Hit points (default_constructor): " << default_constructor.get_hit_points()
	<< std::endl;

	std::cout << std::endl << "test named" << std::endl;
	ClapTrap	named_constructor("Named");
	named_constructor.takeDamage(100);
	std::cout << "Hit points (named_constructor): " << named_constructor.get_hit_points()
	<< std::endl;

	std::cout << std::endl << "test copy" << std::endl;
	ClapTrap	copy_constructor(default_constructor);
	copy_constructor.attack("Someone");

	std::cout << std::endl << "test assignment copy" << std::endl;
	default_constructor = named_constructor;
	std::cout << "Hit points (default_constructor): " << default_constructor.get_hit_points()
	<< std::endl;

	// BALROG ATTACKS GANDALF
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << "BALROG ATTACKS GANDALF:"
	<< std::endl << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Energy points (balrog): " << balrog.get_energy_points()
		<< std::endl;
		balrog.attack("🧙‍♂️ Gandalf");
		if (i < 10)
			gandalf.takeDamage(balrog.get_attack_damage());
		std::cout << std::endl;
	}
	std::cout << "Hit points (Gandalf): " << gandalf.get_hit_points();
	std::cout << std::endl;

	// GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK)
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << "GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK):"
	<< std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Energy points (gandalf): " << gandalf.get_energy_points()
		<< std::endl;
		gandalf.attack("♨️  Balrog");
		if (i < 4)
			balrog.takeDamage(gandalf.get_attack_damage());
		std::cout << std::endl;
	}
	std::cout << "Hit points (Balrog): " << balrog.get_hit_points();
	std::cout << std::endl;

	std::cout << "Hit points (Gandalf): " << gandalf.get_hit_points();
	std::cout << std::endl;
	gandalf.beRepaired(999999989);
	std::cout << "Hit points (Gandalf): " << gandalf.get_hit_points();
	std::cout << std::endl;

	// ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK)
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << "ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK):"
	<< std::endl << std::endl;
	std::cout << "Energy points (gandalf): " << gandalf.get_energy_points()
	<< std::endl;
	gandalf.attack("♨️  Balrog");
	balrog.takeDamage(-1);
	std::cout << std::endl;
	std::cout << "Hit points (Balrog): " << balrog.get_hit_points();
	std::cout << std::endl;
	balrog.attack("🧙‍♂️ Gandalf");
	balrog.beRepaired(100);
	gandalf.beRepaired(-1);
	std::cout << "Hit points (Gandalf): " << gandalf.get_hit_points();
	std::cout << std::endl << std::endl;

	return (0);
}
