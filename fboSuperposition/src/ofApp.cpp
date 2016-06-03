#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0,0,0);
    ofSetFrameRate(60);
    
    //allocate our fbos.
    //providing the dimensions and the format for the,
    fbo_a.allocate(400, 400, GL_RGBA); // with alpha, 8 bits red, 8 bits green, 8 bits blue, 8 bits alpha, from 0 to 255 in 256 steps
    fbo_b.allocate(400, 400, GL_RGBA);
    // we have to clear all the fbos so that we don't see any artefacts
    // the clearing color does not matter here, as the alpha value is 0, that means the fbo is cleared from all colors
    // whenever we want to draw/update something inside the fbo, we have to write that inbetween fbo.begin() and fbo.end()
    
    fbo_a.begin();
    ofClear(255,255,255, 0);
    fbo_a.end();
    
    fbo_b.begin();
    ofClear(255,255,255, 0);
    fbo_b.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofEnableAlphaBlending();
    
    int mousex  = (ofGetMouseX() / (float) ofGetWidth()) * 400;
    
    //lets draw some graphics into our two fbos
    fbo_a.begin();
    ofClear(0,0,0, 0);
        ofPushStyle();
        ofFill();
        ofSetColor(ofColor::red);
        ofDrawCircle(mousex, 100, 50);
        ofPopStyle();
    fbo_a.end();
    
    fbo_b.begin();
    ofClear(0,0,0, 0);
    ofPushStyle();
        ofFill();
        ofSetColor(ofColor::blue);
        ofDrawCircle(400 - mousex, 300, 50);
    ofPopStyle();
    
    fbo_b.end();
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    fbo_a.draw(0,0);
    fbo_b.draw(0,0);

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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