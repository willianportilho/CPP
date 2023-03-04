/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:11:27 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/04 16:49:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
# define AANIMAL_H

#include <iostream>
#include <string>

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);
		AAnimal			&operator=(AAnimal const &rhs);
		void			setType(std::string const type);
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
	protected:
		std::string		_type;
};

#endif
