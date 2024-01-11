/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:45 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 14:32:47 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

#include "bureaucrat.hpp"

class bureaucrat;

class Aform {
	public :
		Aform();
		~Aform();

		//Getters
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getStatus() const;

		//Setters
		void setName(std::string name);
		void setSignGrade(int psignGrade);
		void setExecGrade(int pExecGrade);
		void setStatus(bool status);

		//COPLIEN FORM
		Aform(Aform &src);
		Aform &operator=(Aform const &copy);

		//Virtual pure
		virtual void beSigned(bureaucrat &data) = 0;
		virtual void beExecuted(bureaucrat &data) = 0;
	protected :
		class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Le rang du form ne peut pas etre supérieur a 1.";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "Le rang du form ne peut pas etre inférieur a 150.";
			}
		};
		class CantSignForm : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Le bureaucrat n'est pas asser haut en rang pour signer le formulaire !";
			}
		};
		class CantExecForm : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Le bureaucrat n'est pas asser haut en rang pour executer le formulaire !";
			}
		};
		class notSigned : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "L'execution de ce formulaire na pas ete approuve !";
			}
		};
	private :
		std::string name;
		bool sign;
		int reqGradeSign;
		int reqGradeExec;
};
std::ostream& operator<<(std::ostream& os, const Aform& obj);
#endif
