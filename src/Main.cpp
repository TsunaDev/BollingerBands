//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Main function
//

#include	<iostream>

using namespace std;

void	print_usage()
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
		return (0);
	}
}
