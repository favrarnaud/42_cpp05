/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:32:45 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 14:32:47 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

#include "bureaucrat.hpp"

class bureaucrat;

class form {
	public :
		form();
		form(std::string const &name, int reqGradeSign, int reqGradeExec);
		~form();
		std::string getName() const;
		int getSignGrade() const;
		int getExecGrade() const;
		bool getStatus() const;
		void beSigned(bureaucrat &data);

		//COPLIEN FORM
		form(form &src);
		form &operator=(form const &copy);
	private :
		const std::string name;
		bool sign;
		int reqGradeSign;
		int reqGradeExec;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Le rang du form ne peut pas etre supérieur a 1.";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Le rang du form ne peut pas etre inférieur a 150.";
		}
	};
	class CantSignForm : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Le bureaucrat n'est pas asser haut en rang pour le signer !";
		}
	};
};
std::ostream& operator<<(std::ostream& os, const form& obj);
#endif
