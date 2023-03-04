/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 16:49:59 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string.h>

class	Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat			&operator=(Cat const &rhs);
		void		makeSound(void) const;
		void		setIdeas(std::string const idea, unsigned int const i);
		std::string	getIdeas(unsigned int const i) const;
		Brain		&getBrain(void) const;
	private:
		Brain	*_brain;
};

#endif
