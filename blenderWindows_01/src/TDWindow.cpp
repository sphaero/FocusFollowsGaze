/*
 *  TDWindow.cpp
 *  blenderWindows_01
 *
 *  Created by Sabrina Verhage on 11/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "TDWindow.h"


TDWindow::TDWindow() {
	gorotate = false;
	taskCompleted = false;
}

void TDWindow::setup() {
	blenderWindow::setup();

	cam.setPosition(0, 0, 400);
	offView = 15;
	rotatevar = 0;
}

void TDWindow::draw() {
	blenderWindow::draw();

	
	//Window 3D environment (black)
	ofSetColor(50, 50, 50);
	ofFill();
	
	ofRect(x+offView, y+offView, width-offView*2, height-offView*2);
	cam.begin(ofRectangle(x+offView, y+offView, width-offView*2, height-offView*2));	
	
	ofPushMatrix();
	
	if(isMouseOver() && gorotate) {
		rotatevar = x-getMouseX();
		ofRotate(rotatevar, 0, 1, 0);
		//cout << "test" << endl;
	} else {
		ofRotate(rotatevar, 0, 1, 0);
	}
	
	ofSetColor(255, 0, 0);
	ofFill();
	ofBox(0, 0, 100, 100);
	ofSetColor(0, 0, 0);
	ofNoFill();
	ofBox(0, 0, 100, 100);
	ofPopMatrix();
	cam.end();
	
	//cout << taskCompleted << endl;
}

void TDWindow::onKeyRelease(int key) {
	if (key == 'r') {
		cout << "werkt" << endl;
		gorotate = true;
	}
}

void TDWindow::mouseReleased(int x, int y, int button) {
	if (gorotate == true) {
		taskCompleted = true; //task broker makes it false again
	} 
	gorotate = false;

}

TDWindow::~TDWindow() {

}