//
// Created by Csala on 2024. 10. 21..
//

#include "Questions.h"


void Questions::addAnswer(const std::string &answer) {
    answers.emplace_back(answer);
}

void Questions::setCorrect(int index) {
answers.at(index).setCorrect();
}

Questions::Questions(const std::string &text) {
this->text = text;
}


