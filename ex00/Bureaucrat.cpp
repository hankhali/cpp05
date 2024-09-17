/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:36:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 18:53:27 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat:: Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
    if (this->grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat " << this->name << " copied" << std::endl;
}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increment()
{
    this->grade -= 1;
    if (this->grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decrement()
{
    this->grade += 1;
    if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high exception: grade < 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low exception: grade > 150";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}
