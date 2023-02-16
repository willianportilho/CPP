/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:39:49 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 17:00:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void		announce(void);
		void		set_name(std::string zombie_name);
	private:
		std::string	_name;
		static int	_number_constructed_zombie;
		static int	_number_destroyed_zombie;
};

Zombie	*zombieHorde(int N, std::string zombie_name);

#endif
