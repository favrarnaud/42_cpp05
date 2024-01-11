/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:57 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:58 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

#include "../include/shrubberyCreationForm.hpp"

shrubberyCreationForm::shrubberyCreationForm() {}

shrubberyCreationForm::shrubberyCreationForm(std::string const &name) {
	this->setName(name);
	this->setSignGrade(145);
	this->setExecGrade(137);
	this->setStatus(false);
	std::cout << "Le formulaire " << this->getName() << " a été édité !" << std::endl;
}

shrubberyCreationForm::~shrubberyCreationForm() {}

void shrubberyCreationForm::beSigned(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		sign();
		this->setStatus(true);
	}
	else
		throw CantSignForm();
}

void shrubberyCreationForm::beExecuted(bureaucrat &data) {
	if (data.getRank() <= this->getSignGrade()) {
		if (!this->getStatus())
			throw notSigned();
		else
			exec(data);
	}
	else
		throw CantExecForm();
}

std::ostream& operator<<(std::ostream& os, const shrubberyCreationForm& obj)
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

void shrubberyCreationForm::sign() {
	std::cout << "\"" << this->getName() << " \"" << " signed !" << std::endl;
}

void shrubberyCreationForm::exec(bureaucrat &data) {
	std::ofstream file(data.getName() + "_Shrubberry.txt");
	file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
	file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
	file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
	file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
	file << "              (_)  \\.-'.-/" << std::endl;
	file << "          __...--- |'-.-'| --...__" << std::endl;
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
	file << " -\"    ' .  . '    |.'-._| '  . .  '   " << std::endl;
	file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
	file << "          ' ..     |'-_.-|" << std::endl;
	file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
	file << "              .'   |'- .-|   '." << std::endl;
	file << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
	file << "   .-' '        '-._______.-'     '  ." << std::endl;
	file << "        .      ~," << std::endl;
	file << "    .       .        .    ' '-." << std::endl;
	file.close();
}