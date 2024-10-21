//
// Created by Csala on 2024. 10. 21..
//

#include "Quiz.h"

#include <utility>
#include <fstream>
#include <sstream>

Quiz::Quiz(std::string name, const std::string& fileName) {
    this->name = std::move(name);
    this->num_questions = 0;
    std::ifstream in(fileName);
    if(!in)
    {
        throw std::runtime_error("file open error");
    }

    std::string line;
    while(getline(in, line))
    {
        if(line.empty()){
            continue;
        }
        if(line[0] == 'Q' && line[1] == ' '){
            questions.emplace_back(line.substr(2));
            num_questions++;
        }
        else if(line[0] == 'A' && line[1] == ' ' )
        {
            questions.at(questions.size()-1).addAnswer(line.substr(2));
        } else {
            std::stringstream ss(line);
            int helyes;
            while(ss >> helyes){
                questions.at(questions.size() - 1).setCorrect(helyes-1);
            }
        }
    }
}
