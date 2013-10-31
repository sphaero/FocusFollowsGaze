/*
 * taskBroker.h
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#ifndef TASKBROKER_H_
#define TASKBROKER_H_

#include "ofMain.h"
#include "blenderTask.h"

class taskBroker {
public:
	taskBroker();
	virtual ~taskBroker();

	void addTask(blenderTask &task);
	void newTask();
	void saveCurrentTask();
	void outputResults();

	std::vector<blenderTask*>	tasks;
	std::vector<blenderTask*>	measuredTasks;

	void setup();
	void start();
	void update();

	blenderTask* 	currentTask;
	float 			nextTaskDeparture;
	float			randomDelayMax = 2.0f;
};

#endif /* TASKBROKER_H_ */