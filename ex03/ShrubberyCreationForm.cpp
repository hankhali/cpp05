/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:40:48 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 15:39:05 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &t)
{
	_target = t._target;
	return (*this);
}

void ShrubberyCreationForm::function() const
{
	std::string namef;
	namef = _target + "_shrubbery";
	const char* char_array = namef.c_str();
	std::fstream fs;
	fs.open(char_array, std::fstream::in | std::fstream::out | std::fstream::app);
	fs << 	"              * *\n"
	"           *    *  *\n"
	"      *  *    *     *  *\n"
	"     *     *    *  *    *\n"
	" * *   *    *    *    *   *\n"
	" *     *  *    * * .#  *   *\n"
	" *   *     * #.  .# *   *\n"
	"  *     \"#.  #: #\" * *    *\n"
	" *   * * \"#. ##\"       *\n"
	"   *       \"###\n"
	"             \"##\n"
	"              ##.\n"
	"              .##:\n"
	"              :###\n"
	"              ;###\n"
	"            ,####.\n"
	"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n"<< std::endl;
	fs.close();
}

int	ShrubberyCreationForm::grade()
{
	if (this->getExec() < 137)
	{
		throw ShrubberyCreationForm::GradeTooHighException();
		return (-1);
	}
	else if (this->getReq() > 145)
	{
		throw ShrubberyCreationForm::GradeTooLowException();
		return (-1);
	}
	return (this->getExec());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    // Optional: Clean up any resources if necessary
}