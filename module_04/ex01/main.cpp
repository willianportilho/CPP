/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/03 16:29:02 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Brain	teste;
	Brain	teste2;


	for(int i = 0; i < 100; i++)
		teste.setIdeas("Testando", i);
	teste2 = teste;
	for(int i = 0; i < 100; i++)
	{
		std::cout << "1 = " << teste.getIdeas(i) << std::endl;
		std::cout << "2 = " << teste2.getIdeas(i) << std::endl;
	}
	return (0);
}
