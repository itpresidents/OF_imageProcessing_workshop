#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    // load image
    image.loadImage("greenscreen.jpg");
    
    //allocate space for the new greenscreened image
    greenScreen.allocate(image.getWidth(), image.getHeight(), OF_IMAGE_COLOR);
    
    //declare an ofPixels object and copy the pixels from the original image into pixels
    ofPixels pixels = image.getPixelsRef();
    
    //step through the columns
    for( int y = 0; y < image.getHeight(); y++) {
        //step through the rows
        for(int x = 0; x < image.getWidth(); x++) {
            //declare an ofColor object and pass it the color for every pixel at (x, y)
            ofColor color = pixels.getColor(x, y);
            //variables to store color info
            int r = color.r;
            int g = color.g;
            int b = color.b;
            
            // if statement to see if green color values are larger than the sum of red and blue color values
            if (g > b+r) {
                // if yes, set those color channels to 255 (all three make white)
                color.r = 255;
                color.g = 255;
                color.b = 255;
            }
            //set the new colors into the ofPixels object
            pixels.setColor(x, y, color);
        }
    }
    //set the pixels for the greenscreened image from the new pixels object
    greenScreen.setFromPixels(pixels);

    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //draw the original image
    image.draw(0,0);
    
    //draw the greenScreened image
    greenScreen.draw(image.getWidth(),0);
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