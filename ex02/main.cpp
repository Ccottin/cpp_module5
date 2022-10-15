/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/15 01:25:52 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test2(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	Form		bb("LaisserPasserA38", 42, 6);
	
	try
	{
		bb.beSigned(a);
		a.signForm(bb.getName());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		a.signForm(bb.getName(), e.what());
	}
	tr
	{
		bb.beSigned(b);
		b.signForm(bb.getName());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		b.signForm(bb.getName(), e.what());
	}
	try
	{
		bb.beSigned(c);
		c.signForm(bb.getName());
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		c.signForm(bb.getName(), e.what());
	}

}

void	test1(void)
{
	Bureaucrat	a = Bureaucrat("Alfred");
	Bureaucrat	b("Jean", 42);
	Bureaucrat	c("Jaques", 1);

	Form		aa;
	
	std::cout << aa << std::endl;
	
	try
	{
		aa.beSigned(a);
		a.signForm(aa.getName());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		a.signForm(aa.getName(), e.what());
	}
	try
	{
		aa.beSigned(b);
		b.signForm(aa.getName());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		b.signForm(aa.getName(), e.what());
	}
	try
	{
		aa.beSigned(c);
		c.signForm(aa.getName());
	}	
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		c.signForm(aa.getName(), e.what());
	}

	std::cout << aa << std::endl;
}

int	main(void)
{
	test1();
	std::cout << std::endl;
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
	return (0);
}
