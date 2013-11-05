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
#include <vector>

class taskBroker {
public:
	taskBroker();
	virtual ~taskBroker();

	void addTask(blenderTask &task);
	void newTask();
	void saveCurrentTask();
	void determineResult();
	void resetTaskWindow();
	void outputResults();

	vector<blenderTask*>	tasks;
	vector<blenderTask*>	measuredTasks;

	void setup();
	void start();
	void update();

	blenderTask* 	currentTask;
	float 			nextTaskDeparture;
	float			randomDelayMax;
};

#endif /* TASKBROKER_H_ */
