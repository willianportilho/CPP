/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:11:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 11:11:23 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>
#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);
		WrongAnimal	&operator=(WrongAnimal const &rhs);
		void		setType(std::string const type);
		std::string	getType(void) const;
		void		makeSound(void) const;
	protected:
		std::string	_type;
};

#endif
