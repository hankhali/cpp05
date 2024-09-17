/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:59:34 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 15:42:48 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
    const std::string formNames[3] = {"shrubbery request", "robotomy request", "presidential request"};
    AForm* form = NULL;
    if (formName == formNames[0])
        form = new ShrubberyCreationForm(target);
    else if (formName == formNames[1]) 
        form = new RobotomyRequestForm(target);
    else if (formName == formNames[2])
        form = new PresidentialPardonForm(target);
    
    if (form) 
    {
        std::cout << "Intern creates " << formName << std::endl;
        return form;
    }
    std::cout << "Form not found: " << formName << std::endl;
    return NULL;
}

