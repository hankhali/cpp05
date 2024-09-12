/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:00:15 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/11 21:50:30 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &t)
{
	_target = t._target;
	return (*this);
}

void PresidentialPardonForm::function() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

int	PresidentialPardonForm::grade()
{
	if (this->getExec() < 5)
	{
		throw PresidentialPardonForm::GradeTooHighException();
		return (-1);
	}
	else if (getReq()> 25)
	{
		throw PresidentialPardonForm::GradeTooLowException();
		return (-1);
	}
	return (this->getExec());
}