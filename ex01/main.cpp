/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 04:33:26 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test3(void)
{
	Bureaucrat	g("Gerard", 24);
	Form		form("Another", 23, 1);

	(++g).signForm(form);
	++g;
	g.signForm(form);
	
}

void	test2(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	Form		bb("LaisserPasserA38", 42, 6);
	
	try
	{
		std::cout << a.getName() << " try to sign form "
		<< bb.getName() << std::endl;
		bb.beSigned(a);
		std::cout << "Success!" << std::endl;
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << b.getName() << " try to sign form "
		<< bb.getName() << std::endl;
		bb.beSigned(b);
		std::cout << "Success!" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << c.getName() << " try to sign form "
		<< bb.getName() << std::endl;
		bb.beSigned(c);
		std::cout << "Success!" << std::endl;
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}

void	test1(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	Form		aa("curvyForm", 43, 42);
	
	std::cout << aa << std::endl;
	
	a.signForm(aa);
	b.signForm(aa);
	c.signForm(aa);
	
	std::cout << aa << std::endl;
}

int	main(void)
{
	
	std::cout << "Test with Bureaucrats' functions : "
	"TryCatch is already implemented inside, so it is"
	"just a print" << std::endl;
	test1();
	std::cout << std::endl;
	std::cout << "Test with Forms' functions : they all"
	" throw an exeption so we'll need to TryCatch them"
	<< std::endl;
	test2();
	std::cout << std::endl;
	{
		try
		{
			Form	form("a", 7894, -456);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try
		{
			Form	formm("a", 1, -456);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	test3();	
	return (0);
}
