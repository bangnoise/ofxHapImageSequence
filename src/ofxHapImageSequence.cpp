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
    path_ = file.getAbsolutePath();

    std::string xml_path = ofFilePath::addTrailingSlash(file.getAbsolutePath()) + "directory_cache.xml";
    ofFile xml_file(xml_path, ofFile::Reference);
    if (xml_file.exists())
    {
        std::time_t directory_modification = std::filesystem::last_write_time(file);
        std::time_t xml_modification = std::filesystem::last_write_time(xml_file);
        if (xml_modification < directory_modification)
        {
            xml_file.remove();
        }
    }
    if (xml_file.exists())
    {
        paths_.clear();
        ofXml cache(xml_path);
        cache.setTo("playlist");
        if (cache.setToChild(0))
        {
            do {
                paths_.push_back(cache.getValue());
            } while (cache.setToSibling());
        }
    }
    else
    {
        reload();
    }
}

void ofxHapImageSequence::reload()
{
    paths_.clear();
    ofDirectory directory(path_);
    directory.allowExt(ofxHapImage::HapImageFileExtension());
    // listDir() and sort() are slow in Debug builds on Windows
    directory.listDir();
    directory.sort();

    ofXml cache;
    cache.addChild("playlist");
    for (unsigned int i = 0; i < directory.size(); i++) {
        std::string this_file = directory[i].getFileName();
        paths_.push_back(this_file);
        ofXml file_xml;
        file_xml.addChild("file");
        file_xml.setTo("file");
        file_xml.setValue("", this_file);
        cache.addXml(file_xml);
    }
    cache.save(ofFilePath::addTrailingSlash(path_) + "directory_cache.xml");
}

unsigned int ofxHapImageSequence::size() // this could be const if ofDirectory.size() were const
{
    return paths_.size();
}

std::string ofxHapImageSequence::operator[](unsigned int index) const
{
    return ofFilePath::addTrailingSlash(path_) + paths_[index];
}
