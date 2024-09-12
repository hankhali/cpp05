/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:05:00 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/10 20:08:41 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>
class PresidentialPardonForm : public AForm
{
    private : 
        std::string _target;
    
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm &operator=(PresidentialPardonForm &t);
        ~PresidentialPardonForm();
        void function() const;
        int grade();
};
