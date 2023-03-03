/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:11:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 15:23:53 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>
#include <string>

class	Animal
{
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal			&operator=(Animal const &rhs);
		void			setType(std::string const type);
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string		_type;
};

#endif
