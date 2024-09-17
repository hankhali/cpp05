/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:37:02 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 20:12:20 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        Bureaucrat();
    
    public:
        Bureaucrat(const std::string _name, int _grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        void signForm(Form fr);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw();
                
        };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs);
