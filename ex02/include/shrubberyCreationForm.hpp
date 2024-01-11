/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:32 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:34 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../include/Aform.hpp"

class shrubberyCreationForm: public Aform
{
	public :
		shrubberyCreationForm();
		shrubberyCreationForm(std::string const &name);
		~shrubberyCreationForm();

		void sign();
		void exec(bureaucrat &data);

		//Override
		void beSigned(bureaucrat &data);
		void beExecuted(bureaucrat &data);
};

std::ostream& operator<<(std::ostream& os, const shrubberyCreationForm& obj);

#endif

