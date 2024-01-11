/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:42:33 by afavre            #+#    #+#             */
/*   Updated: 2024/01/09 14:42:36 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "../include/Aform.hpp"

class intern {
	public:
		intern();
		~intern();
		Aform *makeForm(std::string type, std::string name);

		//COPLIEN FORM
		intern(intern &src);
		intern &operator=(intern const &copy);

	class creationErrorException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "l'intern na pas su quel formulaire creer !";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const intern& obj);

#endif
