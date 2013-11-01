/*
 * blenderWindow.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderWindow.h"

blenderWindow::blenderWindow() {
	// TODO Auto-generated constructor stub
	
	//what type of window is it: rotate, cmd or property?
	cmdActive = true;

}

void blenderWindow::setup() {
	enableMouseEvents();	
	font.loadFont("verdana.ttf", 18);
	
	
	if (cmdActive) {
		multilineTextInput.setup();
		multilineTextInput.multiline = true;
		multilineTextInput.setFont(font);
		
		multilineTextInput.bounds.x = x;
		multilineTextInput.bounds.y = y;
		multilineTextInput.bounds.width = width;
		multilineTextInput.bounds.height = height;
	}
	
}

void blenderWindow::draw() {
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
	
	if (cmdActive) {
		multilineTextInput.draw();
	}
	
}

blenderWindow::~blenderWindow() {
	// TODO Auto-generated destructor stub
}

