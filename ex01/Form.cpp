/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 04:22:08 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <iostream>

Form::Form(void) :	_name("Default"), _signed(false),
					_gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form " << _name << " got created" 
	<< std::endl;
}

Form::Form(std::string const name, int const gradeToSign,
			int const gradeToExecute) : _name(name),
					_signed(false),
					_gradeToSign(gradeToSign),
					_gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	std::cout << "Form " << _name << " got created"
	<< std::endl;
}

Form::Form(Form const &ref) : _name(ref.getName()),
						_signed(ref.getForm()),
						_gradeToSign(ref.getToSign()),
						_gradeToExecute(ref.getToExecute())
{
//	*this = ref;
	std::cout << "Form " << _name << " got created again"
	<< std::endl;
}

Form::~Form(void)
{
	std::cout << "Form " << _name << " went to trash"
	<< std::endl;
}

/* Operators Overload */

Form 	&Form::operator=(Form const &ref)
{
	if (this != &ref)
		this->_signed = ref.getForm();
	std::cout << "Form " << _name << " got copied"
	<< std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream,
		Form const &ref)
{
	stream << ref.getName() << " : form needs a bureaucrat "
	"grade "  << ref.getToSign() << " to be signed or "
	<< ref.getToExecute() << " to be executed and is currently";
	if (ref.getForm() == true)
		stream << " signed" << std::endl;
	else	
		stream << " not signed" << std::endl;
	return (stream);
}

/* Accessors */

std::string const	Form::getName(void) const
{
	return (_name);
}

bool				Form::getForm(void) const
{
	return (_signed);
}

int					Form::getToSign(void) const
{
	return (_gradeToSign);
}

int					Form::getToExecute(void) const
{
	return (_gradeToExecute);
}

/* Exceptions */

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Form's or else's grade is too low");
}

const char * Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

/* Member fonctions */

void				Form::beSigned(Bureaucrat const &b)
{
	if (_signed == true)
		throw AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
