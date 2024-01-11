/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:22 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:24 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "../include/Aform.hpp"

class robotomyRequestForm: public Aform
{
public :
	robotomyRequestForm();
	robotomyRequestForm(std::string const &name);
	~robotomyRequestForm();

	void sign();
	void exec();

	//Override
	void beSigned(bureaucrat &data);
	void beExecuted(bureaucrat &data);
};

std::ostream& operator<<(std::ostream& os, const robotomyRequestForm& obj);

#endif
