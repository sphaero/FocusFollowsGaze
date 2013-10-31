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

	// see windowState diagrams
	bool cmdActive;
	bool active;
	bool coloredActive;
	// time to fade back to original color
	float coloredTime;

private:
	void processColored();
};

#endif /* BLENDERWINDOW_H_ */
