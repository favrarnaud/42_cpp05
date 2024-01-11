/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:27:13 by afavre            #+#    #+#             */
/*   Updated: 2023/10/11 13:27:15 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bureaucrat.hpp"

int main()
{
	std::cout << "--- Creation d'un bureaucrate valide ---" << std::endl;
	try {
		bureaucrat a("arnaud", 2);
		std::cout << a <<  std::endl;
		std::cout << "check des fonction increment et decrement" << std::endl;
		try {
			a.incrementGrade();
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			a.decrementGrade();
			std::cout << a << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << "--- Creation d'un bureaucrate avec un grade trop bas ---" << std::endl;
	try {
		bureaucrat a("charlotte", 151);
		std::cout << a <<  std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "--- Creation d'un bureaucrate avec un grade trop haut ---" << std::endl;
	try {
		bureaucrat a("didier", 0);
		std::cout << a <<  std::endl << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
}
