/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 22:04:16 by bposa             #+#    #+#             */
/*   Updated: 2025/03/29 19:42:05 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm; //Forward declaration to avoid circular dependency

#define REDISH "\033[1;31m"
#define YELLOWISH "\033[33m"
#define GREENISH "\033[1;32m"
#define RESETISH "\033[0m"

/**
 *	Default constructor sets _name to 'JohnDoe' and _grade to worst grade.
 *	Best grade is 1, worst 150;
 *	upGrade() decrements _grade and downGrade() increments it.
 *
 *	Special exceptions: GradeTooHighException and GradeTooLowException.
 */
class Bureaucrat {
	const std::string			_name;
	unsigned short				_grade;
	static const unsigned short	_bestGrade	= 1;
	static const unsigned short	_worstGrade	= 150;
	static_assert(_bestGrade < _worstGrade, "Best grade must be less than worst grade");//delete for production code

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat&	operator=(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat(const std::string& name, unsigned short grade);

	const std::string&	getName()	const noexcept;
	unsigned short		getGrade()	const noexcept;
	void	upGrade();		//--grade (3 becomes 2)
	void	downGrade();	//++grade (3 becomes 4)
	void	signForm(AForm& obj) const;
	bool	executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
