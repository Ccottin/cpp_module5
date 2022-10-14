/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/14 03:28:10 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

void	tryIncDecfonctions(Bureaucrat &b)
{
	try
	{
		b.incrementGrade(300);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.decrementGrade(300);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b.getGrade() << std::endl;
	try
	{
		b.decrementGrade(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << b.getGrade() << std::endl;
}

void	oneExceptionIsCatched(Bureaucrat &c)
{
	std::cout << std::endl;
	try
	{
		c.setGrade(151);
		c.setGrade(0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	whatGotRewritedAnyway(Bureaucrat &c)
{
	try
	{
		c.setGrade(151);
		c.setGrade(0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade too High" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Grade too Low" << std::endl;
	}
} 
/* but you can still make a difference with variouses catchs */
/* It also makes a lot of sense you can only get the first   */
/* one, for exeptions are made to stop at the first error    */

void	inConstructor(void)
{
	Bureaucrat	a("Paul", 151);
}

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("Jean");
	Bureaucrat	c = b;
	Bureaucrat	d("Jaques", 1);

	std::cout << b.getName() << std::endl;
	std::cout << b << std::endl;
	b.setGrade(42);
	std::cout << b << std::endl;
	try
	{
		--a;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << a << " is alread"
		"y at lower level!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		++d;
	}
	catch (std::exception &e)
	{
		std::cout << "Bureaucrat " << d << " is alread"
		"y at higher level!" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		inConstructor();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	oneExceptionIsCatched(c);
	std::cout << std::endl;
	whatGotRewritedAnyway(c);
	std::cout << std::endl;
	tryIncDecfonctions(b);
	std::cout << std::endl;
	return (0);
}
