/*
 *  TDWindow.h
 *  blenderWindows_01
 *
 *  Created by Sabrina Verhage on 11/4/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TDWINDOW_H_
#define TDWINDOW_H_

#include "blenderWindow.h"
#include "blender3DBox.h"

class TDWindow: public blenderWindow {
	
public:
	TDWindow();
	virtual ~TDWindow();
	
	void setup();
	void draw();
	void onKeyRelease(int key);
	void mouseReleased(int x, int y, int button);
	void mouseMoved(int x, int y);
	
	bool dorotate;
	int rotatevar;

	ofVec2f lastMouse;
	ofCamera cam;

	blender3DBox box;
};

#endif /* TDWINDOW_H_ */
