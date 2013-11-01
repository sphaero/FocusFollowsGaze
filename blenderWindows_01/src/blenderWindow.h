/*
 * blenderWindow.h
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#ifndef BLENDERWINDOW_H_
#define BLENDERWINDOW_H_

#include "ofxMSAInteractiveObject.h"
#include "ofxTextInputField.h"

class blenderWindow: public ofxMSAInteractiveObject {
public:
	blenderWindow();
	virtual ~blenderWindow();
	
	void setup();
	void draw();

	// see windowState diagrams
	bool cmdActive;
	bool active;
	bool coloredActive;
	// time to fade back to original color
	float coloredTime;
	
	ofxTextInputField multilineTextInput;
	ofTrueTypeFont font;

private:
	void processColored();
};

#endif /* BLENDERWINDOW_H_ */
