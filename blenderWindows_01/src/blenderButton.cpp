/*
 * blenderButton.cpp
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#include "blenderButton.h"

blenderButton::blenderButton() {
	// TODO Auto-generated constructor stub
	on = false;

}

blenderButton::~blenderButton() {
	// TODO Auto-generated destructor stub
}

void blenderButton::onRelease(int x, int y, int button)
{
	on = !on;
}

void blenderButton::draw()
{
	ofFill();
	if (img.isAllocated()) {
		if (on)
			ofSetColor(255);
		else
			ofSetColor(255, 255, 255, 100);
		img.draw(this->x,this->y);
	}
	else
	{
		if (on)
			ofSetColor(100,0,0);
		else
			ofSetColor(0,200,0);
		ofRect((ofRectangle)*this);
		ofSetColor(0);
		ofNoFill();
		ofRect((ofRectangle)*this);
	}
}

void blenderButton::setImage(string path)
{
	img.loadImage(path);
}
