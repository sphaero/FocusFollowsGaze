/*
 * blenderWindow.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderWindow.h"

blenderWindow::blenderWindow() {
	// TODO Auto-generated constructor stub
	coloredActive = false;
	windowColor = ofColor(104, 104, 104);
	activeWindowColor = ofColor(144, 144, 144);
	windowColored = ofColor(255, 123, 25);
	coloredCount = 1.0f;
}

void blenderWindow::setup() {
	enableMouseEvents();	
	enableKeyEvents();	
	font.loadFont("verdana.ttf", 18);
	
}

void blenderWindow::update() {
	
}

void blenderWindow::draw() {

	//draw window (grey) with mouse over animation
	ofColor drawColor = windowColor;
	if(isMouseOver() )
	{
		drawColor = activeWindowColor;
		active = true;
	}
	else
	{
		active = false;
	}

	if (coloredActive)
	{
		processColored(drawColor);
	}

	ofSetColor(drawColor);
	ofFill();
	ofRect(x, y, width, height); //fill
	ofSetColor(0, 0, 0);
	ofNoFill();
	ofRect(x, y, width, height); //stroke
}

void blenderWindow::processColored(ofColor &c)
{
	coloredCount -= 0.02f;
	c.lerp(windowColored, coloredCount);
	if (coloredCount < 0.02)
	{
		coloredActive = false;
		coloredCount = 1.0f;
	}
}

blenderWindow::~blenderWindow() {
	// TODO Auto-generated destructor stub
}

