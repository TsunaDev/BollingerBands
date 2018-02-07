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

void    print_usage()
{
	cout << "Bollinger Bands" << endl << endl;
	cout << "USAGE" << endl;
	cout << "\tperiod\t\tnumberof indexes for the moving average" << endl;
	cout << "\tstandard_dev\tstandard deviation coefficient to apply" << endl;
	cout << "\tindexes_file\tfile containing daily indexes" << endl;
	cout << "\tindex_number\tindex number to compute moving average and Bollinger bands" << endl << endl;
	cout << "OPTIONS" << endl;
	cout << "\t-h\t\tprint the usage and quit." << endl;
}

int	main(int ac, char **av)
{
	if (ac == 2 && string(av[1]) == "-h") {
		print_usage();
		return 0;
	}
	if (ac != 5) {
		cout << "Use -h to see the usage" << endl;
		return 84;
	} else if (!isNumber(av[1]) || !isNumber(av[2]) || !isNumber(av[4])) {
		cout << "Use -h to see the usage" << endl;
		return 84;
	}
	Bollinger	bollinger(atoi(av[1]), stod(av[2]), av[3], atoi(av[4]));
	bollinger.dump();
}
