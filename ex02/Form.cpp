/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:19:51 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 19:28:18 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name ("default"),  _req(42), _exec(42)
{

}

AForm::~AForm()
{

}

AForm::AForm(const std::string name, const int req, const int exec) : _name (name), _req(req), _exec(exec)
{
	if (req > 150 || exec > 150)
		throw AForm::GradeTooLowException();
	else if (exec < 1 || req < 1)
		throw AForm::GradeTooHighException();
	else
		_sign = 0;
}

AForm &AForm::operator=(AForm &t)
{
	this->_sign = t._sign;
	(std::string)this->_name = t._name;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, AForm &t)
{
	// os = NULL;
	os << t.getName() << " Current sign "<< t.getSign() << "1 : can be signed" << "0 : cant be signed" << " requiered : " << t.getReq() << " grade exec : " << t.getExec() << std::endl;
	return os;
}

int	AForm::grade()
{
	if (this->_req > 150 || this->_exec > 150)
	{
		throw AForm::GradeTooLowException();
		return (-1);
	}
	else if (this->_req < 1 || this->_exec < 1)
	{
		throw AForm::GradeTooHighException();
		return (-1);
	}
	return (this->_req);
}

const char* AForm::GradeTooHighException:: what() const throw()
{
	return "AForm Grade is too high !";
}

const char* AForm::GradeTooLowException:: what() const throw()
{
	return "AForm Grade is too low !";
}

const std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSign()
{
	return (this->_sign);
}

int AForm::getExec()
{
	return (this->_exec);
}

int AForm::getReq()
{
	return (this->_req);
}


void AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() > this->_req) {  // If the grade is too low for signing
        throw AForm::GradeTooLowException();
    } else {
        this->_sign = true;  // Mark the form as signed
    }
}



void AForm::execute(Bureaucrat const &executor) const {
    if (!_sign) {
        throw std::runtime_error("Form is not signed.");  // Prevent execution if not signed
    } else if (executor.getGrade() > this->_exec) {
        throw AForm::GradeTooLowException();  // Prevent execution if grade is too low
    } else {
        this->function();  // Call the form-specific function
    }
}

