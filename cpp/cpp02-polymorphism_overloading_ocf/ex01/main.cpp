/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:40:18 by bposa             #+#    #+#             */
/*   Updated: 2025/02/02 11:17:48 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main (void) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	cout << "a is " << a << endl;
	cout << "b is " << b << endl;
	cout << "c is " << c << endl;
	cout << "d is " << d << endl;

	cout << "a is " << a.toInt() << " as integer" << endl;
	cout << "b is " << b.toInt() << " as integer" << endl;
	cout << "c is " << c.toInt() << " as integer" << endl;
	cout << "d is " << d.toInt() << " as integer" << endl;

	return 0;
}
