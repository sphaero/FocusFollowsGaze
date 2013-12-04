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

	button.set(5,5, ofGetWindowWidth()/5-10, ofGetWindowHeight()/30);
	button.enableMouseEvents();
}

void PropWindow::update()
{
	blenderWindow::update();
	if (cmdActive && button.on)
	{
		ofLogVerbose() << "COMPLETE PROPWINDOW";
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
	button.on = false;
}
