/*
 * taskBroker.cpp
 *
 *  Created on: Oct 31, 2013
 *      Author: arnaud
 */

#include "taskBroker.h"

taskBroker::taskBroker()
{
	// TODO Auto-generated constructor stub
	currentTask = NULL;
	nextTaskDeparture = 0;
	randomDelayMax = 2.0f;
	
}

taskBroker::~taskBroker()
{
	// TODO Auto-generated destructor stub
}

void taskBroker::setup()
{
	//initialise possible tasks
	

}

void taskBroker::start()
{
	//start deploying tasks
}

void taskBroker::update() {
	//check if current task is completed and delay has passed
	float curTime = ofGetElapsedTimef();
	if (currentTask)
	{
		// check for if completed (endTime = 0 at start!)
		if (currentTask->endTime > currentTask->startTime)
		{
			saveCurrentTask();
		}
		//check for timeout
		if (currentTask->startTime + currentTask->timeOut < curTime )
		{
			ofLogVerbose() << "task timeout";
			currentTask->endTime = curTime;
			currentTask->result = blenderTask::TIMEOUT;
			saveCurrentTask();
		}
	}
	else if (nextTaskDeparture < curTime)
	{
		newTask();
	}
}

void taskBroker::saveCurrentTask()
{
	measuredTasks.push_back(currentTask);
	ofLogVerbose() << "task finished at: " << currentTask->endTime
			<< " started at: " << currentTask->startTime
			<< " status = " << currentTask->result;
	currentTask = NULL;
	nextTaskDeparture = ofRandom(randomDelayMax) + ofGetElapsedTimef();
}

void taskBroker::newTask()
{
	currentTask = new blenderTask();
}

void taskBroker::outputResults()
{
	std::vector<blenderTask*>::iterator it = measuredTasks.begin();
	while (it != measuredTasks.end())
	{
		ofLogVerbose() << "task finished at: " << (*it)->endTime
					<< " started at: " << (*it)->startTime
					<< " status = " << (*it)->result;
		it++;
	}
}
