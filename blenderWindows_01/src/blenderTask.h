/*
 * blenderTask.h
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#ifndef BLENDERTASK_H_
#define BLENDERTASK_H_

#include "blenderWindow.h"
#include "ofMain.h"

class blenderTask {
public:
	blenderTask();
	virtual ~blenderTask();

	enum RESULT {
		INIT,
		CORRECT,
		TIMEOUT,
		WINDOWERR,
		SHORTCUTERR
	};

	static int 				count;
	int						countId;
	string					identifier;
	blenderWindow* 			correspondingWindow;
	float					timeOut;
	float					startTime;
	float					endTime;
	blenderTask::RESULT		result;

	blenderWindow* 	getCorrespondingWindow() { return correspondingWindow; }
	void			setCorrespondingWindow(blenderWindow &window) { correspondingWindow = &window; }
	void			setIdentifier(string id) { identifier = id; }

};

#endif /* BLENDERTASK_H_ */
