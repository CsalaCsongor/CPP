#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include "SimpleTextGenerator.h"
using namespace std;


int main() {

    string text = "Now is not the time for sleep, now is the time for party!";
    SimpleTextGenerator textGenerator;
    textGenerator.trainFromText(text);


    return 0;
}