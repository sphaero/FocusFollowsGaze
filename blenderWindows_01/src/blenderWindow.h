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
	virtual void reset();
	
	int offView; //offset for 3D Viewport

	// see windowState diagrams
	bool cmdActive;				// is blender task active in this window?
	bool active; 				// is window active
	static bool operatorActive; // is an operator (like rotate) active?
	bool coloredActive; 		//for color only
	// time to fade back to original color
	float coloredTime;
	float coloredStart;
	
	bool taskCompleted;
	bool mouseFocus;
	
	ofTrueTypeFont font;

	void onRollOver(int x, int y) {  if (!operatorActive && mouseFocus) active = true; }
	void onRollOut() { if (!operatorActive && mouseFocus) active = false; }

	// Gaze move event
	void onGazeMoved(ofVec2f &coords);

private:
	void processColored(ofColor &c);
	ofColor windowColor;
	ofColor activeWindowColor;
	ofColor	windowColored;
	float coloredCount;
};

#endif /* BLENDERWINDOW_H_ */
