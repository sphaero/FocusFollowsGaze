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
	
	set(0, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	button.set(10,10, 200, 50);
	button.enableMouseEvents();
}

void PropWindow::update()
{
	blenderWindow::update();
	if ( button.isMousePressed() )
	{
		ofLogVerbose() << "BUTTON PRESSSED!!!";
	}
}

void PropWindow::draw()
{
	blenderWindow::draw();
	if ( button.isMouseOver() )
	{
		ofLogVerbose() << "MOUSE OVER!!!";
		ofSetColor(255,0,0);
		ofFill();
		ofRect((ofRectangle)button);
	}
	else
	{
		ofSetColor(0,255,0);
		ofFill();
		ofRect((ofRectangle)button);
	}
}
