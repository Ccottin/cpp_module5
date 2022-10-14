/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:58:25 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/14 05:14:41 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

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
		void				setGrade(int const);

		Bureaucrat			&operator++(void);
		Bureaucrat			&operator--(void);

		
		void				incrementGrade(int const i);
		void				decrementGrade(int const i);
		void				signForm(std::string const name);
		void				signForm(std::string const name,
								std::string const reason);

	/* Exceptions */

	class	GradeTooHighException : public std::exception
	{
		public :
			virtual const char * what() const throw() {
				return ("Bureaucrat's grade is too high");
			}
	};

	class	GradeTooLowException : public std::exception
	{
		public :
			virtual const char * what() const throw() {
				return ("Bureaucrat's grade is too low");
			}
	};

	protected :

	private :

		std::string const	_name;
		int					_grade;
		static const int	_Highest = 1;
		static const int	_Lowest = 150;
};

		std::ostream	&operator<<(std::ostream &stream,
							Bureaucrat const &ref);
#endif
