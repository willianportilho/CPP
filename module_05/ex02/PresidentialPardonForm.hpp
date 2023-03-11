/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/10 16:30:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include <iostream>
#include <string>

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);
		std::string const		getTarget(void) const;
		void					execute(Bureaucrat const & executor) const;
	private:
		PresidentialPardonForm(void);
		std::string const		_target;
};

#endif
