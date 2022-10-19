/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 03:58:59 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"

void	tryIncDecfonctions(Bureaucrat &b)
{
	std::cout << b << std::endl;
	try
	{
		b.incrementGrade(300);
		std::cout << b.getName() << " is now grade "
		<< b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.decrementGrade(300);
		std::cout << b.getName() << " is now grade "
		<< b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.incrementGrade(41);
		std::cout << b.getName() << " is now grade "
		<< b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b.decrementGrade(149);
		std::cout << b.getName() << " is now grade "
		<< b.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	oneExceptionIsCatched(void)
{
	std::cout << std::endl;
	try
	{
		Bureaucrat c;	
		c.incrementGrade(151);
		c.decrementGrade(151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Only first exception is catched" << std::endl;
}

void	whatGotRewritedAnyway(Bureaucrat &c)
{
	int	n = 200;
	try
	{
		c.incrementGrade(n);
		c.decrementGrade(150);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Grade too High" << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Grade too Low" << std::endl;
	}
} 
/* but you can make a difference with variouses catchs 		 */
/* It also makes a lot of sense you can only get the first   */
/* one, for exeptions are made to stop at the first error    */

void	someOtherTests(void)
{
	try
	{
		Bureaucrat HardTry = Bureaucrat("Jaques", 1234566);
		std::cout << "test0passed" << std::endl;
		Bureaucrat HarderTry = Bureaucrat("Jaques", 150 + 3);
		std::cout << "test1passed" << std::endl;
		Bureaucrat EvenMore("MORE", 1);
		Bureaucrat Lastone = ++EvenMore;
		std::cout << "if this is printed, you're in trouble"
		<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "It is handled in an ok way" << std::endl;
	}
}

int		main(void)
{
	Bureaucrat	a;
	Bureaucrat	b("Jean");
	Bureaucrat	c = b;
	Bureaucrat	d("Jaques", 1);

	std::cout << b.getName() << std::endl;
	std::cout << b << std::endl;
	try
	{
		std::cout << "try to demote " << a.getName() << std::endl;
		--a;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "try to promote " << d.getName() << std::endl;
		++d;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "New Bureaucrat whit a low grade : " << std::endl;
	try
	{
		Bureaucrat	a("Paul", 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "New Bureaucrat whit a high grade : " << std::endl;
	try
	{
		Bureaucrat	a("Paul", 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "(¯`·._.· Testing Incrementation and Decrementation fonctions"
	"  ·._.·´¯)" << std::endl;
	tryIncDecfonctions(b);
	std::cout << std::endl;
	std::cout << "(¯`·._.· A few tests that helped me understand how"
	" exceptions are working ·._.·´¯)" << std::endl;
	oneExceptionIsCatched();
	std::cout << std::endl;
	whatGotRewritedAnyway(c);
	std::cout << std::endl;
	std::cout << "(¯`·._.· Last Ones ·._.·´¯)" << std::endl;
	someOtherTests();
	return (0);
}
