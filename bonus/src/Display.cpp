//
// EPITECH PROJECT, 2018
// Bollinger
// File description:
// Graphical display class
//

#include <iostream>
#include <sstream>
#include <cmath>
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
	setScale();
	cout << "Scale : " << _scale << endl;
}

void	Display::setScale()
{
	double	tmpMax = _maxBand;
	int	sizeMax = 0;

	cout << tmpMax << endl;
	while (tmpMax > 1) {
		tmpMax /= 10.0;
		sizeMax++;
	}
	tmpMax *= 10.0;
	tmpMax = ceil(tmpMax) * pow(10, sizeMax - 1);
	cout << tmpMax << endl;
	double	tmpMin = _minBand;
	double	sizeMin = 0;

	while (tmpMin > 1) {
		tmpMin /= 10.0;
		sizeMin++;
	}
	tmpMin *= 10.0;
	tmpMin = floor(tmpMin) * pow(10, sizeMin - 1);
	cout << tmpMax << endl;

	double diff = abs(tmpMax - tmpMin);
	cout << diff << endl;
	_scale = diff / 10.0;
	_ceil = tmpMax;
	_floor = tmpMin;
}

void	Display::start(unsigned int width, unsigned int height)
{
	sf::ContextSettings	context(0,0,8);
	sf::RenderWindow	window(sf::VideoMode(width, height),
				       "Bollinger bands", sf::Style::Default,
				       context);
	sf::Text		text;
	_width = width;
	_height = height;
	window.setFramerateLimit(60);
	setMeanVertices();
	setBandsVertex();
	_font.loadFromFile("font.ttf");
	//setInfos();
	sf::View	view(sf::Vector2f((float)width * 2.0f, (float)_middle),
			     sf::Vector2f((float)width * 4.0f, (float)(_maxBand - _minBand)));
	window.setView(view);
	window.clear(sf::Color::White);
	window.draw(_bandsVertex);
	window.draw(&_meanVertices[0], _meanVertices.size(), sf::Lines);
	window.draw(&_meanVertices[1], _meanVertices.size() - 1, sf::Lines);
	window.display();
	sf::Event	event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed ||
			    (event.type == sf::Event::KeyPressed &&
			     event.key.code == sf::Keyboard::Escape))
				window.close();				
		}
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

void	Display::setBandsVertex()
{
	sf::VertexArray bands(sf::TrianglesStrip, _upperBand.size() * 2);
	size_t	idxB = 0;

	for (size_t idx = 0; idx < _upperBand.size(); idx++) {
		bands[idxB].position = sf::Vector2f((float)idx *
						(((float)_width * 4.0f) /
						_rollingMean.size()), (float)_upperBand[idx]);
		bands[idxB].color = sf::Color::Black;
		bands[idxB].color.a = 100;
		idxB++;
		bands[idxB].position = sf::Vector2f((float)idx *
						(((float)_width * 4.0f) /
						_rollingMean.size()), (float)_lowerBand[idx]);
		bands[idxB].color = sf::Color::Black;
		bands[idxB].color.a = 100;
		idxB++;
	}
	_bandsVertex = bands;
}

void	Display::setInfos()
{

}

void	Display::dumpBands()
{
	cout << "max" << _maxBand << endl;
	cout << "min" << _minBand << endl;
	for (size_t idx = 0; idx <= _bollinger.getMaxIndex() -
		     _bollinger.getDefaultIndex(); idx++) {
		cout << "idx : " << idx << endl;
		cout << "upper : " << _upperBand[idx] << endl;
		cout << "lower : " << _lowerBand[idx] << endl;
		cout << "mean : " << _rollingMean[idx] << endl;
		cout << "------" << endl;
	}
}
