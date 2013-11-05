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
	//initialise gaze coords
	gazeCoords[0] = -1;
	gazeCoords[1] = -1;
	
	mypropWindow.set(0, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytdWindow.set(ofGetWindowWidth()/4, 0, ofGetWindowWidth()/2, ofGetWindowHeight()/4*3);
	mytxtWindow1.set(ofGetWindowWidth()/4*3, 0, ofGetWindowWidth()/4, ofGetWindowHeight()/4*3);
	mytxtWindow2.set(0, ofGetWindowHeight()/4*3, ofGetWindowWidth(), ofGetWindowHeight()/4);


}

//--------------------------------------------------------------
void testApp::update(){
	//receiveGazeCoords();
	broker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//drawGaze();
}

void testApp::receiveGazeCoords()
{
	char udpMsg[100];
	udpSocket.Receive(udpMsg, sizeof(udpMsg));
	if (strlen(udpMsg) > 1)
	{
		memcpy(gazeCoords, (void*)udpMsg, sizeof(gazeCoords));
	}
	/*else
	{
		gazeCoords[0] = -1;
		gazeCoords[1] = -1;
	}*/
}

void testApp::drawGaze()
{
	//if(gazeCoords[0] == -1)
	//	return;
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
	case 'l':
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
