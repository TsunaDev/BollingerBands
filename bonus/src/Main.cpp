//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Main file
//

#include <iostream>
#include "Bollinger.hpp"

bool	isNumber(const string &s)
{
	return !s.empty() && s.find_first_not_of("0123456789.-") == string::npos;
}

int	main(int ac, char **av)
{
	if (ac != 5) {
		cout << "Please put 4 arguments" << endl;
		return 84;
	} else if (!isNumber(av[1]) || !isNumber(av[2]) || !isNumber(av[4])) {
		cout << "Argument 1, 2 and 4 should only be numbers" << endl;
		return 84;
	}
	Bollinger	bollinger(atoi(av[1]), stod(av[2]), av[3], atoi(av[4]));
	bollinger.dump();
}
