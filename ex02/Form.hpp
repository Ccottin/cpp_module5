/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/16 07:29:05 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>
# include <exception>

class	Bureaucrat;

class	AForm {

	public :
		
		AForm(void);
		AForm(std::string const name, std::string const target,
				bool form, int const gradeToSign,
				int const gradeToExecute);
		AForm(AForm const &ref);
		AForm &operator=(AForm const &ref);
		virtual ~AForm(void);

		std::string const	&getName(void) const;
		std::string	const	&getTarget(void) const;
		bool				getForm(void) const;
		int 				getToSign(void) const;
		int					getToExecute(void) const;

		virtual void		beSigned(Bureaucrat const &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

	/* Exceptions */

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char * what() const throw() {
				return ("Form's grade is too high");
			}
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char * what() const throw() {
				return ("Form's or else's grade is too low");
			}
	};

	class	AlreadySignedException : public std::exception
	{
		public :
			virtual const char * what() const throw() {
				return ("Form is already signed");
			}
	};

	class NotSignedException : public std::exception 
	{
		public :
			virtual const char *what() const throw() {
				return ("Unsigned forms cannot be "
				"executed"); 
			}
	};


	protected :

	void				setForm(const bool);

	private :

		std::string const	_name;
		std::string	const	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

		std::ostream	&operator<<(std::ostream &stream,
							AForm const &ref);
#endif
