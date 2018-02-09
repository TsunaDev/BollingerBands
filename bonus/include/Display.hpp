//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Graphical display class' header
//

#ifndef	DISPLAY_HPP_
#define DISPLAY_HPP_

#include <SFML/Graphics.hpp>
#include "Bollinger.hpp"

class Display {
public:
	Display(Bollinger bollinger);
	void		start(int, int);
	void		dumpBands();

private:
	void		setBands();
	Bollinger	_bollinger;
	double		_maxBand;
	double		_minBand;
	double		_middle;
	vector<double>	_upperBand;
	vector<double>	_lowerBand;
	vector<double>	_rollingMean;
	int			_width;
	int			_height;
	void			setMeanVertices();
	vector<sf::Vertex>	_meanVertices;
	sf::Window		_window;
};

#endif	// !DISPLAY_HPP_
