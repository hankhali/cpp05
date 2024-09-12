/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:59:34 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/12 20:00:43 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern::~Intern() {};

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = {"shrubbery request", "robotomy request", "presidential request"};
	AForm* forms[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};
	int i = -1;
	while (++i < 3) {
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}
	std::cout << "Form not found" << std::endl;
	return NULL;
}