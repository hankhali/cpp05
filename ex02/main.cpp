/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:40:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 15:29:48 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Create a high-ranking bureaucrat
        Bureaucrat john("John", 4);
        std::cout << john << std::endl;

        // Create forms
        AForm *shrubberyForm = new ShrubberyCreationForm("Home");
        AForm *robotomyForm = new RobotomyRequestForm("Robot");
        AForm *pardonForm = new PresidentialPardonForm("Arthur Dent");

        // Signing forms with John
        std::cout << "\nSigning forms with John:\n";
        john.signForm(*shrubberyForm);   // John attempts to sign ShrubberyCreationForm
        john.signForm(*robotomyForm);    // John attempts to sign RobotomyRequestForm
        john.signForm(*pardonForm);      // John attempts to sign PresidentialPardonForm

        // Executing forms with John
        std::cout << "\nExecuting forms with John:\n";
        try {
            john.executeForm(*shrubberyForm);  // John attempts to execute ShrubberyCreationForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            john.executeForm(*robotomyForm);   // John attempts to execute RobotomyRequestForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            john.executeForm(*pardonForm);     // John attempts to execute PresidentialPardonForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        // New low-ranking bureaucrat (failure case)
        Bureaucrat lowRank("LowRank", 150);
        std::cout << "\nLowRank is " << lowRank.getGrade() << "/150\n";

        // Attempt to sign forms with LowRank
        std::cout << "\nSigning forms with LowRank (should fail):\n";
        try {
            lowRank.signForm(*shrubberyForm);   // LowRank tries to sign ShrubberyCreationForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;  // This should print an error
        }

        try {
            lowRank.signForm(*robotomyForm);    // LowRank tries to sign RobotomyRequestForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;  // This should print an error
        }

        try {
            lowRank.signForm(*pardonForm);      // LowRank tries to sign PresidentialPardonForm
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;  // This should print an error
        }

        // Cleanup
        delete shrubberyForm;
        delete robotomyForm;
        delete pardonForm;
    } 
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
 