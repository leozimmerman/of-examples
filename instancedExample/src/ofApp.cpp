#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
 
    ofSetBackgroundColor(0);
    ofSetFrameRate(60);
 
    
    //gui-------------
    gui.setup();
    gui.add(gMode.setup("LINEAL/RADIAL", false));
    gui.add(gRadMode.setup("Concentric/Centrifuge", false));
    gui.add(gRadDeform.setup("Radial Mix", 0.0, 0.0, 1.0));
    
    
    gui.add(gWidth.setup("width", 1.0, 0., 1.0));
    gui.add(gHeight.setup("height/radius", 0.25, 0., 1.0));
    gui.add(gCubesizeUnified.setup("cubesize", 0.25, 0., 1.0));
    //gui.add(gCubesize.setup("cubesize", ofVec3f(0.2), ofVec3f(0.0), ofVec3f(1.0)));
    gui.add(gMaskRadius.setup("maskRadius", 0.0, 0.0, 1.0));
    gui.add(gHres.setup("Hres", 0.3, 0., 1.0));
    gui.add(gVres.setup("Vres", 0.3, 0., 1.0));
    gui.add(gXpos.setup("Xpos", 0.0, 0., 1.0));
    gui.add(gYpos.setup("Ypos", 0.5, 0., 1.0));
    gui.add(gVelocity.setup("velocity", 0.0, 0., 1.0));
    //nz
    gui.add(gNzTime.setup("nzTime", 0.1, 0.0, 1.0));
    
    gui.add(gNzXAmp.setup("nzXAmp", 0.0, 0.0, 1.0));
    gui.add(gNzXFreq.setup("nzXFreq", 0.5, 0.0, 1.0));
    gui.add(gNzXRug.setup("nzXRug", 0.05, 0.01, 1.0));
    
    gui.add(gNzYAmp.setup("nzYAmp", 0.0, 0.0, 1.0));
    gui.add(gNzYFreq.setup("nzYFreq", 0.5, 0.0, 1.0));
    gui.add(gNzYRug.setup("nzYRug", 2.0, 0.01, 30.0));
    
    gui.add(gNzZAmp.setup("nzZAmp", 0.0, 0.0, 1.0));
    gui.add(gNzZFreq.setup("nzZFreq", 0.5, 0.0, 1.0));
    gui.add(gNzZRug.setup("nzZRug", 0.05, 0.01, 1.0));
    //
    gui.add(gUseCam.setup("useCam", false));
    gui.add(gAxis.setup("axis", false));
    gui.add(gUseLight.setup("useLight", false));
    gui.add(gLightPos.setup("LighPos", ofVec3f(0.5), ofVec3f(0.0), ofVec3f(1.0)));

    
    
    cam.lookAt(ofVec3f( ofGetWidth()*.5, ofGetHeight()*.5, 0.0));
    light.setPosition(ofGetWidth()*.5, ofGetHeight()*.5, 150.0);
    light.setPointLight();
    
    instanced.setup();
    instanced.setLimits(ofVec3f(ofGetWidth(), ofGetHeight(), 100));
    instanced.setOrientation(ofVec3f(1,1,1));
    instanced.setColor(ofColor::white);
    
    
    bShowGui = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    //display frame rate as window title
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    int w = ofGetWidth();

    //update instancedManager values
    if(!gMode)instanced.setMode(LINEAL);
    else if(gMode && !gRadMode) instanced.setMode(RAD_CONCENTRIC);
    else if(gMode && gRadMode){
        instanced.setMode(RAD_CENTRIFUGE);
        instanced.setRadDeform(gRadDeform);
    }
    
    instanced.setWidth(gWidth);
    instanced.setHeight(gHeight);
    instanced.setCubeSize(gCubesizeUnified * MAX_CUBESIZE*w);
    //    instanced.setCubeSize(ofVec3f(gCubesize->x * MAX_CUBESIZE,
    //                                  gCubesize->y * MAX_CUBESIZE,
    //                                  gCubesize->z * MAX_CUBESIZE));
    instanced.setMaskRadius(gMaskRadius);
    instanced.setHres(gHres * MAX_H_RES);
    instanced.setVres(gVres * MAX_V_RES);
    instanced.setVelocity(gVelocity * MAX_VELOCITY);
    instanced.setXpos(gXpos);
    instanced.setYpos(gYpos);
    //nz
    instanced.setNzTime(gNzTime * MAX_NZ_TIME);
    
    instanced.setXnzAmp(gNzXAmp * MAX_NZ_AMP*w);
    instanced.setXnzFreq(gNzXFreq * MAX_NZ_FREQ);
    instanced.setXnzRug(gNzXRug * MAX_NZ_RUG*w);
    
    instanced.setYnzAmp(gNzYAmp * MAX_NZ_AMP*w);
    instanced.setYnzFreq(gNzYFreq * MAX_NZ_FREQ);
    instanced.setYnzRug(gNzYRug * MAX_NZ_RUG*w);
    
    instanced.setZnzAmp(gNzZAmp * MAX_NZ_AMP*w);
    instanced.setZnzFreq(gNzZFreq * MAX_NZ_FREQ);
    instanced.setZnzRug(gNzZRug * MAX_NZ_RUG*w);
    
    //light pos
    
    light.setPosition(gLightPos->x * MAX_LIGHT_X,
                      gLightPos->y * MAX_LIGHT_Y,
                      gLightPos->z * MAX_LIGHT_Z );

    
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(gUseLight){
        ofEnableLighting();
        light.enable();
    }
    
    if(gUseCam)cam.begin();
    
    if(gAxis)ofDrawAxis(200);
    //light.draw();
    
    instanced.draw();
    
    if(gUseCam)cam.end();
    
    if(gUseLight){
        light.disable();
        ofDisableLighting();
    }

    //drawScene(ofGetHeight(), ofGetWidth());
    if (bShowGui) gui.draw();


}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    switch (key){
        default:
            break;
    }
    
}


