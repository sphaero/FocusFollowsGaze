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

void TXTWindow::update()
{
	blenderWindow::update();
	if (cmdActive)
	{
		if (multilineTextInput.text != prevTxt)
		{
			ofLogVerbose() << "COMPLETE PROPWINDOW";
			taskCompleted = true;
		}
	}
	else
	{
		prevTxt = multilineTextInput.text;
	}
}

void TXTWindow::draw() {
	blenderWindow::draw();
	
	multilineTextInput.draw();
}

void TXTWindow::onGazeMoved(ofVec2f &coords){

	// is the user looking at us?
	if (hitTest(coords.x, coords.y))
	{
		if (!operatorActive) active = true;
		if(!multilineTextInput.getIsEditing()){
			multilineTextInput.beginEditing();
		}
	}
	else
	{
		if (!operatorActive) active = false;
		if(multilineTextInput.getIsEditing())
		{
			multilineTextInput.endEditing();
		}
	}
}

TXTWindow::~TXTWindow() {
	
}
