/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:57:36 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/18 05:28:04 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	testppf(void)
{
	Intern	ImNotSureWeHiredThisGuy;
	Intern	OneMoreIntern(ImNotSureWeHiredThisGuy);
	AForm	*ppf;
	bool	alloc = false;

	try
	{
		ppf = OneMoreIntern.makeForm("presidential pardon", "YourLogin");
		alloc = true;
		Bureaucrat Jaques("Jaques", 5);
		ppf->beSigned(Jaques);
		ppf->execute(Jaques);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (alloc)
		delete ppf;
}
void	testrrf(void)
{
	Intern	random;
	Intern	AnotherRandom = random;
	AForm	*rrf;
	bool	alloc = false;

	try
	{
		rrf = random.makeForm("robotomy request", "ccottin");
		alloc = true;
		Bureaucrat Georges("Georges", 45);
		rrf->beSigned(Georges);
		rrf->execute(Georges);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (alloc)
		delete rrf;
}

void	testscf(void)
{
	Intern	random;
	AForm	*scf;
	bool	alloc = false;

	try
	{
		scf = random.makeForm("shrubbery creation", "spacial void");
		alloc = true;
		Bureaucrat Jean("Jean", 137);
		scf->beSigned(Jean);
		scf->execute(Jean);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	if (alloc)
		delete scf;
}

int	main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		bool	success = false;
		try
		{
			rrf = someRandomIntern.makeForm("robotomy request",
				"Bender");
			success = true;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		if (success)
		{
			delete rrf;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	testscf();
	std::cout << std::endl;
	std::cout << std::endl;
	testrrf();
	std::cout << std::endl;
	std::cout << std::endl;
	testppf();
	return (0);
}
