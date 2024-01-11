/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:40 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:42 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/presidentialPardonForm.hpp"

presidentialPardonForm::presidentialPardonForm() {}

presidentialPardonForm::presidentialPardonForm(std::string const &name) {
	this->setName(name);
	this->setSignGrade(25);
	this->setExecGrade(5);
	this->setStatus(false);
	std::cout << "Le formulaire " << this->getName() << " a été édité !" << std::endl;
}

presidentialPardonForm::~presidentialPardonForm() {}

void presidentialPardonForm::beSigned(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		sign();
		this->setStatus(true);
	}
	else
		throw CantSignForm();
}

void presidentialPardonForm::beExecuted(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		if (!this->getStatus())
			throw notSigned();
		else
			exec(data);
	}
	else
		throw CantExecForm();
}

std::ostream& operator<<(std::ostream& os, const presidentialPardonForm& obj)
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

void presidentialPardonForm::sign() {
	std::cout << "\"" << this->getName() << " \"" << " signed !" << std::endl;
}

void presidentialPardonForm::exec(bureaucrat &data) {
	std::cout << data.getName() << " a ete pardonne de son erreur ! felicitation a toi !" <<std::endl;
}
