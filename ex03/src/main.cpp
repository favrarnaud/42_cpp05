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
#include "../include/intern.hpp"

int main()
{
	try {
		bureaucrat a("arnaud", 1);
		intern i;

		try {
			Aform* b;
			try {
				b = i.makeForm("robotomy request", "burp");
				try {
					b->beSigned(a);
					try {
						b->beExecuted(a);
					} catch (std::exception &e) {
						std:: cout << e.what() << std::endl;
					}
				} catch (std::exception &e) {
					std:: cout << e.what() << std::endl;
				}
			} catch (std::exception &e) {
				std:: cout << e.what() << std::endl;
			}
			delete(b);
		} catch (std::exception &e) {
			std:: cout << e.what() << std::endl;
		}
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}
