#include "ofxHapImageSequence.h"

ofxHapImageSequence::ofxHapImageSequence()
{

}

ofxHapImageSequence::ofxHapImageSequence(ofDirectory& directory)
{
    load(directory);
}

ofxHapImageSequence::ofxHapImageSequence(const std::string& path)
{
    load(path);
}

ofxHapImageSequence::~ofxHapImageSequence()
{

}

void ofxHapImageSequence::load(ofDirectory &directory)
{
    load(directory.path());
}

void ofxHapImageSequence::load(const std::string &path)
{
    ofFile file(path, ofFile::Reference);
    if (file.exists() && !file.isDirectory())
    {
        file = ofFile(file.getEnclosingDirectory(), ofFile::Reference);
    }
    // listDir() and sort() are slow in Debug builds on Windows
    directory_ = ofDirectory(file.getAbsolutePath());
    directory_.allowExt(ofxHapImage::HapImageFileExtension());
    directory_.listDir();
    directory_.sort();
}

unsigned int ofxHapImageSequence::size()
{
    return directory_.size();
}

ofxHapImage ofxHapImageSequence::getImage(unsigned int index)
{
    return ofxHapImage(directory_[index]);
}
