/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 18:05:17 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/01 17:46:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void	print_title(std::string const class_name, std::string const test_name)
{
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << class_name;
	std::cout << std::endl;
	std::cout << "============================================================";
	std::cout << std::endl << test_name
	<< std::endl << std::endl;
	return ;
}

static void print_info(std::string const info1, int info2)
{
	std::cout << info1 << info2 << std::endl;
	return ;
}

static void	print_new_block_tests(int break_lines)
{
	for (int i = 0; i < break_lines; i++)
	{
		std::cout << std::endl;
		std::cout << "============================================================";
	}
	std::cout << std::endl;
	return ;
}

// CLAPTRAP
static void clap_trap_tests(void)
{
	{
		print_title("CLAPTRAP TESTS", "CONSTRUCTORS AND OVERLOAD:");

		// CONSTRUCTORS AND OVERLOAD
		std::cout << "test default" << std::endl;
		ClapTrap	default_constructor;
		default_constructor.beRepaired(100);
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		std::cout << std::endl << "test named" << std::endl;
		ClapTrap	named_constructor("Named");
		named_constructor.takeDamage(100);
		print_info("Hit points (named_constructor): ", named_constructor.get_hit_points());

		std::cout << std::endl << "test copy" << std::endl;
		ClapTrap	copy_constructor(default_constructor);
		copy_constructor.attack("Someone");

		std::cout << std::endl << "test assignment copy" << std::endl;
		default_constructor = named_constructor;
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		// DESTRUCTORS
		std::cout << std::endl << "DESTRUCTORS:" << std::endl;
	}

	{
		// BALROG ATTACKS GANDALF
		print_title("CLAPTRAP TESTS", "BALROG ATTACKS GANDALF:");

		ClapTrap	balrog;
		ClapTrap	gandalf("🧙‍♂️ Gandalf");
		std::cout << std::endl;

		for (int i = 0; i < 11; i++)
		{
			print_info("Energy points (balrog): ", balrog.get_energy_points());
			balrog.attack("🧙‍♂️ Gandalf");
			if (i < 10)
				gandalf.takeDamage(balrog.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK)
		print_title("CLAPTRAP TESTS", "GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK):");

		for (int i = 0; i < 5; i++)
		{
			print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
			gandalf.attack("♨️  Balrog");
			if (i < 4)
				balrog.takeDamage(gandalf.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Balrog): ", balrog.get_hit_points());
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		gandalf.beRepaired(999999989);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK)
		print_title("CLAPTRAP TESTS", "ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK):");

		print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
		gandalf.attack("♨️  Balrog");
		balrog.takeDamage(-1);
		std::cout << std::endl;

		print_info("Hit points (Balrog): ", balrog.get_hit_points());
		balrog.attack("🧙‍♂️ Gandalf");
		balrog.beRepaired(100);
		std::cout << std::endl;

		gandalf.beRepaired(-1);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// DESTRUCTORS
		print_title("CLAPTRAP TESTS", "DESTRUCTORS:");
	}
}

// SCAVTRAP
static void scav_trap_tests(void)
{
	print_new_block_tests(6);
	{
		print_title("SCAVTRAP TESTS", "CONSTRUCTORS AND OVERLOAD:");

		// CONSTRUCTORS AND OVERLOAD
		std::cout << "test default" << std::endl;
		ScavTrap	default_constructor;
		default_constructor.beRepaired(100);
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		std::cout << std::endl << "test named" << std::endl;
		ScavTrap	named_constructor("Named");
		named_constructor.takeDamage(100);
		print_info("Hit points (named_constructor): ", named_constructor.get_hit_points());

		std::cout << std::endl << "test copy" << std::endl;
		ScavTrap	copy_constructor(default_constructor);
		copy_constructor.attack("Someone");

		std::cout << std::endl << "test assignment copy" << std::endl;
		default_constructor = named_constructor;
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		// DESTRUCTORS
			std::cout << std::endl << "DESTRUCTORS:" << std::endl;
	}

	{
		// BALROG ATTACKS GANDALF
		print_title("SCAVTRAP TESTS", "BALROG ATTACKS GANDALF:");

		ScavTrap	balrog;
		ScavTrap	gandalf("🧙‍♂️ Gandalf");
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			print_info("Energy points (balrog): ", balrog.get_energy_points());
			balrog.attack("🧙‍♂️ Gandalf");
			if (i < 2)
				gandalf.takeDamage(balrog.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK)
		print_title("SCAVTRAP TESTS", "GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK):");

		for (int i = 0; i < 4; i++)
		{
			print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
			gandalf.attack("♨️  Balrog");
			balrog.takeDamage(gandalf.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Balrog): ", balrog.get_hit_points());

		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		gandalf.beRepaired(999999939);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK)
		print_title("SCAVTRAP TESTS", "ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK):");

		print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
		std::cout << std::endl;

		gandalf.guardGate(); // GUARD GATE
		std::cout << std::endl;

		gandalf.attack("♨️  Balrog");
		balrog.takeDamage(-1);
		std::cout << std::endl;
		print_info("Hit points (Balrog): ", balrog.get_hit_points());
		balrog.attack("🧙‍♂️ Gandalf");
		balrog.beRepaired(100);
		gandalf.beRepaired(-1);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		print_title("SCAVTRAP TESTS", "DESTRUCTORS:");
	}
}

// FRAGTRAP
static void frag_trap_tests(void)
{
	print_new_block_tests(6);
	{
		print_title("FRAGTRAP TESTS", "CONSTRUCTORS AND OVERLOAD:");

		// CONSTRUCTORS AND OVERLOAD
		std::cout << "test default" << std::endl;
		FragTrap	default_constructor;
		default_constructor.beRepaired(100);
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		std::cout << std::endl << "test named" << std::endl;
		FragTrap	named_constructor("Named");
		named_constructor.takeDamage(100);
		print_info("Hit points (named_constructor): ", named_constructor.get_hit_points());

		std::cout << std::endl << "test copy" << std::endl;
		FragTrap	copy_constructor(default_constructor);
		copy_constructor.attack("Someone");

		std::cout << std::endl << "test assignment copy" << std::endl;
		default_constructor = named_constructor;
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());

		// DESTRUCTORS
		std::cout << std::endl << "DESTRUCTORS:" << std::endl;
	}

	{
		// BALROG ATTACKS GANDALF
		print_title("FRAGTRAP TESTS", "BALROG ATTACKS GANDALF:");

		FragTrap	balrog;
		FragTrap	gandalf("🧙‍♂️ Gandalf");
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			print_info("Energy points (balrog): ", balrog.get_energy_points());
			balrog.attack("🧙‍♂️ Gandalf");
			if (i < 2)
				gandalf.takeDamage(balrog.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK)
		print_title("FRAGTRAP TESTS", "GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK):");

		for (int i = 0; i < 3; i++)
		{
			print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
			gandalf.attack("♨️  Balrog");
			balrog.takeDamage(gandalf.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Balrog): ", balrog.get_hit_points());

		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		gandalf.beRepaired(999999959);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK)
		print_title("FRAGTRAP TESTS", "ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK):");

		print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
		gandalf.attack("♨️  Balrog");
		balrog.takeDamage(-1);
		std::cout << std::endl;
		print_info("Hit points (Balrog): ", balrog.get_hit_points());
		balrog.attack("🧙‍♂️ Gandalf");
		balrog.beRepaired(100);
		gandalf.beRepaired(-1);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		std::cout << std::endl;

		gandalf.highFivesGuys(); // HIGH FIVES

		// DESTRUCTORS
		print_title("FRAGTRAP TESTS:", "DESTRUCTORS:");
	}
}

