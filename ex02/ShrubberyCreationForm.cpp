/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:48 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 21:59:39 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("ShrubberyCreationForm", "Target", false, 145, 137)
{
	std::cout << getName() << " created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", target, false, 145, 137)
{
	std::cout << getName() << " created" << std::endl;
}

ShrubberyCreationForm::
ShrubberyCreationForm(ShrubberyCreationForm const &ref) :
	AForm(ref.getName(), ref.getTarget(),  ref.getForm(), 145, 137)
{
	std::cout << "ShrubberyCreationForm " << ref.getName()
	<< " created with a photocopier" << std::endl;
}

ShrubberyCreationForm
&ShrubberyCreationForm::operator=(ShrubberyCreationForm
			const &ref)
{
	std::cout << "ShrubberyCreationForm " << ref.getName()
	<< " calls copy operator" << std::endl;
	if (this != &ref)
		this->setForm(ref.getForm());
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Trees from " << getName() << " form got harvested" << std::endl;
}

void	ShrubberyCreationForm::execute
			(Bureaucrat const & executor) const
{
	std::ofstream	file;
	std::string		name = getTarget() + "_shrubbery";

	if (this->getForm() != true)
		throw NotSignedException();
	if (executor.getGrade() > this->getToExecute())
		throw GradeTooLowException();
	try
	{
		file.open(name.c_str());
		file.write("\n                    / / /\n"
"                   /        /  /     / /   /\n"
"                /                 /         /  /\n"
"                                /\n"
"                               /               / /\n"
"               /          /            /              /\n"
"               /            '/,        /               /\n"
"               /              'b      *\n"
"                /              '$    / /              / /\n"
"               /    /           $:   /:               /\n"
"            / /      / / /      * /  @):       /   / /\n"
"                          /     :@,@):   ,/**:'   /\n"
"              /      /,         :@@*: / /**'     /   /\n"
"                       '/o/    /:(@'/@**'''  /\n"
"               /  /       'bq, /:,@@*'   ,*      /  /\n"
"                          ,p$q8,:@)'  /p*'      /\n"
"                   /     '  / '@@Pp@@*'    /  /\n"
"                    /  / / /   Y7'.'     /  /\n"
"                              :@):.\n"
"                             .:@:'.\n"
"                           .::(@:. \n"
"                         .::::(@:. \n", 1024);
		file.close();
	}
	catch (std::exception &e)
	{
		if (file.is_open())
			file.close();
		std::cout << e.what() << std::endl;
		throw e;
	}
}
