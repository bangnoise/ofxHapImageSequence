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
    void reload();
    unsigned int size();
    std::string operator [](unsigned int index) const;
private:
    std::string path_;
    std::vector<std::string> paths_;
};