static void	diamond_trap_tests(void)
{
	print_new_block_tests(6);
	{
		print_title("DIAMONDTRAP TESTS", "CONSTRUCTORS AND OVERLOAD:");

		// CONSTRUCTORS AND OVERLOAD
		std::cout << "test default" << std::endl;
		DiamondTrap	default_constructor;
		default_constructor.beRepaired(100);
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());
		default_constructor.whoAmI(); // WHOAMI

		std::cout << std::endl << "test named" << std::endl;
		DiamondTrap	named_constructor("Named");
		named_constructor.takeDamage(100);
		print_info("Hit points (named_constructor): ", named_constructor.get_hit_points());
		named_constructor.whoAmI(); // WHOAMI

		std::cout << std::endl << "test copy" << std::endl;
		DiamondTrap	copy_constructor(default_constructor);
		copy_constructor.attack("Someone");
		copy_constructor.whoAmI(); // WHOAMI

		std::cout << std::endl << "test assignment copy" << std::endl;
		default_constructor = named_constructor;
		print_info("Hit points (default_constructor): ", default_constructor.get_hit_points());
		default_constructor.whoAmI(); // WHOAMI
		std::cout << std::endl;


		// DESTRUCTORS
		std::cout << std::endl << "DESTRUCTORS:" << std::endl;
	}

	{
		// PRINT INFO (ENERGY POINTS, ATTACK DAMAGE, HIT POINTS ...):
		print_title("DIAMONDTRAP TESTS", "PRINT INFO (ENERGY POINTS, ATTACK DAMAGE, HIT POINTS ...):");

		DiamondTrap	balrog;
		DiamondTrap	gandalf("🧙‍♂️ Gandalf");
		std::cout << std::endl;

		// BALROG
		print_info("    Hit points (Balrog): ", balrog.get_hit_points());
		print_info(" Energy points (Balrog): ", balrog.get_energy_points());
		print_info(" Attack Damage (Balrog): ", balrog.get_attack_damage());
		balrog.guardGate();
		balrog.highFivesGuys();
		balrog.whoAmI();
		std::cout << std::endl;

		// GANDALF
		print_info("   Hit points (Gandalf): ", gandalf.get_hit_points());
		print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
		print_info("Attack Damage (Gandalf): ", gandalf.get_attack_damage());
		gandalf.guardGate();
		gandalf.highFivesGuys();
		gandalf.whoAmI();
		std::cout << std::endl;
		
		// BALROG ATTACKS GANDALF
		print_title("DIAMONDTRAP TESTS", "BALROG ATTACKS GANDALF:");

		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			print_info("Energy points (balrog): ", balrog.get_energy_points());
			balrog.attack("🧙‍♂️ Gandalf");
			if (i < 2)
				gandalf.takeDamage(balrog.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK)
		print_title("DIAMONDTRAP TESTS", "GANDALF ATTACKS BALROG (POSITIVE NUMBER ATTACK):");

		for (int i = 0; i < 3; i++)
		{
			print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
			gandalf.attack("♨️  Balrog");
			balrog.takeDamage(gandalf.get_attack_damage());
			std::cout << std::endl;
		}
		print_info("Hit points (Balrog): ", balrog.get_hit_points());

		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		gandalf.beRepaired(999999959);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());

		// ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK)
		print_title("DIAMONDTRAP TESTS", "ADDITIONAL TESTS (NEGATIVE NUMBER ATTACK):");

		print_info("Energy points (Gandalf): ", gandalf.get_energy_points());
		std::cout << std::endl;

		gandalf.guardGate(); // GUARD GATE
		std::cout << std::endl;
	
		gandalf.attack("♨️  Balrog");
		balrog.takeDamage(-1);
		std::cout << std::endl;
		print_info("Hit points (Balrog): ", balrog.get_hit_points());
		balrog.attack("🧙‍♂️ Gandalf");
		balrog.beRepaired(100);
		gandalf.beRepaired(-1);
		print_info("Hit points (Gandalf): ", gandalf.get_hit_points());
		std::cout << std::endl;

		gandalf.highFivesGuys(); // HIGH FIVES
		std::cout << std::endl;

		gandalf.whoAmI();

		// DESTRUCTORS
		print_title("DIAMONDTRAP TESTS:", "DESTRUCTORS:");
	}
}

int main(void)
{
	clap_trap_tests();
	scav_trap_tests();
	frag_trap_tests();
	diamond_trap_tests();

	return (0);
}
