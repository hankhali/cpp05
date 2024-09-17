/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:40:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 15:38:07 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main() {
    Intern intern;

    // Example of creating forms using the intern
    AForm* shrubbery = intern.makeForm("shrubbery request", "Home");
    if (shrubbery) {
        std::cout << shrubbery->getName() << " form created!" << std::endl;
    }

    AForm* robotomy = intern.makeForm("robotomy request", "Bender");
    if (robotomy) {
        std::cout << robotomy->getName() << " form created!" << std::endl;
    }

    AForm* pardon = intern.makeForm("presidential request", "Arthur Dent");
    if (pardon) {
        std::cout << pardon->getName() << " form created!" << std::endl;
    }

    // Test an invalid form creation
    AForm* invalidForm = intern.makeForm("invalid request", "Nobody");
    if (invalidForm == NULL) {
        std::cout << "Failed to create invalid form." << std::endl;
    }

    // Don't forget to delete the created forms to avoid memory leaks
    delete shrubbery;
    delete robotomy;
    delete pardon;

    return 0;
}
