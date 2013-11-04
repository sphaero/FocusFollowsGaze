/*
 * blenderWindow.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderWindow.h"

blenderWindow::blenderWindow() {
	// TODO Auto-generated constructor stub


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
	if(isMouseOver()) {
		ofSetColor(144, 144, 144);
		active = true;
	} else {
		ofSetColor(104, 104, 104);
		active = false;
	}
	ofFill();
	ofRect(x, y, width, height); //fill
	ofSetColor(0, 0, 0);
	ofNoFill();
	ofRect(x, y, width, height); //stroke
	
}



blenderWindow::~blenderWindow() {
	// TODO Auto-generated destructor stub
}

