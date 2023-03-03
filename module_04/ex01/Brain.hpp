/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 16:23:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>

class	Brain
{
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);
		Brain		&operator=(Brain const &rhs);
		void		setIdeas(std::string const idea, unsigned int const i);
		std::string	getIdeas(unsigned int const i) const;
	protected:
		std::string	_type;
	private:
		std::string	_ideas[100];
};

#endif
