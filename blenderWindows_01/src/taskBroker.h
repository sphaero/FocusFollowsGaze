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

	// method to add task to the pool of tasks to choose from
	void addTask(blenderTask &task);
	// setup a new task from the pool of tasks
	void newTask();
	// save the current task to the array of measured tasks
	void saveCurrentTask();
	// determine the result of a task
	void determineResult();
	// reset all windows to a sane state
	void resetTaskWindow();
	// output measured results to the console
	void outputResults();
	void saveResults();

	// the pool of tasks
	vector<blenderTask*>	tasks;
	// the saved tasks
	vector<blenderTask*>	measuredTasks;

	void start();
	void update();

	// pointer to the current task
	blenderTask* 	currentTask;
	// time for new task departure
	float 			nextTaskDeparture;
	// the maximum time until the next task
	float			randomDelayMax;
};

#endif /* TASKBROKER_H_ */
