/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:45:11 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/19 19:21:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iostream>

class	Serializer
{
	public:
		~Serializer(void);
	private:
		Serializer(void);
		Serializer(Serializer const &src);
		Serializer	&operator=(Serializer const &rhs);
};

#endif
