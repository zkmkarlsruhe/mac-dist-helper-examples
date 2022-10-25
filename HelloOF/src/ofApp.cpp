#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetWindowTitle("HelloOF");
	ofBackground(0);

	kitty.load("kitty.png");
	font.load(OF_TTF_SANS, 40);
}

//--------------------------------------------------------------
void ofApp::update() {
	spin += 0.005;
}

//--------------------------------------------------------------
void ofApp::draw() {

	// kitteh
	ofSetColor(255);
	kitty.draw(0, 0);

	// greeting
	ofSetColor(255, 0, 255);
	ofPushMatrix();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateDeg(sin(spin) * 135);
	ofTranslate(-font.stringWidth(greeting) / 2, font.stringHeight(greeting) / 2);
	font.drawString(greeting, 0, 0);
	ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}
