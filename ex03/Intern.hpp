/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/18 02:03:26 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

# include <string>
# include <iostream>
# include <exception>

class	AForm;

class	Intern {

	public :
		
		Intern(void);
		Intern(Intern const &ref);
		Intern &operator=(Intern const &ref);
		virtual ~Intern(void);

		AForm	*makeForm(std::string name,
				std::string target) const;

		/* Exceptions */

	class	WrongNameException : public std::exception
	{
		public :
			virtual const char * what() const throw();
	};

	protected :

	private :

};

#endif
