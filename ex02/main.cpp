/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 21:57:57 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

/*	this test battery is good to go for all forms type, just	*/
/*	change every occurences to another							*/

void	test2(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	RobotomyRequestForm	aa;
	
	std::cout << aa << std::endl;
	
	std::cout << a.getName() << " try to sign form "
	<< aa.getName() << std::endl;
	a.signForm(aa);
		
	std::cout << b.getName() << " try to sign form "
	<< aa.getName() << std::endl;
	b.signForm(aa);
	
	std::cout << c.getName() << " try to sign form "
	<< aa.getName() << std::endl;
	c.signForm(aa);
	
	std::cout << std::endl;
	std::cout << aa << std::endl;
		
	std::cout << a.getName() << " try to execute form "
	<< aa.getName() << std::endl;
	a.executeForm(aa);
	
	std::cout << b.getName() << " try to execute form "
	<< aa.getName() << std::endl;
	b.executeForm(aa);
		
	std::cout << c.getName() << " try to execute form "
	<< aa.getName() << std::endl;
	c.executeForm(aa);
}

void	test1(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	RobotomyRequestForm	aa("Eden");
	
	std::cout << aa << std::endl;
	
	try
	{
		std::cout << a.getName() << " try to sign form "
		<< aa.getName() << std::endl;
		aa.beSigned(a);
		std::cout << "Success!" << std::endl;
		
	}
	catch (std::exception &e)
	{
		
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << b.getName() << " try to sign form "
		<< aa.getName() << std::endl;
		aa.beSigned(b);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << c.getName() << " try to sign form "
		<< aa.getName() << std::endl;
		aa.beSigned(c);
		std::cout << "Success!" << std::endl;
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << aa << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << a.getName() << " try to execute form "
		<< aa.getName() << std::endl;
		aa.execute(a);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << b.getName() << " try to execute form "
		<< aa.getName() << std::endl;
		aa.execute(b);
		std::cout << "Success!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << c.getName() << " try to execute form "
		<< aa.getName() << std::endl;
		aa.execute(c);
		std::cout << "Success!" << std::endl;
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

int	main(void)
{
	{

		Bureaucrat a("Bureacrat", 142);
		RobotomyRequestForm casic("cible");

		try
		{
			casic.execute(a);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		a.executeForm(casic);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	test1();
	std::cout << std::endl;
	std::cout << "Now testing with Bureaucrats'"
	" functions" << std::endl;
	test2();
	std::cout << std::endl;
	return (0);
}
