/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 19:15:14 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 20:03:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class	Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		void				setType(std::string type);
		std::string const	&getType(void);
	private:
		std::string	_type;
};

#endif
