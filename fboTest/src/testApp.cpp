#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //allows console to receive info about camera
    grabber.setVerbose(true);
    
    //initialize the camera with a capture width and height
    grabber.initGrabber(640, 480);
    
    //allocate memory for our ofImage, where we save the frame to
    screenGrab.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_COLOR);
    myFbo.allocate(grabber.width, grabber.height);
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();


}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255, 255, 255);
    //this way of drawing the camera mirrors it
    grabber.draw(grabber.getWidth(), 0, -grabber.getWidth(),grabber.getHeight());
    //if you don't want to mirror it, draw like this
    //grabber.draw(0,0);
    
    
    if (isScreenGrabbed) {
        //draw saved frame into FBO
        myFbo.begin();
        //put stuff here
        ofPushStyle(); //so alpha only affects FBO
        ofEnableAlphaBlending(); //lets us use alpha channel in the FBO
        ofSetColor(255, 255, 255, 100); //sets color to full color, then 100 for alpha
        //we also want to mirror the screengrab
        screenGrab.draw(grabber.getWidth(), 0, -grabber.getWidth(),grabber.getHeight());
        //end styles (set color)
        ofPopStyle();

        //end drawing into FBO
        myFbo.end();
        
        //draw FBO
        myFbo.draw(0,0);
    }
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
    screenGrab.setFromPixels(grabber.getPixelsRef());
    isScreenGrabbed = true;
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