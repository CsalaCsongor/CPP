//
// Created by Csala on 2024. 12. 09..
//
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include "TextGenerator.h"
#ifndef LAB12_SIMPLETEXTGENERATOR_H
#define LAB12_SIMPLETEXTGENERATOR_H

using namespace std;

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const; // a map kiíratása
};



#endif //LAB12_SIMPLETEXTGENERATOR_H
