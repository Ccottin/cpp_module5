/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 02:42:01 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat " << _name << " got recruted "
	" at grade " << _grade << " and everybody feels sorry "
	"for him" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name) : _name(name),
	_grade(150)
{
	std::cout << "Bureaucrat " << _name << " got recruted "
	" at grade " << _grade << " and everybody feels sorry "
	"for him" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade)
	: _name(name), _grade(grade)
{	
	if (grade > _Lowest)
		throw GradeTooLowException();
	else if (grade < _Highest) 
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << _name << " got recruted "
	" at grade " << _grade << " and everybody feels sorry "
	"for him" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) : _name(ref.getName())
{
	*this = ref;
	std::cout << "Bureaucrat " << _name << " got a copy of"
	" himself" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << _name << " got fired"
	<< std::endl;
}

/* Operators Overload */

Bureaucrat 	&Bureaucrat::operator=(Bureaucrat const &ref)
{
	if (this != &ref)
		this->_setGrade(ref.getGrade());
	std::cout << "Bureaucrat " << _name << " constructs"
	" a copy of himself" << std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream,
		Bureaucrat const &ref)
{
	stream << ref.getName() << ", bureaucrat grade "
	<< ref.getGrade() << "." << std::endl;
	return (stream);
}

Bureaucrat	&Bureaucrat::operator++(void)
{
	if (_grade - 1 < _Highest)
		throw GradeTooHighException();
	else
		(this->_grade)--;
	return (*this);
}

Bureaucrat	&Bureaucrat::operator--(void)
{
	if (_grade + 1 > _Lowest)
		throw GradeTooLowException();
	else
		(this->_grade)++;
	return (*this);
}

/* Accessors */

std::string const	Bureaucrat::getName(void) const
{
	return (_name);
}

int					Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void				Bureaucrat::_setGrade(int const i)
{
	if (i > _Lowest)
		throw GradeTooLowException();
	else if (i < _Highest) 
		throw GradeTooHighException();
	else
		_grade = i;
}

/* Exceptions */

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high");
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low");
}

/* Member fonctions */

void			Bureaucrat::incrementGrade(int const i)
{
	if (_grade - i < _Highest)
		throw GradeTooHighException();
	_setGrade(_grade - i);
}

void			Bureaucrat::decrementGrade(int const i)
{
	if (_grade + i > _Lowest)
		throw GradeTooLowException();
	_setGrade(_grade + i);

}
