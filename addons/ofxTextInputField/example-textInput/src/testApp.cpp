#include "testApp.h"

ofTrueTypeFont font;

//--------------------------------------------------------------
void testApp::setup() {
    
	
//	monoLineTextInput.setup();
//	monoLineTextInput.text = "hello world";
//    monoLineTextInput.bounds.x = 100;
//    monoLineTextInput.bounds.y = 100;
//	monoLineTextInput.bounds.height = 40;
//	monoLineTextInput.bounds.width = 188;
	
	multilineTextInput.setup();
	multilineTextInput.text = "test";
    multilineTextInput.bounds.x = 100;
    multilineTextInput.bounds.y = 100;
	multilineTextInput.bounds.width = 400;
	multilineTextInput.bounds.height = 500;
	multilineTextInput.multiline = true;
	//font.loadFont(OF_TTF_SERIF, 18);
	//multilineTextInput.setFont(font);
	
	
}

//--------------------------------------------------------------
void testApp::update() {
	
}

//--------------------------------------------------------------
void testApp::draw() {
    ofBackground(255*.15);
    
    ofSetColor(255, 0, 0);
	ofFill();
    //ofRect(monoLineTextInput.bounds);
	ofRect(multilineTextInput.bounds);
    ofNoFill();
	ofSetColor(255);
	monoLineTextInput.draw();
	multilineTextInput.draw();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) { 

}
