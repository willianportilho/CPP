/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:22:45 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/16 14:10:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie	michael("Leon Kennedy");
	michael.announce();

	Zombie	*kratos;
	kratos = newZombie("Ashley Graham");
	kratos->announce();
	delete	kratos;

	randomChump("Ada Wong");

	return (0);
}
