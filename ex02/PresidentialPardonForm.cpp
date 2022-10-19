/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:48 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 21:59:12 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("PresidentialPardonForm", "Target", false, 25, 5)
{
	std::cout << getName() << " created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", target, false, 25, 5)
{
	std::cout << getName() << " created" << std::endl;
}

PresidentialPardonForm::
PresidentialPardonForm(PresidentialPardonForm const &ref) :
	AForm(ref.getName(), ref.getTarget(), ref.getForm(), 25, 5)
{
	std::cout << "PresidentialPardonForm " << ref.getName()
	<< " created with a photocopier" << std::endl;
}

PresidentialPardonForm
&PresidentialPardonForm::operator=(PresidentialPardonForm
			const &ref)
{
	std::cout << "PresidentialPardonForm " << ref.getName()
	<< " calls copy operator" << std::endl;
	if (this != &ref)
		this->setForm(ref.getForm());
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << getName() <<" is no longer forgiving "
	<< getTarget() << std::endl;
}

void	PresidentialPardonForm::execute
			(Bureaucrat const & executor) const
{
	if (this->getForm() != true)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();
	std::cout << "Zaphod Beeblebrox forgive "
	<< getTarget() << std::endl;	
}
