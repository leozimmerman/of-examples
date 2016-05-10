#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    
    player.load("sounds/mix-stereo.wav");
    
    cout<<"FILE INFO:"<<endl;
    cout<<"Duration: "<< player.getDuration()<<endl;
    cout<<"Num Channels: "<< player.getNumChannels()<<endl;
    
    
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    int sr = player.getSampleRate();
    
    // update the sound playing system:?
    ofSoundUpdate();
        
    soundBuffer = player.getCurrentSoundBuffer(512);
    
//    cout<<"soundBuffer channels: "<<soundBuffer.getNumChannels()<<endl;
//    cout<<"soundBuffer sr: "<<soundBuffer.getSampleRate()<<endl;
//    cout<<"sound NumFrames"<<soundBuffer.getNumFrames()<<endl;
//    cout<<"soundB thickCount"<<soundBuffer.getTickCount()<<endl;
    
    //-----------------
    
    waveform.clear();
    
    int ch=0; //channel to visualize
    
    for(size_t i = 0; i < soundBuffer.getNumFrames(); i++) {
        float sample = soundBuffer.getSample(i, ch);
        float x = ofMap(i, 0, soundBuffer.getNumFrames(), 0, ofGetWidth());
        float y = ofMap(sample, -1, 1, 0, ofGetHeight());
        waveform.addVertex(x, y);
    }
    
    
    
   
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    waveform.draw();
    
    ofDrawBitmapString("Press any key to play audio file", 30, ofGetHeight()-40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    player.play();

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
