#include "testApp.h"

#define N_TEXTFIELDS 4
#define OG_UDP_PORT 20320

ofxTextInputField multilineTextInput[N_TEXTFIELDS];
ofTrueTypeFont font;

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(240);\
	ofEnableAlphaBlending();
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(60);
	font.loadFont("verdana.ttf", 18);
	
	// Setup UDP socket to receive data from OpenGazer
	udpSocket.Create();
	udpSocket.Bind(OG_UDP_PORT);
	udpSocket.SetNonBlocking(true);
	//initialise gaze coords
	gazeCoords[0] = -1;
	gazeCoords[1] = -1;

	for (int i = 0; i < N_TEXTFIELDS; i++) {
		multilineTextInput[i].setup();
		multilineTextInput[i].multiline = true;
		multilineTextInput[i].setFont(font);
	}
}

//--------------------------------------------------------------
void testApp::update(){
	//receiveGazeCoords();
	broker.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofFill();
	
	ofSetColor(117, 48, 207);
	ofRect(multilineTextInput[0].bounds.x, multilineTextInput[0].bounds.y, multilineTextInput[0].bounds.width, multilineTextInput[0].bounds.height);
	ofSetColor(138, 207, 48);
	ofRect(multilineTextInput[1].bounds.x, multilineTextInput[1].bounds.y, multilineTextInput[1].bounds.width, multilineTextInput[1].bounds.height);
	ofSetColor(48, 207, 197);
	ofRect(multilineTextInput[2].bounds.x, multilineTextInput[2].bounds.y, multilineTextInput[2].bounds.width, multilineTextInput[2].bounds.height);
	ofSetColor(207, 48, 59);
	ofRect(multilineTextInput[3].bounds.x, multilineTextInput[3].bounds.y, multilineTextInput[3].bounds.width, multilineTextInput[3].bounds.height);
	
	ofSetColor(255);
	ofNoFill();
	for (int i = 0; i < N_TEXTFIELDS; i++) {
		//multilineTextInput[i].posActive(mouseX, mouseY);
		multilineTextInput[i].draw();
	}
	
	drawGaze();
//	multilineTextInput[0].posActive(mouseX, mouseY);
//	multilineTextInput[0].draw();
	

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
	//dimensions for Blender mock-up
	multilineTextInput[0].bounds.x = 0;
	multilineTextInput[0].bounds.y = 0;
	multilineTextInput[0].bounds.width = ofGetWindowWidth()/4;
	multilineTextInput[0].bounds.height = ofGetWindowHeight()/4*3;

	multilineTextInput[1].bounds.x = ofGetWindowWidth()/4*3;
	multilineTextInput[1].bounds.y = 0;
	multilineTextInput[1].bounds.width = ofGetWindowWidth()/4;
	multilineTextInput[1].bounds.height = ofGetWindowHeight()/4*3;

	multilineTextInput[2].bounds.x = 0;
	multilineTextInput[2].bounds.y = ofGetWindowHeight()/4*3;
	multilineTextInput[2].bounds.width = ofGetWindowWidth();
	multilineTextInput[2].bounds.height = ofGetWindowHeight()/4;

	multilineTextInput[3].bounds.x = ofGetWindowWidth()/4;
	multilineTextInput[3].bounds.y = 0;
	multilineTextInput[3].bounds.width = ofGetWindowWidth()/2;
	multilineTextInput[3].bounds.height = ofGetWindowHeight()/4*3;

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
