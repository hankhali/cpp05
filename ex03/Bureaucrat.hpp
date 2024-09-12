/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:37:02 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/11 21:49:33 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <new>
#include "AForm.hpp"

class AForm;
class Bureaucrat {
	protected:
	const std::string _name;
	int	_grade;
	public:

	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat &operator=(Bureaucrat &t);
	~Bureaucrat();

	        class GradeTooLowException: public std::exception {
            public :
                virtual const char *what() const throw();
        };
        class GradeTooHighException: public std::exception {
            public :
                virtual const char *what() const throw();
        };
	int	grade();
	std::string getName() const;
	int getGrade() const;
	void	increaseGrade();
	void	descreaseGrade();
	void	signForm(AForm &f);
	void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &os, Bureaucrat &t);

#endif