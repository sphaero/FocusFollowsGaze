#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(240);\
	ofEnableAlphaBlending();
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);
	
	// Setup UDP socket to receive data from OpenGazer
	udpSocket.Create();
	udpSocket.Bind(OG_UDP_PORT);
	udpSocket.SetNonBlocking(true);
	// initialise gaze coords
	gazeCoords[0] = -1;
	gazeCoords[1] = -1;
	
	// Set windows positions & dimensions
	mypropWindow.set(0, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytdWindow.set(ofGetWindowWidth()/4, 0, ofGetWindowWidth()/2, ofGetWindowHeight()/4*3);
	mytxtWindow1.set(ofGetWindowWidth()/4*3, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytxtWindow2.set(0, ofGetWindowHeight()/4*3, ofGetWindowWidth(), ofGetWindowHeight()/4);

	// Initiase tasks & corresponding windows
	blenderTask* t0 = new blenderTask();
	t0->setCorrespondingWindow((blenderWindow&)mypropWindow);
	t0->setIdentifier("PROP");
	blenderTask* t1 = new blenderTask();
	t1->setCorrespondingWindow((blenderWindow&)mytdWindow);
	t1->setIdentifier("TDWN");
	//t1->timeOut = 10.f;
	blenderTask* t2 = new blenderTask();
	t2->setCorrespondingWindow((blenderWindow&)mytxtWindow1);
	t2->setIdentifier("TXT1");
	// Add the initialised task to the broker
	blenderTask* t3 = new blenderTask();
	t3->setCorrespondingWindow((blenderWindow&)mytxtWindow2);
	t3->setIdentifier("TXT2");
	broker.addTask(*t0);
	broker.addTask(*t1);
	broker.addTask(*t2);
	broker.addTask(*t3);
}

//--------------------------------------------------------------
void testApp::update(){
	receiveGazeCoords();
	if (started) {
		broker.update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	drawGaze();
}

void testApp::receiveGazeCoords()
{
	char udpMsg[100];
	int b;
	b = udpSocket.Receive(udpMsg, sizeof(udpMsg));
	if (b > 1)
	{
		memcpy(gazeCoords, (void*)udpMsg, sizeof(gazeCoords));
	}
}

void testApp::drawGaze()
{
	if(gazeCoords[0] == -1)
		return;
	//ofLogVerbose() << gazeCoords[0] << ":" << gazeCoords[1];
	int coordX = gazeCoords[0] - ofGetWindowPositionX();
	int coordY = gazeCoords[1] - ofGetWindowPositionY();
	ofPushMatrix();
	ofNoFill();
	ofSetColor(100,255,255,100);
	ofCircle(ofPoint(coordX, coordY), 40);
	ofSetColor(100,255,255,50);
	ofCircle(ofPoint(coordX, coordY), 20);
	ofSetColor(100,255,255,20);
	ofCircle(ofPoint(coordX, coordY), 10);
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	switch (key)
	{
	case 's':
		started = true;
		break;
	case 'l':
		// oyutput current measured tasks
		broker.outputResults();
		break;
	case OF_KEY_UP: //change to alt + F11?
		ofToggleFullscreen();
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	// reposition all windows on a resize event
	mypropWindow.set(0, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mypropWindow.setup();
	mytdWindow.set(ofGetWindowWidth()/4, 0, ofGetWindowWidth()/2, ofGetWindowHeight()/4*3);
	mytdWindow.setup();
	mytxtWindow1.set(ofGetWindowWidth()/4*3, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytxtWindow1.setup();
	mytxtWindow2.set(0, ofGetWindowHeight()/4*3, ofGetWindowWidth(), ofGetWindowHeight()/4);
	mytxtWindow2.setup();
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::exit()
{
	broker.saveResults();
	broker.outputResults();
}
