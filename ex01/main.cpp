/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:40:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 20:14:44 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    // Bureaucrat();
    try {
        std::cout << "Creating a valid Bureaucrat and Form..." << std::endl;
        Bureaucrat john("John", 4);
        Form validForm("ValidForm", 150, 3); //sign grade execute grade
        std::cout << john.getName() << " with grade " << john.getGrade() << " has been created." << std::endl;
        std::cout << "Form " << validForm.getName() << " requires signing grade " << validForm.getReq()
                  << " and execution grade " << validForm.getExec() << "." << std::endl;

        std::cout << "John tries to sign the valid form..." << std::endl;
        validForm.beSigned(john);
        std::cout << "Form successfully signed by " << john.getName() << std::endl;

        john.signForm(validForm);
    } catch (const std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try 
    {
        std::cout << "\nCreating an invalid Form with a sign grade of 151..." << std::endl;
        Form invalidForm("InvalidForm", 151, 3);
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}


//if the signing grade is greater than 150 it is too low
//                        les than 1 then it is too high 
