//
// Created by Csala on 2024. 12. 09..
//

#include "SimpleTextGenerator.h"

void SimpleTextGenerator::trainFromText(string trainingText) {


        for(char &c : trainingText)
        {
            c = tolower(c);
            if(!islower(c)){
                c = ' ';
            }
        }
        stringstream ss(trainingText);
        string word, prev1 = "", prev2 = "";
        ss >> prev1 >> prev2;
        while(ss >> word){
            data[prev1 + " " + prev2].push_back(word);
            prev1 = prev2;
            prev2 = word;
        }
        data[prev1 + " " + word].push_back("");

        for(auto it = data.begin(); it !=data.end(); it++)
        {
            cout << it->first << ": {";
            for(auto i : it->second)
            {
                cout << i << ", ";
            }
            cout << "}" << endl;
        }

}

void SimpleTextGenerator::trainFromFile(string filename) {
ifstream in(filename);
if(!in){
    throw runtime_error("Error when opening the file.");
}else
{
    string line;
    while(getline(in, line)){
        trainFromText(line);
    }
}
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    return std::string();
}

void SimpleTextGenerator::printData() const {

}
