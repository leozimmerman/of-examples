#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "instancedManager.h"

//---------------
#define MAX_CUBESIZE 0.02
#define MAX_H_RES 200
#define MAX_V_RES 100
#define MAX_VELOCITY 10

#define MAX_NZ_TIME 50

#define MAX_NZ_AMP 0.2
#define MAX_NZ_FREQ 0.1
#define MAX_NZ_RUG 0.03

#define MAX_LIGHT_X 1024
#define MAX_LIGHT_Y 800
#define MAX_LIGHT_Z 800




class ofApp : public ofBaseApp{
	
public:
		
	void setup();
	void update();
	void draw();
   
    
    void keyPressed(int key);
    
    //gui----
    //gui
    ofxToggle gMode, gRadMode;
    ofxFloatSlider gRadDeform;
    
    ofxFloatSlider gWidth, gHeight, gHres,
    gVres, gVelocity, gYpos, gXpos;
    
    ofxVec3Slider gCubesize;
    ofxFloatSlider gCubesizeUnified;
    
    ofxFloatSlider gMaskRadius;
    
    ofxFloatSlider gNzTime;
    ofxFloatSlider gNzXAmp, gNzXRug, gNzXFreq;
    ofxFloatSlider gNzYAmp, gNzYRug, gNzYFreq;
    ofxFloatSlider gNzZAmp, gNzZRug, gNzZFreq;
    
    ofxToggle gUseCam;
    ofxToggle gAxis;
    ofxToggle gUseLight;
    ofxVec3Slider gLightPos;
    
    ofxPanel gui;

    bool bShowGui;
    
    ofEasyCam cam;
    ofLight light;
    
    InstancedManager instanced;
    
    

};
