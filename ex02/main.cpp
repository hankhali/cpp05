/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:40:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/11 21:49:52 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main ()
{
   Bureaucrat test("test", 4);

    test.increaseGrade();
    std::cout << test << std::endl;
    AForm *testform = new PresidentialPardonForm("Home");
    AForm *testform1 = new RobotomyRequestForm("robot");
    // testform->function();
    testform1->beSigned(test);
    testform->beSigned(test);
    test.signForm(*testform);
    test.signForm(*testform1);
    try
    {
        {/* code */
            test.executeForm(*testform);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try {
    Bureaucrat test1("hey", -2);
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    // std::cout << test1 << std::endl;
    std::cout << test.getName() << std::endl;
}