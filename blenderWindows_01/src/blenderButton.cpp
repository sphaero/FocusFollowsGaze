/*
 * blenderButton.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#include "blenderButton.h"

blenderButton::blenderButton() {
	// TODO Auto-generated constructor stub
	buttonDown = false;

}

blenderButton::~blenderButton() {
	// TODO Auto-generated destructor stub
}

void blenderButton::onRelease(int x, int y, int button)
{
	buttonDown = !buttonDown;
}

void blenderButton::draw()
{
	ofFill();
	if (buttonDown)
		ofSetColor(100,0,0);
	else
		ofSetColor(0,200,0);
	ofRect((ofRectangle)*this);
	ofSetColor(0);
	ofNoFill();
	ofRect((ofRectangle)*this);

}
