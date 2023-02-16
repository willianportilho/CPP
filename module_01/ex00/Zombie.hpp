/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:39:49 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 14:21:33 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string zombie_name);
		~Zombie(void);
		void		announce(void);
	private:
		std::string	name;
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

#endif
