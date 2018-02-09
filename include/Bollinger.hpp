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
	//void	errorHandling();
	bool	changeIndex(size_t);
	const vector<double>	&getValues() const;
	const size_t		&getIndex() const;
	const size_t		&getMaxIndex() const;
	const size_t		&getDefaultIndex() const;
	const size_t		&getPeriod() const;
	const double		&getSDCoef() const;
	const double		&getMean() const;
	const double		&getSD() const;
	const double		&getUpperBand() const;
	const double		&getLowerBand() const;

private:
	void		setValues(string);
	void		setMean();
	void		setStandardDeviation();
	void		setBands();
	size_t		_period;
	double		_SDCoef;
	string		_filename;
	size_t		_index;
	size_t		_maxIndex;
	size_t		_defIndex;
	vector<double>	_values;
	double		_mean;
	double		_SD;
	double		_upperBand;
	double		_lowerBand;
};

#endif	// !BOLLINGER_HPP_
