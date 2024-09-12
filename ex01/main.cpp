/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankhali <hankhali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:40:59 by hankhali          #+#    #+#             */
/*   Updated: 2024/09/10 19:16:54 by hankhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
   Bureaucrat test("test", 4);

    test.increment();
    try {
        Form testform("formTest", 1, 3);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}