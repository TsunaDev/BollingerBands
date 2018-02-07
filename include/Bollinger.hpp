//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Bollinger's header file
//

#ifndef	BOLLINGER_HPP_
#define BOLLINGER_HPP_

#include <string>
#include <vector>

using namespace std;

class	Bollinger {
public:
	Bollinger(size_t, double, string, size_t);
	void	dump();
	void	changeIndex(size_t);
private:
	void		setValues(string);
	void		setMean();
	void		setStandardDeviation();
	void		setBands();
	size_t		_period;
	double		_SDCoef;
	string		_filename;
	size_t		_index;
	vector<double>	_values;
	double		_mean;
	double		_SD;
	double		_upperBand;
	double		_lowerBand;
};

#endif	// !BOLLINGER_HPP_
