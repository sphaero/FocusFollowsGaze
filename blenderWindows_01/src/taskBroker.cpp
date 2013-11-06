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
	randomDelayMax = 5.0f;
}

taskBroker::~taskBroker()
{
	// TODO Auto-generated destructor stub
}

void taskBroker::update() {
	//check if current task is completed and delay has passed
	float curTime = ofGetElapsedTimef();
	// we are running as long as we have a pointer to a task
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
				resetTaskWindow();
				saveCurrentTask();
			}
			//check for timeout
			else if (currentTask->startTime + currentTask->timeOut < curTime )
			{
				ofLogVerbose() << "task timeout " << currentTask->correspondingWindow->taskCompleted;
				currentTask->endTime = curTime;
				currentTask->result = blenderTask::TIMEOUT;
				resetTaskWindow();
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
		ofLogVerbose() << "task COMPLETED";
		currentTask->result = blenderTask::CORRECT;
	}
	// task wrong window
	else if (currentTask->correspondingWindow->active &&
			currentTask->correspondingWindow->taskCompleted )
	{
		ofLogVerbose() << "task wrong window";
		currentTask->result = blenderTask::WINDOWERR;
	}
	// task probably wrong shortcut
	else {
		ofLogVerbose() << "task shortcut error";
		currentTask->result = blenderTask::SHORTCUTERR;
	}
}

void taskBroker::resetTaskWindow()
{
	currentTask->correspondingWindow->reset();
}

void taskBroker::saveCurrentTask()
{
	measuredTasks.push_back(currentTask);
	//ofLogVerbose() << "task finished at: " << currentTask->endTime
	//		<< " started at: " << currentTask->startTime
	//		<< " status = " << currentTask->result;
	currentTask = NULL;
	nextTaskDeparture = ofRandom(randomDelayMax) + ofGetElapsedTimef();
}

void taskBroker::newTask()
{
	// reset all the windows to a sane state
	vector<blenderTask*>::iterator it = tasks.begin();
	while (it != tasks.end())
	{
		(*it)->correspondingWindow->cmdActive = false;
		++it;
	}

	// create a new task
	currentTask = new blenderTask();

	// pick a random task from the pool
	int i = floor(ofRandom(tasks.size()-0.1));
	// from the picked task we copy the pointer to the window & the id
	currentTask->correspondingWindow = tasks.at(i)->correspondingWindow;
	currentTask->identifier = tasks.at(i)->identifier;
	// mark the window to be colored (color cue) and set cmdActive
	currentTask->correspondingWindow->coloredActive = true;
	currentTask->correspondingWindow->cmdActive = true;
}

void taskBroker::outputResults()
{
	std::vector<blenderTask*>::iterator it = measuredTasks.begin();
	while (it != measuredTasks.end())
	{
		if ((*it)->result == blenderTask::TIMEOUT)
		{
			ofLogVerbose() << (*it)->countId << ":" << (*it)->identifier << ": task timed out";
		}
		else
		{
			float t = (*it)->endTime - (*it)->startTime;
			cout.setf(ios::fixed);
			ofLogVerbose() << (*it)->countId << ":" << (*it)->identifier
					<< ": task finished in:\t" << t
					<< " status:\t " << (*it)->result;
		}
		++it;
	}
}

void taskBroker::saveResults()
{
	string filename = ofToString(ofGetUnixTime());
	ofLogToFile(filename);
	std::vector<blenderTask*>::iterator it = measuredTasks.begin();
	while (it != measuredTasks.end())
	{
		float t = (*it)->endTime - (*it)->startTime;
		ofLog() << ";" <<
				(*it)->countId << ";" <<
				(*it)->identifier << ";" <<
				t << ";" <<
				(*it)->result;
		++it;
	}
	ofLogToConsole();
}

void taskBroker::addTask(blenderTask &task)
{
	tasks.push_back(&task);
}
