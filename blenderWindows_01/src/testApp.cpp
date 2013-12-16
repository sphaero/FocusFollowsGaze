#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0);\
	ofEnableAlphaBlending();
	ofSetLogLevel(OF_LOG_VERBOSE);
	//ofSetFrameRate(60);
	ofSetVerticalSync(false);
	// Setup UDP socket to receive data from OpenGazer
	udpSocket.Create();
	udpSocket.Bind(OG_UDP_PORT);
	udpSocket.SetNonBlocking(true);

	// initialise gaze coords
	gazeCoords[0] = -1;
	gazeCoords[1] = -1;
	gazeCoords[2] = -1;
	gazeCoords[3] = -1;
	
	//create an event listener for eye movement
	//ofAddListener(onEyeMoved, this, &testApp::eyeMoved);
	ofAddListener(gazeMove, (blenderWindow*)&mypropWindow, &blenderWindow::onGazeMoved);
	ofAddListener(gazeMove, (blenderWindow*)&mytdWindow, &blenderWindow::onGazeMoved);
	ofAddListener(gazeMove, (TXTWindow*)&mytxtWindow1, &TXTWindow::onGazeMoved);
	ofAddListener(gazeMove, (TXTWindow*)&mytxtWindow2, &TXTWindow::onGazeMoved);

	// Set windows positions & dimensions
	mypropWindow.set(0, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytdWindow.set(ofGetWindowWidth()/4, 0, ofGetWindowWidth()/2, ofGetWindowHeight()/4*3);
	mytxtWindow1.set(ofGetWindowWidth()/4*3, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytxtWindow2.set(0, ofGetWindowHeight()/4*3, ofGetWindowWidth(), ofGetWindowHeight()/4);

	//position buttons
	float posX = ofGetWindowWidth() - 64;
	float posY = ofGetWindowHeight() - 32;
	gazeTrackBtn.setImage("gaze.png");
	gazeTrackBtn.enableMouseEvents();
	gazeTrackBtn.set(posX, posY, 16, 16);
	startBtn.setImage("record.png");
	startBtn.enableMouseEvents();
	startBtn.set(posX+20, posY, 16, 16);
	cursorBtn.setImage("cursor.png");
	cursorBtn.enableMouseEvents();
	cursorBtn.set(posX+40, posY, 16, 16);


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

	// very ugly code
	if (gazeTrackBtn.on)
	{
		mypropWindow.mouseFocus = false;
		mytdWindow.mouseFocus = false;
		mytxtWindow1.mouseFocus = false;
		mytxtWindow2.mouseFocus = false;
	}
	else
	{
		mypropWindow.mouseFocus = true;
		mytdWindow.mouseFocus = true;
		mytxtWindow1.mouseFocus = true;
		mytxtWindow2.mouseFocus = true;
	}
	receiveGazeCoords();
	if ( gazeTrackBtn.on && (gazeCoords[2] != prevGazeCoords[0] || gazeCoords[3] != prevGazeCoords[1]) )
	{
		// Eyes have moved
		//ofLogVerbose() << "eyes have moved";
		prevGazeCoords[0] = gazeCoords[2];
		prevGazeCoords[1] = gazeCoords[3];
		int coordX = gazeCoords[2] - ofGetWindowPositionX();
		int coordY = gazeCoords[3] - ofGetWindowPositionY();
		ofVec2f gc = ofVec2f(coordX, coordY);
		//ofLogVerbose() << gc;
		ofNotifyEvent(gazeMove, gc);
	}
	if (startBtn.on) {
		broker.update();
	}
	mypropWindow.update();
	mytdWindow.update();
	mytxtWindow1.update();
	mytxtWindow2.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	mypropWindow.draw();
	mytdWindow.draw();
	mytxtWindow1.draw();
	mytxtWindow2.draw();

	if (cursorBtn.on)
	{
		drawGaze();
	}
	ofSetColor(255);
        ofDrawBitmapString("Fps: " + ofToString( ofGetFrameRate()), ofGetWindowWidth()-200,ofGetWindowHeight()-25);
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
	if(gazeCoords[2] == -1)
		return;
	int coordX = gazeCoords[2] - ofGetWindowPositionX();
	int coordY = gazeCoords[3] - ofGetWindowPositionY();
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
		startBtn.on = true;
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

	float posX = w - 64;
	float posY = h - 32;
	gazeTrackBtn.set(posX, posY, 16, 16);
	startBtn.set(posX+20, posY, 16, 16);
	cursorBtn.set(posX+40, posY, 16, 16);
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
