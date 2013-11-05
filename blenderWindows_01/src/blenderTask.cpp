/*
 * blenderTask.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderTask.h"

// initialise the counter
int blenderTask::count = 0;

blenderTask::blenderTask() {
	count++;
	countId = count;
	// TODO Auto-generated constructor stub
	startTime = ofGetElapsedTimef();
	endTime = 0.f;
	timeOut = 5.f;
	result = blenderTask::INIT;
	correspondingWindow = NULL;
}

blenderTask::~blenderTask() {
	// TODO Auto-generated destructor stub
}

