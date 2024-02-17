#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  soundPlayer.load("440Hz_44100Hz_16bit_05sec.wav");
  soundPlayer.setLoop(true);
  soundPlayer.play();

  ofSetBackgroundColor(0);

  light.setPosition(100, 100, 100);
  light.enable();

  material.setShininess(120);
  material.setSpecularColor(ofColor(255, 255, 255, 255));
  material.setDiffuseColor(ofColor(255, 255, 255, 255));
  material.setAmbientColor(ofColor(255, 255, 255, 255));

  ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  easyCam.begin();
  material.begin();

  ofPushMatrix();
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, 0);
  ofRotateDeg(ofGetElapsedTimef() * rotationSpeed, 1, 1, 0);
  ofDrawBox(0, 0, 0, 200);
  ofPopMatrix();

  material.end();
  easyCam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
