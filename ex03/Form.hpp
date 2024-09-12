/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:38:30 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/10 18:39:54 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <new>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
	const std::string _name;
	bool	_sign;
	const int _req;
	const int _exec;
	public:

	Form();
	Form(const std::string name, const int _req, const int _exec);
	Form &operator=(Form &t);
	~Form();

	        class GradeTooLowException: public std::exception {
            public :
                virtual const char *what() const throw();
        };
        class GradeTooHighException: public std::exception {
            public :
                virtual const char* what() const throw();
        };
	int	grade();
	const std::string getName();
	int getSign();
	void beSigned(Bureaucrat &b);
	int getExec();
	int getReq();
};

std::ostream& operator<<(std::ostream &os, Form &t);
