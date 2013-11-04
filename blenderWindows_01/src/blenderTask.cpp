/*
 * blenderTask.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "blenderTask.h"

blenderTask::blenderTask() {
	// TODO Auto-generated constructor stub
	startTime = ofGetElapsedTimef();
	endTime = 0.f;
	timeOut = 1.f;
	result = blenderTask::INIT;
	correspondingWindow = NULL;
}

blenderTask::~blenderTask() {
	// TODO Auto-generated destructor stub
}

