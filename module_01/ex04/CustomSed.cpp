/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomSed.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:21:07 by wportilh          #+#    #+#             */
/*   Updated: 2023/02/22 11:15:51 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomSed.hpp"

CustomSed::CustomSed(void)
{
	return ;	
}

CustomSed::~CustomSed(void)
{
	return ;
}

void	CustomSed::_replace_line(std::string &line, std::string const s1,
													std::string const s2)
{
	size_t	pos = 0;
	size_t	s1_lenght;

	while (pos != std::string::npos)
	{
		s1_lenght = s1.length();
		pos = line.find(s1);
		if (pos != std::string::npos)
		{
			line.erase(pos, s1_lenght);
			line.insert(pos, s2);
		}
	}
}

void	CustomSed::_send_text_output(std::string const filename,
										std::string const line)
{
	std::ofstream	outfile;

	outfile.open(filename.c_str(), std::ofstream::trunc);
	if (!outfile.is_open())
		std::cerr << "replace: error: file creation or opening" << std::endl;
	outfile << line;
	outfile.close();
}

void	CustomSed::replace(std::string const filename, std::string const s1,
													std::string const s2)
{
	std::ifstream	infile;
	std::string		line;
	std::string		all_text;

	if (filename.empty() || s1.empty())
	{
		std::cerr << "replace: error: the first and/or second argument are/is empty"
		<< std::endl;
		return ;
	}
	infile.open(filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "replace: error: cannot open the file" << std::endl;
		return ;
	}
	while (getline(infile, line))
	{
		_replace_line(line, s1, s2);
		all_text += line;
		if (!infile.eof())
			all_text += '\n';
	}
	_send_text_output(filename + ".replace", all_text);
	infile.close();
}
