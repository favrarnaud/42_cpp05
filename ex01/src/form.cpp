/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:37 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 14:32:39 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"

form::form() {}

form::form(std::string const &name, int reqGradeSign, int reqGradeExec): name(name), reqGradeSign(reqGradeSign), reqGradeExec(reqGradeExec)
{
	if (reqGradeSign < 1)
		throw form::GradeTooHighException();
	if (reqGradeSign > 150)
		throw GradeTooLowException();
	if (reqGradeExec < 1)
		throw form::GradeTooHighException();
	if (reqGradeExec > 150)
		throw GradeTooLowException();
	this->sign = false;
	std::cout << "Le formulaire " << this->getName() << " a été édité !" << std::endl;
}

form::~form() {
	std::cout << "Le formulaire " << this->getName() << " a été détruit !" << std::endl;
}

std::string form::getName() const {
	return this->name;
}

int form::getSignGrade() const {
	return this->reqGradeSign;
}

int form::getExecGrade() const {
	return this->reqGradeExec;
}

bool form::getStatus() const {
	return this->sign;
}

void form::beSigned(bureaucrat &data)
{
	if (data.getRank() <= this->getSignGrade()) {
		this->sign = true;
	}
	else
		throw CantSignForm();
}


//COPLIEN FORM
form::form(form &src)
{
	*this = src;
}

form &form::operator=(form const &copy)
{
	if (this != &copy) {
		this->reqGradeSign = copy.reqGradeSign;
		this->reqGradeExec = copy.reqGradeExec;
		this->sign = copy.sign;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const form& obj)
{
	os
	<< "Nom : "
	<< obj.getName()
	<< ", Rang nécéssaire a la signature : "
	<< obj.getSignGrade()
	<< ", Rang nécéssaire a l'éxécution : "
	<< obj.getExecGrade()
	<< ", signé : "
	<< obj.getStatus();
	return os;
}
