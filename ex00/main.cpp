/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 18:36:42 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/17 12:08:30 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() 
{
    try 
    {
        Bureaucrat john("John", 1);
        std::cout << john << std::endl;

        john.increment();
        std::cout << john << std::endl;

        john.increment(); // This should throw an exception
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        Bureaucrat jane("Jane", 148);
        std::cout << jane << std::endl;

        jane.decrement();
        std::cout << jane << std::endl;

        jane.decrement(); // This should throw an exception
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
