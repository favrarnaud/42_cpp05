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

#include "bureaucrat.hpp"
#include "form.hpp"

int main()
{
	// boucle valide
	try {
		bureaucrat a("arnaud", 2);
		std::cout << a << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Création d'un formulaire valide" << std::endl;
	try {
		form form("ducon", 5, 50);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	// erreurs de grade dans les forms
	std::cout << std::endl << "Création de formulaires avec gradeSign too low" << std::endl;
	try {
		form form("too high grade for sign", 151, 50);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Création de formulaires avec gradeSign too high" << std::endl;
	try {
		form form("too high grade for sign", 0, 50);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl << "Création de formulaires avec gradeExec too low" << std::endl;
	try {
		form form("too high grade for sign", 10, 151);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Création de formulaires avec gradeExec too high" << std::endl;
	try {
		form form("too high grade for sign", 10, 0);
		std::cout << form << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl << std::endl;
	}

	//test des signature
	std::cout << "signature possible" << std::endl;
	try {
		bureaucrat bc("ducon", 1);
		try {
			form form("lajoie", 5, 50);
			try {
				bc.signForm(form);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout <<std::endl << "signature impossible" << std::endl;
	try {
		bureaucrat bc("ducon", 10);
		try {
			form form("lajoie", 5, 50);
			try {
				bc.signForm(form);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
