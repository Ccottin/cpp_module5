/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/16 07:31:03 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm: public AForm {

	public :

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm
			const &ref);
		virtual ~ShrubberyCreationForm(void);
		
		virtual void	execute(Bureaucrat const & executor) const;

};

#endif
