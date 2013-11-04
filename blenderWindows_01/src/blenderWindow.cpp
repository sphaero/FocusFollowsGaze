/*
 * blenderWindow.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderWindow.h"

blenderWindow::blenderWindow(int _windowType) {
	// TODO Auto-generated constructor stub
	
	//what type of window is it: rotate, cmd or property?
	windowType = _windowType;

}

void blenderWindow::setup() {
	enableMouseEvents();	
	font.loadFont("verdana.ttf", 18);
	
	
	if (windowType == TEXTED) {
		multilineTextInput.setup();
		multilineTextInput.multiline = true;
		multilineTextInput.setFont(font);
		
		multilineTextInput.bounds.x = x;
		multilineTextInput.bounds.y = y;
		multilineTextInput.bounds.width = width;
		multilineTextInput.bounds.height = height;
	} else if (windowType == TDVIEW) {
		cam.setPosition(0, 0, 400);
		offView = 15;
	}
	
}

void blenderWindow::draw() {

	
	//Windows (grey)
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
	
	if (windowType == TEXTED) {
		multilineTextInput.draw();
	} else if (windowType == TDVIEW) {
		
		//Window 3D environment (black)
		ofSetColor(50, 50, 50);
		ofFill();
		
		ofRect(x+offView, y+offView, width-offView*2, height-offView*2);
		cam.begin(ofRectangle(x+offView, y+offView, width-offView*2, height-offView*2));	
		
		ofPushMatrix();
		if(isMouseOver()) {
			ofRotate(x-getMouseX(), 0, 1, 0);
		} else {
			ofRotate(10, 0, 1, 0);
		}
		
		ofSetColor(255, 0, 0);
		ofFill();
		ofBox(0, 0, 100, 100);
		ofSetColor(0, 0, 0);
		ofNoFill();
		ofBox(0, 0, 100, 100);
		ofPopMatrix();
		cam.end();
	} else if (PROPERTY) {
		//draw poperty gui
	}
	
}

blenderWindow::~blenderWindow() {
	// TODO Auto-generated destructor stub
}

