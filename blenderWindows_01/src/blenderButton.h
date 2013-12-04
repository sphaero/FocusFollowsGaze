/*
 * blenderButton.h
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#ifndef BLENDERBUTTON_H_
#define BLENDERBUTTON_H_

#include "ofxMSAInteractiveObject.h"
#include "ofMain.h"

class blenderButton: public ofxMSAInteractiveObject {
public:
	blenderButton();
	virtual ~blenderButton();

	bool on;
	void onRelease(int x, int y, int button);
	void draw();
	//void setImage(ofImage img);
	void setImage(string path);
	ofImage img;
};

#endif /* BLENDERBUTTON_H_ */
