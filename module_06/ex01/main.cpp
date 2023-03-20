/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:02:42 by wportilh          #+#    #+#             */
/*   Updated: 2023/03/20 10:12:04 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	uintptr_t	serialized_test;
	Data		*deserialized_test;
	Data		*test = new Data;

	test->number = 42;
	test->string = "42SP";
	serialized_test = Serializer::serialize(test);
	deserialized_test = Serializer::deserialize(serialized_test);

	std::cout << "                     test = " << test					<< std::endl;
	std::cout << "        deserialized test = " << deserialized_test	<< std::endl;
	std::cout << "             test->number = " << test->number			<< std::endl;
	std::cout << "deserialized_test->number = " << test->number			<< std::endl;
	std::cout << "             test->string = " << test->string			<< std::endl;
	std::cout << "deserialized_test->string = " << test->string			<< std::endl;
	std::cout << "serialized_test (uintptr) = " << serialized_test		<< std::endl;

	delete test;

	return (0);
}
