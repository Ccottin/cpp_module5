/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:48 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 22:08:44 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("RobotomyRequestForm", "Target", false, 72, 45)
{
	std::cout << getName() << " created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", target, false, 72, 45)
{
	std::cout << getName() << " created" << std::endl;
}

RobotomyRequestForm::
RobotomyRequestForm(RobotomyRequestForm const &ref) :
	AForm(ref.getName(), ref.getTarget(), ref.getForm(), 72, 45)
{
	std::cout << "RobotomyRequestForm " << ref.getName()
	<< " created with a photocopier" << std::endl;
}

RobotomyRequestForm
&RobotomyRequestForm::operator=(RobotomyRequestForm
			const &ref)
{
	std::cout << "RobotomyRequestForm " << ref.getName()
	<< " calls copy operator" << std::endl;
	if (this != &ref)
		this->setForm(ref.getForm());
	return (*this);
}
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << getName() << " will robotomise "
	<< getTarget() << " no more!" << std::endl;
}

void	RobotomyRequestForm::execute
			(Bureaucrat const & executor) const
{
	if (this->getForm() != true)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();
	std::cout << "*BrZZzzZZZzZRrrrZzzzT BrRbRZZzzzzzzzZZzT*"
	<< std::endl;
	if (rand() % 2 == 1)
	{
		std::cout << getTarget() << " got successfully "
		<< "robotomised" << std::endl;
	}
	else
	{
		std::cout << getTarget() << " could not have been "
		<< "robotomised :(" << std::endl;
	}
}
