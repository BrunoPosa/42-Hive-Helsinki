/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:51:49 by bposa             #+#    #+#             */
/*   Updated: 2025/02/22 23:36:20 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

using std::string;
using std::cout;
using std::endl;

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(const ScavTrap& obj);
	ScavTrap&	operator=(const ScavTrap& obj);
	~ScavTrap();
	ScavTrap(const string& name);

	void	attack(const string& target) override;
	void	guardGate();
};

#endif