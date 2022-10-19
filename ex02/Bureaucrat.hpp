/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/19 21:39:12 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <string>
# include <iostream>
# include <exception>

class	AForm;

class	Bureaucrat {

	public :
		
		Bureaucrat(void);
		Bureaucrat(std::string const name);
		Bureaucrat(std::string const name, int const grade);
		Bureaucrat(Bureaucrat const &ref);
		Bureaucrat &operator=(Bureaucrat const &ref);
		virtual ~Bureaucrat(void);

		std::string const	getName(void) const;
		int 				getGrade(void) const;

		Bureaucrat			&operator++(void);
		Bureaucrat			&operator--(void);

		
		void				incrementGrade(int const i);
		void				decrementGrade(int const i);
		void				signForm(AForm & form) const;
		void				executeForm(AForm const & form);
			
	/* Exceptions */

	class	GradeTooHighException : public std::exception
	{ virtual const char * what() const throw(); };

	class	GradeTooLowException : public std::exception
	{ virtual const char * what() const throw(); };

	protected :

	private :

		std::string const	_name;
		int					_grade;
		static const int	_Highest = 1;
		static const int	_Lowest = 150;
		void				_setGrade(int const);
};

		std::ostream	&operator<<(std::ostream &stream,
							Bureaucrat const &ref);
#endif
