/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:19:50 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/17 22:22:15 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOMSED_H
# define CUSTOMSED_H

#include <iostream>
#include <fstream>

class	CustomSed
{
	public:
		CustomSed(void);
		~CustomSed(void);
		void			replace(std::string const filename,
								std::string const s1,
								std::string const s2);
	private:
		void			_replace_line(std::string &line,
										std::string const s1,
										std::string const s2);
		void				_send_text_output(std::string const filename,
												std::string const line,
												std::string const s1,
												std::string const s2);
};

#endif
