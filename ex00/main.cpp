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
