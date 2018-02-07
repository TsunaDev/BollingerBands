//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Bollinger's source file
//

#include <fstream>
#include <iostream>
#include <exception>
#include <iomanip>
#include <cmath>
#include "Bollinger.hpp"

Bollinger::Bollinger(size_t period, double SDCoef, string filename, size_t index) :
	_period(period), _SDCoef(SDCoef), _filename(filename), _index(index)
{
	try {
		setValues(filename);
	} catch (const invalid_argument &e) {
		throw e;
	}
	setMean();
	setStandardDeviation();
	setBands();
}

void	Bollinger::setValues(string filename)
{
	ifstream	file(filename);

	if (!file)
		throw invalid_argument("Can't open file");

	string		content;

	while (getline(file, content))
		_values.push_back(stod(content));
	file.close();
}

void	Bollinger::changeIndex(size_t index)
{
	_index = index;
	setMean();
	setStandardDeviation();
	setBands();
}

void	Bollinger::setMean()
{
	double	sum = 0.0;

	for (size_t idx = _index - _period + 1; idx <= _index; idx++)
		sum += _values[idx];
	_mean = sum / (double)_period;
}

void	Bollinger::setStandardDeviation()
{
	double	sum = 0.0;

	for (size_t idx = _index - _period + 1; idx <= _index; idx++)
		sum += pow(_values[idx] - _mean, 2);
	_SD = sqrt(sum / (double)_period);
}

void	Bollinger::setBands()
{
	_upperBand = _mean + (_SD * _SDCoef);
	_lowerBand = _mean - (_SD * _SDCoef);
}

const vector<double>	&Bollinger::getValues() const
{
	return _values;
}

const size_t	&Bollinger::getIndex() const
{
	return _index;
}

const size_t	&Bollinger::getPeriod() const
{
	return _period;
}

const double	&Bollinger::getSDCoef() const
{
	return _SDCoef;
}

const double	&Bollinger::getMean() const
{
	return _mean;
}

const double	&Bollinger::getSD() const
{
	return _SD;
}

const double	&Bollinger::getUpperBand() const
{
	return _upperBand;
}

const double	&Bollinger::getLowerBand() const
{
	return _lowerBand;
}

void	Bollinger::dump()
{
	cout << "INPUT" << endl;
	cout << "Index: " << _index << endl;
	cout << "Period: " << _period << endl;
	cout << "SD_coef: " << fixed << setprecision(2) << _SDCoef << endl << endl;

	cout << "OUTPUT" << endl;
	cout << "MA: " << fixed << setprecision(2) << _mean << endl;
	cout << "SD: " << fixed << setprecision(2) << _SD << endl;
	cout << "B+: " << fixed << setprecision(2) << _upperBand << endl;
	cout << "B-: " << fixed << setprecision(2) << _lowerBand << endl;
}
