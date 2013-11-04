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
	void onKeyRelease(int key);
	
	ofCamera cam;
	
	int windowType;
	enum windowType {
		TEXTED,
		TDVIEW,
		PROPERTY 
	};	
	int offView; //offset for 3D Viewport

	// see windowState diagrams
	bool cmdActive; 
	bool active; //is window active
	bool coloredActive; //for color only
	// time to fade back to original color
	float coloredTime;
	
	ofxTextInputField multilineTextInput;
	ofTrueTypeFont font;

private:
	void processColored();
};

#endif /* BLENDERWINDOW_H_ */
