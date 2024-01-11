/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:39:27 by afavre            #+#    #+#             */
/*   Updated: 2023/10/11 13:39:29 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Aform.hpp"

class form;

bureaucrat::bureaucrat()
{
	this->name = "default";
	 this->rank = 150;
}

bureaucrat::bureaucrat(std::string const &name, int rank): name(name), rank(rank)
{
	if (rank < 1)
		throw bureaucrat::GradeTooHighException();
	if (rank > 150)
		throw bureaucrat::GradeTooLowException();
	std::cout << this->name << " a rejoint notre entreprise ! souhaitez lui la bienvenue !" << std::endl;
}

bureaucrat::~bureaucrat()
{
	std::cout << this->name << " a posé sa démission." << std::endl;
}

std::string bureaucrat::getName() const
{
	return (this->name);
}

int  bureaucrat::getRank() const
{
	return (this->rank);
}

//COPLIEN FORM
bureaucrat::bureaucrat(bureaucrat &src)
{
	*this = src;
}

bureaucrat &bureaucrat::operator=(bureaucrat const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = copy.name + "_copy";
	this->rank = copy.rank;
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const bureaucrat& obj)
{
	os << "Nom du bureaucrate: " << obj.getName() << ", Rang du bureaucrat: " << obj.getRank();
	return os;
}

