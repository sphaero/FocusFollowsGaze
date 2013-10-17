#include "testApp.h"

#define N_TEXTFIELDS 4

ofxTextInputField multilineTextInput[N_TEXTFIELDS];

ofTrueTypeFont font;


//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(240);
	ofSetLogLevel(OF_LOG_VERBOSE);
	
	font.loadFont("verdana.ttf", 18);
	
	for (int i = 0; i < N_TEXTFIELDS; i++) {
		multilineTextInput[i].setup();
		multilineTextInput[i].multiline = true;
		multilineTextInput[i].setFont(font);
	}
	
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
void testApp::update(){

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
	
//	multilineTextInput[0].posActive(mouseX, mouseY);
//	multilineTextInput[0].draw();
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
