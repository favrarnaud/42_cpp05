/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afavre <afavre@student.42lausanne>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:37:13 by afavre            #+#    #+#             */
/*   Updated: 2023/10/12 16:37:15 by afavre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../include/Aform.hpp"

class presidentialPardonForm: public Aform
{
public :
	presidentialPardonForm();
	presidentialPardonForm(std::string const &name);
	~presidentialPardonForm();

	void sign();
	void exec(bureaucrat &data);

	//Override
	void beSigned(bureaucrat &data);
	void beExecuted(bureaucrat &data);
};

std::ostream& operator<<(std::ostream& os, const presidentialPardonForm& obj);

#endif
