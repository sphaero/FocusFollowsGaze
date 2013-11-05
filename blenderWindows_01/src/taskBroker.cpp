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
		if (!currentTask->correspondingWindow)
		{
			ofLogError("correspondingWindow is NULL");
		}
		else
		{
			// check for if completed (endTime = 0 at start!)
			if ( currentTask->correspondingWindow->taskCompleted )
			{
				currentTask->endTime = curTime;
				determineResult();
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
	}
	else if (nextTaskDeparture < curTime)
	{
		newTask();
	}
}

void taskBroker::determineResult()
{
	// task is successful
	if (currentTask->correspondingWindow->active &&
			currentTask->correspondingWindow->taskCompleted )
	{
		currentTask->result = blenderTask::CORRECT;
	}
	// task wrong window
	else if (currentTask->correspondingWindow->active &&
			currentTask->correspondingWindow->taskCompleted )
	{
		currentTask->result = blenderTask::WINDOWERR;
	}
	// task probably wrong shortcut
	else {
		currentTask->result = blenderTask::SHORTCUTERR;
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
	int i = floor(ofRandom(tasks.size()));
	currentTask->correspondingWindow = tasks.at(i)->correspondingWindow;
	currentTask->correspondingWindow->coloredActive = true;
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

void taskBroker::addTask(blenderTask &task)
{
	tasks.push_back(&task);
}
