#include "ofApp.h"

#include <iostream>

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
  std::cout << "keyPressed: " << key << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
  std::cout << "keyReleased: " << key << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
  std::cout << "mouseMoved: " << x << ", " << y << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
  std::cout << "mouseDragged: " << x << ", " << y << ", " << button << std::endl;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  std::cout << "mousePressed: " << x << ", " << y << ", " << button << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
  std::cout << "mouseReleased: " << x << ", " << y << ", " << button << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
  std::cout << "mouseEntered: " << x << ", " << y << std::endl;
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
  std::cout << "mouseExited: " << x << ", " << y << std::endl;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  std::cout << "windowResized: " << w << ", " << h << std::endl;
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
  std::cout << "gotMessage: " << msg.message << std::endl;
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
  std::cout << "dragEvent: " << dragInfo.position << std::endl;
}
