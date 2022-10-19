/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 22:02:16 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>
#include <iostream>

AForm::AForm(void) : _name("Default"), _target("target"),
					_signed(false), _gradeToSign(150),
					_gradeToExecute(150)
{
	std::cout << "Form " << _name << " got created "
	"(Form default constructor)" << std::endl;
}

AForm::AForm(std::string const name,
				std::string const target,
				bool form,
				int const gradeToSign,
				int const gradeToExecute) : _name(name),
					_target(target),
					_signed(form),
					_gradeToSign(gradeToSign),
					_gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw	GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw	GradeTooHighException();
	std::cout << "Form " << _name << " got created "
	"(Form constructor)" << std::endl;
}

AForm::AForm(AForm const &ref) : _name(ref.getName()),
						_target(ref.getTarget()),
						_signed(ref.getForm()),
						_gradeToSign(ref.getToSign()),
						_gradeToExecute(ref.getToExecute())
{
	std::cout << "Form " << _name << " got created again"
	<< std::endl;
}

AForm::~AForm(void)
{
	std::cout << "Form " << _name << " went to trash"
	<< std::endl;
}

/* Operators Overload */

AForm 	&AForm::operator=(AForm const &ref)
{
	if (this != &ref)
		this->_signed = ref.getForm();
	std::cout << "Form " << _name << " got copied"
	<< std::endl;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream,
		AForm const &ref)
{
	stream << ref.getName() << " : form with "
	<< ref.getTarget() << " target needs a bureaucrat "
	"grade "  << ref.getToSign() << " to be signed or "
	<< ref.getToExecute() << " to be executed and is currently";
	if (ref.getForm() == true)
		stream << " signed" << std::endl;
	else	
		stream << " not signed" << std::endl;
	return (stream);
}

/* Exceptions */

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Form's grade is too low");
}

const char * AForm::AlreadySignedException::what() const throw()
{
	return ("Form is already signed");
}

const char * AForm::NotSignedException::what() const throw()
{
	return ("Unsigned forms cannot be executed"); 
}

/* Accessors */

std::string const	&AForm::getName(void) const
{
	return (_name);
}

std::string	const	&AForm::getTarget(void) const
{
	return (_target);
}
bool				AForm::getForm(void) const
{
	return (_signed);
}

int					AForm::getToSign(void) const
{
	return (_gradeToSign);
}

int					AForm::getToExecute(void) const
{
	return (_gradeToExecute);
}

void				AForm::setForm(const bool b)
{
	this->_signed = b;
}

/* Member fonctions */

void				AForm::beSigned(Bureaucrat const &b) 
{
	if (_signed == true)
		throw AlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}
