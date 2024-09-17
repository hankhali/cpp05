/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:40:48 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 22:13:03 by hankhali         ###   ########.fr       */
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
    if (this != &t) 
        _target = t._target; 
    return *this;
}

void ShrubberyCreationForm::function() const {
    std::string filename = _target + "_shrubbery";  // Create the file name
    std::ofstream outFile(filename.c_str());  // Open file for writing

    if (!outFile) {  // Check if the file was opened successfully
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    // Write ASCII tree into the file
    outFile << "              * *\n"
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
               "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";

    outFile.close();  // Close the file after writing
    std::cout << "Shrubbery has been created in file: " << filename << std::endl;
}


int	ShrubberyCreationForm::grade()
{
	if (this->getExec() < 137)
	{
		throw ShrubberyCreationForm::GradeTooHighException();
	}
	else if (this->getReq() > 145)
	{
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	return (this->getExec());
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}

//Sign Grade: 145
//Execution Grade: 137
