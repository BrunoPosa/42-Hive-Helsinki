/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:41:21 by bposa             #+#    #+#             */
/*   Updated: 2025/03/31 16:53:59 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::string;

/*	Orthodox Canonical Form	*/
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	cout << "Shrubbery def. constructor" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), _target(obj._target) {
	cout << "Shrubbery copy constructor" << endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this != &obj) {
		_target = obj._target;
		cout << "Shrubbery copy assignment" << endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	cout << "Shrubbery def. destructor" << endl;
}




/*	Overload	*/
ShrubberyCreationForm::ShrubberyCreationForm(const string& target)
	:	AForm("ShrubberyCreationForm", 145, 137),
		_target(_validateTarget(target))
{
	cout << "Shrubbery overloaded constructor" << endl;
}




/*	Methods	(member functions)	*/
bool	ShrubberyCreationForm::act() const {
	std::ofstream outFile(_target + "_shrubbery", std::ios::out | std::ios::trunc);
	if (!outFile.is_open()) {
		cout << "Could not open file!" << endl;
		return false;
	}

	int	i = _target.length();
	do {
		outFile << R"(
			# #### ####
		### \/#|### |/####
		##\/#/ \||/##/_/##/_#
		###  \/###|/ \/ # ###
	##_\_#\_\## | #/###_/_####
	## #### # \ #| /  #### ##/##
	__#_--###`  |{,###---###-~
				\ }{
				}}{
				}}{
			ejm  {{}
		, -=-~{ .-^- _
				`}
				{)";
		if (outFile.fail()) {
			cout << "Writing failed!" << endl;
			return false;
		}
	} while (--i > 0);

	cout << GREENISH << "Shrubbery planted in " << _target << "_shrubbery." << RESETISH << endl;
	return true;
}

string	ShrubberyCreationForm::_validateTarget(const string& target) {
	if (target.length() + 10 > 255) {
		throw std::invalid_argument("Target must be < 245 characters!");
	}
	const string	disallowed = "/\\?%*:|\"<>'`$&;!{}[]()#@+=~^, \t\n";
	if (target.find_first_of(disallowed) != string::npos) {
		throw std::invalid_argument("Invalid characters detected! Avoid \\t, \\n and these:/\\?%*:|\"<>'`$&;!{}[]()#@+=~^, \t\n");
	}
	return target;
}

