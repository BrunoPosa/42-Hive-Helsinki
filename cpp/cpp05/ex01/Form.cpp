/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:44:49 by bposa             #+#    #+#             */
/*   Updated: 2025/03/28 19:20:31 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;

/*	Orthodox Canonical Form	*/
Form::Form() : _name("JohnDoe"), _signed(false), _signGrade(1), _execGrade(1) {}

Form::Form(const Form& obj)
	: _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {}

Form&	Form::operator=(Form const &obj) {
	if (this != &obj) {
		_signed = obj._signed;
		cout << "Aform copy assignment operator." << endl;
	}
	return *this;
}

Form::~Form() {	cout << "Aform def. destructor" << endl;	}




/*	Constructor Overload	*/
Form::Form(const string& name, unsigned short signGrade, unsigned short execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (signGrade < _bestGrade || execGrade < _bestGrade) {
		throw GradeTooHighException();
	}
	else if (signGrade > _worstGrade || execGrade > _worstGrade) {
		throw GradeTooLowException();
	}
}




/*	Member Functions	*/

const string&	Form::getName()			const noexcept {	return _name;	}
bool			Form::getSigned()		const noexcept {	return _signed;	}
unsigned short	Form::getSignGrade()	const noexcept {	return _signGrade;	}
unsigned short	Form::getExecGrade()	const noexcept {	return _execGrade;	}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_signed = true;
}

const char*	Form::GradeTooHighException::what() const noexcept {	return "Signer's grade too high!";	}

const char*	Form::GradeTooLowException::what() const noexcept {	return "Signer's grade too low!";	}




/*	Insertion operator overload	*/
std::ostream&	operator<<(std::ostream& os, const Form& obj) {
	return os
		<< "Form: " << obj.getName() << ", "
		<< "Sign Grade: " << obj.getSignGrade() << ", "
		<< "Execution Grade: " << obj.getExecGrade() << ", "
		<< "Signed: " << obj.getSigned()
		<< endl;
}
