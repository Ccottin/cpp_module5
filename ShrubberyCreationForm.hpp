/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:48 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/14 06:17:58 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	Form("Default", false, 145, 137)
{
	std::cout << "ShrubberyCreationForm " << _name
	<< " created" << std::endl;
}

ShrubberyCreationForm::
ShrubberyCreationForm(ShrubberyCreationForm const &ref) :

{
	std::cout << "ShrubberyCreationForm " << _name
	<< " created with a photocopier" << std::endl;
}
ShrubberyCreationForm::
ShrubberyCreationForm &operator=(ShrubberyCreationForm
			const &ref)
{

}
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}
