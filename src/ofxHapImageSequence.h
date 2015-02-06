#pragma once
#include "ofMain.h"
#include "ofxHapImage.h"

class ofxHapImageSequence {
public:
    ofxHapImageSequence();
    ~ofxHapImageSequence();
    ofxHapImageSequence(ofDirectory& directory);
    ofxHapImageSequence(const std::string& path);
    void load(ofDirectory& directory);
    void load(const std::string& path);
    unsigned int size();
    ofxHapImage getImage(unsigned int index);
private:
    ofDirectory directory_;
};
