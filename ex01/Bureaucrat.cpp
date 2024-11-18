#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat:: Bureaucrat(const std::string _name, int _grade) : name(_name), grade(_grade)
{
    if (this->grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat " << this->name << " destroyed " << std::endl;
    
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increment()
{
    this->grade -= 1;
    if (this->grade < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
}

void Bureaucrat::decrement()
{
    this->grade += 1;
    if (this->grade > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high exception: grade < 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low exception: grade > 150";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;
}

void Bureaucrat::signForm(Form fr) {
    if (fr.getSign() == 1) {
        std::cout << name << " signed " << fr.getName() << std::endl;
    }
    else
        std::cout << name << " couldn’t sign " << fr.getName() << " because Bureaucrat grade is not high enough." << std::endl;
}

