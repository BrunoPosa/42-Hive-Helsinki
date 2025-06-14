/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:23:23 by bposa             #+#    #+#             */
/*   Updated: 2025/06/06 16:28:54 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

using std::string;
using std::cout;
using std::endl;

namespace {

	void	_convertChar(unsigned int type, const string& lit, double *value);
	void	_convertInt(unsigned int type, const string& lit, double *value);
	void	_convertFloat(unsigned int type, const string& lit, double *value);
	void	_convertDouble(unsigned int type, const string& lit, double *value);

	enum LiteralType {
		TYPE_CHAR = 0,
		TYPE_INT,
		TYPE_FLOAT,
		TYPE_DOUBLE,
		TYPE_INVALID
	};

	void (*_typeConverter[4])(unsigned int type, const string& literal, double *value) = {
		_convertChar,
		_convertInt,
		_convertFloat,
		_convertDouble
	};

	string _toLower(const string& lit) {
		string s = lit;
		for (char& ch : s)
			if (ch >= 'A' && ch <= 'Z')
				ch += ('a' - 'A');
		return s;
	}

	bool	isSpecialDouble(const string& lit) {
		string	lower = _toLower(lit);
		if (lower == "nan" || lower == "+nan" || lower == "-nan" ||
			lower == "inf" || lower == "+inf" || lower == "-inf") {
			return true;
		}
		return false;
	}

	LiteralType _detectType(const string& lit) {
		if (	(lit.length() == 1 && !std::isdigit(lit.at(0)))
			||	(lit.length() == 3 && lit.front() == '\'' && lit.back() == '\'')) {
			return TYPE_CHAR;
		} else if (lit.empty() || lit.find_first_not_of("infaINFA-+.0123456789") != string::npos) {
			return TYPE_INVALID;
		} else if (isSpecialDouble(lit)) {
			return TYPE_DOUBLE;
		}

		try {
			size_t pos;
			std::stoi(lit, &pos);
			if (pos == lit.length()) { return TYPE_INT;	}
		} catch (std::exception&) {}

		if (lit.back() == 'f' || lit.back() == 'F') {
			try {
				size_t pos;
				std::stof(lit, &pos);
				if (pos == lit.length() - 1) { return TYPE_FLOAT; }
			} catch (std::exception&) {}
		}

		try {
			size_t pos;
			std::stod(lit, &pos);
			if (pos == lit.length()) { return TYPE_DOUBLE; }
		} catch (std::exception&) {}

		return TYPE_INVALID;
	}

	void	_convertChar(unsigned int type, const string& lit, double *value) {
		char	ch = 0;

		if (type == TYPE_CHAR) {
			ch = lit.length() == 3 ?
					lit.at(1)
				:	lit.at(0);
			*value = static_cast<double>(ch);
		} else {
			if (*value <= std::numeric_limits<char>::max() && *value >= std::numeric_limits<char>::min()) {
				ch = static_cast<char>(*value);
			} else {
				cout << "char  : impossible" << endl;
				return;
			}
		}
		if (std::isprint(ch)) {
			cout << "char  : '" << ch << "'" << endl;
		} else {
			cout << "char  : Non displayable!" << endl;
		}
	}

	void	_convertInt(unsigned int type, const string& lit, double *value) {
		int	n = 0;

		if (type == TYPE_INT) {
			n = std::stoi(lit);
			*value = static_cast<double>(n);
		} else {
			if (*value <= std::numeric_limits<int>::max() && *value >= std::numeric_limits<int>::min()) {
				n = static_cast<int>(*value);
			} else {
				cout << "int   : impossible" << endl;
				return;
			}
		}
		cout << "int   : " << n << endl;
	}

	void	_convertFloat(unsigned int type, const string& lit, double *value) {
		float	f = 0.0f;

		if (type == TYPE_FLOAT) {
			f = std::stof(lit);
			*value = static_cast<double>(f);
		} else {
			if ((*value <= std::numeric_limits<float>::max() && *value >= std::numeric_limits<float>::lowest())
			|| isSpecialDouble(lit)) {
				f = static_cast<float>(*value);
			} else {
				cout << "float : impossible" << endl;
				return;
			}
		}
		cout << "float : " << std::fixed << f << "f" << endl;
	}

	void	_convertDouble(unsigned int type, const string& lit, double *value) {
		double	d = 0.0;

		if (type == TYPE_DOUBLE) {
			d = std::stod(lit);
			*value = d;
		} else {
			d = *value;
		}
		cout << "double: " << std::fixed << d << endl;
	}
}

void	ScalarConverter::convert(const string& literal) {
	try {
		double			value = 0;
		LiteralType		type = _detectType(literal);

		if (type == TYPE_INVALID) {
			cout	<< "char  : impossible\n"
					<< "int   : impossible\n"
					<< "float : impossible\n"
					<< "double: impossible" << endl;
		} else {
			for (int i = 0; i < 4; i++) {
				_typeConverter[(type + i) % 4](type, literal, &value);
			}
		}
	} catch (std::exception& e) {
		cout << YELLOWISH << "exception caugth: " << REDISH << e.what() << RESETISH << endl;
	}
}
