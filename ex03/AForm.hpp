/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:23:56 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 15:38:46 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

 #include <iostream>
 #include <string>
 #include "Bureaucrat.hpp"
 

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _sign;
        const int _req;
        const int _exec;
    
    public:
        AForm();
        AForm(const std::string name, const int req, const int exec);
        AForm &operator=(AForm &t);
        virtual ~AForm();

            class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooHighException: public std::exception
        {
            public: 
                virtual const char *what() const throw();
        };
        int grade();
        const std::string getName() const;
        int getSign();
        void beSigned(Bureaucrat &b);
        int getExec();
        virtual void function() const = 0;
        int getReq();
        void execute(Bureaucrat const & executor)const;
};

std::ostream& operator<<(std::ostream &os, AForm &t);