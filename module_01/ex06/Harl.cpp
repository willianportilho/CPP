/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:27:37 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/22 11:20:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_debug(void)
{
	std::cout
	<< "I love having extra bacon for my"
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< std::endl
	<< "I really do!"
	<< std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout
	<< "I cannot believe adding extra bacon costs more money." 
	<< std::endl
	<< "You didn't put enough bacon in my burger! "
	<< std::endl
	<< "If you did, I wouldn't be asking for more!"
	<< std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout
	<< "I think I deserve to have some extra bacon for free. "
	<< std::endl
	<< "I've been coming for years whereas you started working "
	<< "here since last month."
	<< std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	Harl::_f 	p_level[4] = \
	{&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	s_level[4] = \
	{"DEBUG", "INFO", "WARNING", "ERROR"};
	int			n_level;

	n_level = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == s_level[i])
			n_level = i;
	}
	switch (n_level)
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl; (this->*p_level[DEBUG])();
			std::cout << std::endl;
			// fallthrough
		case INFO:
			std::cout << "[ INFO ]" << std::endl; (this->*p_level[INFO])();
			std::cout << std::endl;
			// fallthrough
		case WARNING:
			std::cout << "[ WARNING ]" << std::endl; (this->*p_level[WARNING])();
			std::cout << std::endl;
			// fallthrough
		case ERROR:
			std::cout << "[ ERROR ]" << std::endl; (this->*p_level[ERROR])();
			break ;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
			break;
	}
	return ;
}
