/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:48 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/15 06:11:23 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.cpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Default", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm " << _name
	<< " created" << std::endl;
}

ShrubberyCreationForm::
ShrubberyCreationForm(ShrubberyCreationForm const &ref) :
	Form("Default", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm " << _name
	<< " created with a photocopier" << std::endl;
	this = &ref;
}
ShrubberyCreationForm::
ShrubberyCreationForm &operator=(ShrubberyCreationForm
			const &ref)
{
	if (this != &ref)
		this->_signed = ref.getForm();
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	"Trees from " << _name << " form got harvested" << std::endl;
}

void	plantAscii(std::name target);
{
	std::ofstream	file;
	std::string		name = target + "_shrubbery";

	try
	{
		file.open(name.c_str());
		file.write
	}
	catch (std::exection &e)
	{
		std::cout << e.what() << std::endl;
	}
}
