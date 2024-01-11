/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:39:13 by afavre            #+#    #+#             */
/*   Updated: 2023/10/11 13:39:14 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class form;

class bureaucrat {
public :
	bureaucrat();
	bureaucrat(std::string const &name, int rank);

	~bureaucrat();

	std::string getName() const;
	int getRank() const;

	void signForm(form &data);
	void incrementGrade();
	void decrementGrade();

	//COPLIEN FORM
	bureaucrat(bureaucrat &src);
	bureaucrat &operator=(bureaucrat const &copy);

private :
	const std::string name;
	int rank;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Le rang du bureaucrat ne peut pas etre supérieur a 1.";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Le rang du bureaucrat ne peut pas etre inférieur a 150.";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const bureaucrat& obj);

#endif

