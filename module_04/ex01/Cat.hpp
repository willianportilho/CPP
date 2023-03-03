/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 15:24:19 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);
		Cat		&operator=(Cat const &rhs);
		void	makeSound(void) const;
	private:
		Brain	*_brain;
};

#endif
