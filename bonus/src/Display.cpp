//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Graphical display class
//

#include <iostream>
#include "Display.hpp"

Display::Display(Bollinger bollinger) : _bollinger(bollinger)
{
	setBands();
}

void	Display::setBands()
{
	size_t	idx = _bollinger.getIndex();
	bool	ret = true;
	double	upperBand;
	double	lowerBand;

	_maxBand = _bollinger.getUpperBand();
	_minBand = _bollinger.getLowerBand();
	while (ret) {
		upperBand = _bollinger.getUpperBand();
		lowerBand = _bollinger.getLowerBand();
		_upperBand.push_back(upperBand);
		if (upperBand > _maxBand)
			_maxBand = upperBand;
		_lowerBand.push_back(lowerBand);
		if (lowerBand < _minBand)
			_minBand = lowerBand;
		_rollingMean.push_back(_bollinger.getMean());
		idx++;
		ret = _bollinger.changeIndex(idx);
	}
	_middle = _minBand + (_maxBand - _minBand) / 2.0;
}

void	Display::start(int width, int height)
{
	sf::RenderWindow	window(sf::VideoMode(width, height), "Bollinger bands");
	_width = width;
	_height = height;
	window.setFramerateLimit(60);
	setMeanVertices();
	sf::View	view(sf::Vector2f((float)width * 2.0f, (float)_middle),
			     sf::Vector2f((float)width * 4.0f, 16000.0f));
//	view.setCenter(0, (int)_middle);
	window.setView(view);
	window.draw(&_meanVertices[0], _meanVertices.size(), sf::Lines);

	while (window.isOpen()) {
		sf::Event	event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.display();
	}
}

void	Display::setMeanVertices()
{
	for (size_t idx = 0; idx < _rollingMean.size() - 1; idx++) {
		_meanVertices.push_back(sf::Vertex(sf::Vector2f((float)idx *
								(((float)_width * 4.0f) /
								 _rollingMean.size()),
								(float)_rollingMean[idx]),
						   sf::Color::Red));
	}
}

void	Display::dumpBands()
{
	cout << "max" << _maxBand << endl;
	cout << "min" << _minBand << endl;
	for (size_t idx = 0; idx <= _bollinger.getMaxIndex() - _bollinger.getDefaultIndex(); idx++) {
		cout << "idx : " << idx << endl;
		cout << "upper : " << _upperBand[idx] << endl;
		cout << "lower : " << _lowerBand[idx] << endl;
		cout << "mean : " << _rollingMean[idx] << endl;
		cout << "------" << endl;
	}
}
