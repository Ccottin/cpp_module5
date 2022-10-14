/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccottin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 05:53:33 by ccottin           #+#    #+#             */
/*   Updated: 2022/10/14 06:06:27 by ccottin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

class ShrubberyCreationForm: public ShrubberyCreationForm {

	public :

		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &ref);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm
			const &ref);
		virtual ~ShrubberyCreationForm(void);

#endif
