/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:26:09 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/19 17:19:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <string>
#include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
	private:
		enum e_level
		{
    		DEBUG,
			INFO,
			WARNING,
			ERROR	
		};
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
		typedef	void (Harl::*_f) (void);
};

#endif
