/*
 *  TXTWindow.cpp
 *  blenderWindows_01
 *
 *  Created by Sabrina Verhage on 11/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "TXTWindow.h"

TXTWindow::TXTWindow() {

	
}

void TXTWindow::setup() {
	blenderWindow::setup();
	
	//set(ofGetWindowWidth()/4*3, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	
	multilineTextInput.setup();
	multilineTextInput.multiline = true;
	multilineTextInput.setFont(font);
	
	multilineTextInput.bounds.x = x;
	multilineTextInput.bounds.y = y;
	multilineTextInput.bounds.width = width;
	multilineTextInput.bounds.height = height;
	
}

void TXTWindow::draw() {
	blenderWindow::draw();
	
	multilineTextInput.draw();
}

TXTWindow::~TXTWindow() {
	
}
