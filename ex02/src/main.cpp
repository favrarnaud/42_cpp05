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
#include "../include/shrubberyCreationForm.hpp"
#include "../include/robotomyRequestForm.hpp"
#include "../include/presidentialPardonForm.hpp"

int main()
{
	try {
		bureaucrat a("arnaud", 1);

//		// AFORM VERIFICATION
//		std::cout << std::endl << "----- verification de la class abstraite -----" << std::endl;
//		try {
//			Aform b("not valid", 20, 30);
//			try {
//				b.beSigned(a);
//				try {
//					b.beExecuted(a);
//				} catch (std::exception &e) {
//					std:: cout << e.what() << std::endl;
//				}
//			} catch (std::exception &e) {
//				std:: cout << e.what() << std::endl;
//			}
//		}
//		catch (std::exception &e) {
//			std:: cout << e.what() << std::endl;
//		}

		// unsigned form
		std::cout << std::endl << "----- test d'un formulaire non signe -----" << std::endl;
		try {
			presidentialPardonForm b("error form");
			try {
				b.beExecuted(a);
			} catch (std::exception &e) {
				std:: cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std:: cout << e.what() << std::endl;
		}

		// PRESIDENTIAL PARDON FORM
		std::cout << std::endl << "----- test du presidential pardon form -----" << std::endl;
		try {
			presidentialPardonForm b("presidential pardon");
			try {
				b.beSigned(a);
				try {
					b.beExecuted(a);
				} catch (std::exception &e) {
					std:: cout << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std:: cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std:: cout << e.what() << std::endl;
		}

		// ROBOTOMY REQUEST FORM
		std::cout << std::endl << "----- test du robotomy request form -----" << std::endl;
		try {
			robotomyRequestForm b("robotomy request");
			try {
				b.beSigned(a);
				try {
					b.beExecuted(a);
				} catch (std::exception &e) {
					std:: cout << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std:: cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std:: cout << e.what() << std::endl;
		}

		// SHRUBBERRY CREATION FORM
		std::cout << std::endl << "----- test du shrubberry creation form -----" << std::endl;
		try {
			shrubberyCreationForm b("shrubberry creation");
			try {
				b.beSigned(a);
				try {
					b.beExecuted(a);
				} catch (std::exception &e) {
					std:: cout << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std:: cout << e.what() << std::endl;
			}
		}
		catch (std::exception &e) {
			std:: cout << e.what() << std::endl;
		}

	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
