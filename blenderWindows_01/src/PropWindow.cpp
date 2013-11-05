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

	button.set(2,2, ofGetWindowWidth()/5-4, ofGetWindowHeight()/30);
	button.enableMouseEvents();
}

void PropWindow::update()
{
	blenderWindow::update();
	if (cmdActive && button.buttonDown)
	{
		ofLogVerbose() << "COMPLEEEETE";
		taskCompleted = true;
	}
}

void PropWindow::draw()
{
	blenderWindow::draw();
	button.draw();
}

void PropWindow::reset()
{
	ofLogVerbose() << "PROPWIN";
	blenderWindow::reset();
	button.buttonDown = false;
}
