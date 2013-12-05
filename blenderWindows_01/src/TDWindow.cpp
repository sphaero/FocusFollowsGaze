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
	dorotate = false;
	taskCompleted = false;
}

void TDWindow::setup() {
	blenderWindow::setup();

	cam.setPosition(0, -6, 1);
	cam.setOrientation(ofVec3f(75,0,0));
	cam.setNearClip(1.0f);
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
	drawGrid();//16, 30.f);
	
	if (dorotate)
	{
		ofVec3f prevRotE = prevRotation.getEuler();
		//ofLogVerbose() << "Rotation Euler = " << box.getOrientationEuler()-prevRotE;
	}
	box.draw();
	cam.end();
	if (operatorActive && active)
	{
		ofSetColor(0,0,0);
		//ofSphere(300.300,300,300);
		ofVec3f boxPos = cam.worldToScreen(box.getPosition(), ofRectangle(x+offView, y+offView, width-offView*2, height-offView*2));
		glLineStipple(1, 0x3F07 );
		glEnable( GL_LINE_STIPPLE );
		ofLine(boxPos.x,boxPos.y, ofGetMouseX(), ofGetMouseY());
		glDisable( GL_LINE_STIPPLE );
	}
}

void TDWindow::drawGrid(int lines, float scale)
{
	//just some style hacking to make sure we draw red and blue
    ofPushStyle();
    ofDisableLighting();
    ofEnableAlphaBlending();
    ofPushMatrix();
    //ofEnableAlpaBlending();

    float gridRadius = lines * scale;
    float step = (lines*scale)/lines;
    int halfway = int(lines/2);

    //float

    ofTranslate(halfway*-step,halfway*-step,0);

    for(int i = 0; i <= lines; i++){

        float pos = i*step;
        if (i==halfway) {
            //X-axis red
            ofSetColor(255, 0, 0, 128);
            ofLine(0, pos, 0, gridRadius, pos, 0);
            //Y-axis green
            ofSetColor(0,255,0);
            ofLine(pos, 0, 0,  pos, gridRadius, 0);
            //Z axis blue
            ofSetColor(0,0,255,128);
            ofLine(pos, pos, -gridRadius, pos, pos, gridRadius);
        }
        else {
            ofSetColor(140, 140, 140, 128);
            ofLine(pos, 0, 0,  pos, gridRadius, 0);
            ofLine(0, pos, 0, gridRadius, pos, 0);
        }
    }
    ofPopMatrix();
    ofPopStyle();
}

void TDWindow::onKeyRelease(int key) {
	if (key == 'r' && active) {
		dorotate = true;
		operatorActive = true;
		prevRotation = box.getOrientationQuat();
	}
}

void TDWindow::mouseReleased(int x, int y, int button) {
	if (dorotate == true) {
		if (button == 2)
		{
			box.setOrientation(prevRotation);
		}
		else
		{
			if (cmdActive)
				ofLogVerbose() << "TDWINDOW COMPLETE";
				taskCompleted = true; //task broker makes it false again
		}
		dorotate = false;
		operatorActive = false;
	} 
}

void TDWindow::mouseMoved(int x, int y)
{
	if (dorotate)
	{
		ofVec2f mouse(x,y);
		//box.setOrientation(ofVec3f(x,y,0));
		ofQuaternion yRot(x-lastMouse.x, ofVec3f(0,0,1));
		ofQuaternion xRot(y-lastMouse.y, ofVec3f(1,0,0));
		ofQuaternion curRot = box.getOrientationQuat();
		curRot *= yRot*xRot;
		box.setOrientation(curRot);
		lastMouse = mouse;
	}
}

TDWindow::~TDWindow() {

}
