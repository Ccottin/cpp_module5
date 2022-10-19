/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/20 00:50:04 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string>
#include <iostream>
#include "Intern.hpp"

Intern::Intern(void) 
{
	std::cout << "A new intern got recruted and nobody "
	"cares" << std::endl;
}

/*interns are basically all the same...*/

Intern::Intern(Intern const &ref)
{
	(void)ref;
	std::cout << "A new intern got a copy of himself "
	"and nobody cares" << std::endl;
}

Intern 	&Intern::operator=(Intern const &ref) 
{
	(void)ref;
	std::cout << "Intern constructs a copy of himself"
	<< std::endl;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "An intern got fired"
	<< std::endl;
}

ShrubberyCreationForm	*returnSCF(std::string target)
{
	ShrubberyCreationForm *ret = new ShrubberyCreationForm(target);
	return (ret);
}

RobotomyRequestForm		*returnRRF(std::string target)
{
	RobotomyRequestForm *ret = new RobotomyRequestForm(target);
	return (ret);

}

PresidentialPardonForm	*returnPPF(std::string target)
{
	PresidentialPardonForm *ret = new PresidentialPardonForm(target);
	return (ret);
}

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	tab[3] = {
					"shrubbery creation",
					"robotomy request",
					"presidential pardon"
					};
	int	i;

	for (i = 0; i < 3; i++)
	{
		if (!tab[i].compare(name))
			break ;
	}
	switch (i)
	{
		case 0 :
			return (returnSCF(target));
		case 1 :
			return (returnRRF(target));
		case 2 :
			return (returnPPF(target));
		default :
			throw WrongNameException();
	}
}

/* an exeption is thrown here event if its not asked in subject, */
/* as you will need to try/catch this fonction anyway for malloc */
/* safety. If you considers this as incorrect, please accept     */
/* this piece of code instead line 86 :							 */
/* 		default :												 */
/*			std::cout << Form name is not valid << std::endl;	 */
/*			return (NULL);										 */
/* a null pointer will then be returned, and to free memory		 */
/* properly you would need to test Form's value. If it is		 */
/* non-null, use delete operator, else don't					 */

const char * Intern::WrongNameException::what() const throw()
{
				return ("Form name is not valid");
}
