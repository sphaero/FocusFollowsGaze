/*
 * PropWindow.h
 *
 *  Created on: Nov 4, 2013
 *      Author: arnaud
 */

#ifndef PROPWINDOW_H_
#define PROPWINDOW_H_

#include "blenderWindow.h"
#include "blenderButton.h"

class PropWindow: public blenderWindow {
public:
	PropWindow();
	virtual ~PropWindow();

	void setup();
	void update();
	void draw();
	void reset();

	blenderButton button;
};

#endif /* PROPWINDOW_H_ */
