/*
 * blenderButton.h
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#ifndef BLENDERBUTTON_H_
#define BLENDERBUTTON_H_

#include "ofxMSAInteractiveObject.h"

class blenderButton: public ofxMSAInteractiveObject {
public:
	blenderButton();
	virtual ~blenderButton();

	bool buttonDown;
	void onRelease(int x, int y, int button);
	void draw();
};

#endif /* BLENDERBUTTON_H_ */
