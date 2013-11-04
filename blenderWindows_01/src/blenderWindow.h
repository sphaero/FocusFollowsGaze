/*
 * blenderWindow.h
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#ifndef BLENDERWINDOW_H_
#define BLENDERWINDOW_H_

#include "ofxMSAInteractiveObject.h"

class blenderWindow: public ofxMSAInteractiveObject {
public:
	blenderWindow();
	virtual ~blenderWindow();
	
	void setup();
	void update();
	void draw();
	
	int offView; //offset for 3D Viewport

	// see windowState diagrams
	bool cmdActive; 
	bool active; //is window active
	bool coloredActive; //for color only
	// time to fade back to original color
	float coloredTime;
	
	ofTrueTypeFont font;

private:
	void processColored();
};

#endif /* BLENDERWINDOW_H_ */
