/*
 * PropWindow.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#include "PropWindow.h"

PropWindow::PropWindow() {
	// TODO Auto-generated constructor stub

}

PropWindow::~PropWindow() {
	// TODO Auto-generated destructor stub
}

void PropWindow::setup()
{
	blenderWindow::setup();
	
	set(0,0,ofGetWindowWidth()/5, ofGetWindowHeight());
	button.set(2,2, ofGetWindowWidth()/5-4, ofGetWindowHeight()/30);
	button.enableMouseEvents();
}

void PropWindow::update()
{
	blenderWindow::update();
}

void PropWindow::draw()
{
	blenderWindow::draw();
	button.draw();
}
