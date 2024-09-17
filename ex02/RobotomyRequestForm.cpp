/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:31:04 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 22:15:52 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &t)
{
    if (this != &t)
        _target = t._target;
    return *this;
}

void RobotomyRequestForm::function() const 
{
    static int counter = 0;

    std::cout << "* drilling noises *" << std::endl;
    if (counter % 2 == 0) {  // 50% chance, alternating between success and failure
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }

    counter++;  // Increment the counter for the next function call
}


int	RobotomyRequestForm::grade()
{
	if (this->getExec() < 45)
	{
		throw RobotomyRequestForm::GradeTooHighException();
		return (-1);
	}
	else if (this->getReq()> 72)
	{
		throw RobotomyRequestForm::GradeTooLowException();
		return (-1);
	}
	return (this->getExec());
}

RobotomyRequestForm::~RobotomyRequestForm() {
    // Destructor implementation
}

//Sign Grade: 72
//Execution Grade: 45