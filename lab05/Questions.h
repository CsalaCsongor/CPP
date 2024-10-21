//
// Created by Csala on 2024. 10. 21..
//

#ifndef LAB4_QUESTIONS_H
#define LAB4_QUESTIONS_H


#include "Answer.h"
#include <string>
#include <vector>

class Questions {
private:
    std::string text;
    std::vector<Answer> answers;
public:
    explicit Questions(const std::string& text);
    void addAnswer(const std::string& answer);
    void setCorrect(int index);
};


#endif //LAB4_QUESTIONS_H
