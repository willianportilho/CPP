/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:31:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 12:03:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
	WrongCat(void);
	WrongCat(WrongCat const &src);
	~WrongCat(void);
	WrongCat	&operator=(WrongCat const &rhs);
	void		makeSound(void) const;
};

#endif
