/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:37 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 14:32:39 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Aform.hpp"

Aform::Aform() {}

Aform::~Aform() {
	std::cout << "Le formulaire " << this->getName() << " a été détruit !" << std::endl;
}

std::string Aform::getName() const {
	return this->name;
}

void Aform::setName(std::string pname) {
	this->name = pname;
}

int Aform::getSignGrade() const {
	return this->reqGradeSign;
}

void Aform::setSignGrade(int psignGrade) {
	this->reqGradeSign = psignGrade;
}

int Aform::getExecGrade() const {
	return this->reqGradeExec;
}

void Aform::setExecGrade(int pExecGrade) {
	this->reqGradeExec = pExecGrade;
}

bool Aform::getStatus() const {
	return this->sign;
}

void Aform::setStatus(bool pstatus) {
	this->sign = pstatus;
}

//COPLIEN FORM
Aform::Aform(Aform &src)
{
	*this = src;
}

Aform &Aform::operator=(Aform const &copy)
{
	if (this != &copy) {
		this->reqGradeSign = copy.reqGradeSign;
		this->reqGradeExec = copy.reqGradeExec;
		this->sign = copy.sign;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Aform & obj)
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
