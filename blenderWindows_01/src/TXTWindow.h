/*
 *  TXTWindow.h
 *  blenderWindows_01
 *
 *  Created by Sabrina Verhage on 11/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TXTWINDOW_H_
#define TXTWINDOW_H_

#include "blenderWindow.h"
#include "ofxTextInputField.h"

class TXTWindow: public blenderWindow {

public: 
	TXTWindow();
	virtual ~TXTWindow();

	void draw();
	void setup();
	void update();

	ofxTextInputField multilineTextInput;
	string prevTxt;
};

#endif /* TXTWINDOW_H_ */
