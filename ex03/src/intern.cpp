/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:42 by afavre            #+#    #+#             */
/*   Updated: 2024/01/09 14:42:43 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/intern.hpp"
#include "../include/shrubberyCreationForm.hpp"
#include "../include/robotomyRequestForm.hpp"
#include "../include/presidentialPardonForm.hpp"

intern::intern() {
	std::cout << "creation d'un interne" << std::endl;
}

intern::~intern() {
	std::cout << "licenciement d'un interne" << std::endl;
}

Aform* intern::makeForm(std::string type, std::string name)
{
	if (type == "robotomy request")
		return new robotomyRequestForm(name);
	else if (type == "pardon request")
		return new presidentialPardonForm(name);
	else if (type == "shrubberry request")
		return new shrubberyCreationForm(name);
	else
		throw intern::creationErrorException();

}

//COPLIEN FORM
intern::intern(intern &src)
{
	*this = src;
}

intern &intern::operator=(intern const &copy)
{
	if (this != &copy) {}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const intern &obj)
{
	(void)obj;
	os << "Ceci est un intern ! " << std::endl;
	return os;
}
