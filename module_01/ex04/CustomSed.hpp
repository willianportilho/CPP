/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:19:50 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 16:13:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOMSED_H
# define CUSTOMSED_H

#include <iostream>

class	CustomSed
{
	public:
		CustomSed(void);
		~CustomSed(void);
		void	replace(std::string const filename, \
						std::string const s1, std::string const s2);
};

#endif
