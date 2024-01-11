/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:48 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:50 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <random>

#include "../include/robotomyRequestForm.hpp"

robotomyRequestForm::robotomyRequestForm() {}

robotomyRequestForm::robotomyRequestForm(std::string const &name) {
	this->setName(name);
	this->setSignGrade(72);
	this->setExecGrade(45);
	this->setStatus(false);
	std::cout << "Le formulaire " << this->getName() << " a été édité !" << std::endl;
}

robotomyRequestForm::~robotomyRequestForm() {}

void robotomyRequestForm::beSigned(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		sign();
		this->setStatus(true);
	}
	else
		throw CantSignForm();
}

void robotomyRequestForm::beExecuted(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		if (!this->getStatus())
			throw notSigned();
		else
			exec();
	}
	else
		throw CantExecForm();
}

std::ostream& operator<<(std::ostream& os, const robotomyRequestForm& obj)
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

void robotomyRequestForm::sign() {
	std::cout << "\"" << this->getName() << " \"" << " signed !" << std::endl;
}

void robotomyRequestForm::exec() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist100(1,100);

	std::cout << "grrrrl, grrrrrrl, bizzz, bzzzzi" << std::endl;
	if (dist100(rng) >= 50)
		std::cout << "la robotomy a ete realise avec succes !" << std::endl;
	else
		std::cout << "l'operation a ete un echec ! fuyez avant que ca n'explose !" << std::endl;
}

