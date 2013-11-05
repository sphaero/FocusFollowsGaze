#pragma once

#include "ofMain.h"
#include "ofxUDPManager.h"
#include "taskBroker.h"

#include "TDWindow.h"
#include "TXTWindow.h"
#include "PropWindow.h"

#define OG_UDP_PORT 20320

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	ofxUDPManager	udpSocket;
	int 			gazeCoords[2];
	void			receiveGazeCoords();
	void			drawGaze();
	
	//Diffent window types
	TXTWindow mytxtWindow1;
	TXTWindow mytxtWindow2;
	TDWindow mytdWindow;
	PropWindow  mypropWindow;

	taskBroker		broker;

};
