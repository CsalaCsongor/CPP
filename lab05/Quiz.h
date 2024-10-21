//
// Created by Csala on 2024. 10. 21..
//

#ifndef LAB4_QUIZ_H
#define LAB4_QUIZ_H


#include <string>
#include <vector>
#include "Questions.h"

class Quiz {
private:
    std::string name;
    std::vector<Questions> questions;

public:
    Quiz(std::string name, const std::string& fileName);
    int num_questions;
};



#endif //LAB4_QUIZ_H
