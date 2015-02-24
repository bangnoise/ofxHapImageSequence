#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (sequence.size() > 0)
    {
        /*
         Calculate the current looped frame number
         */
        int this_frame = ofGetFrameNum() % sequence.size();
        /*
         Update our image
         */
        image.loadImage(sequence[this_frame]);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (sequence.size() == 0)
    {
        ofDrawBitmapString("Drag a folder of Hap images to this window.", 10, 20);
        ofDrawBitmapString("Images sequences should be at 30 FPS (for this demo).", 10, 40);
    }
    else
    {
        image.draw((ofGetWindowWidth() / 2) - (image.getWidth() / 2), (ofGetWindowHeight() / 2) - (image.getHeight() / 2));
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    if (dragInfo.files.size() > 0)
    {
        sequence.load(dragInfo.files[0]);
    }
}
