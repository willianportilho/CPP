/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 20:30:57 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_H
# define Dog_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);
		Dog			&operator=(Dog const &rhs);
		void		makeSound(void) const;
		void		setIdeas(std::string const idea, unsigned int const i);
		std::string	getIdeas(unsigned int const i) const;
	private:
		Brain	*_brain;
};

#endif
