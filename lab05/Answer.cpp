//
// Created by Csala on 2024. 10. 21..
//

#include "Answer.h"

Answer::Answer(const std::string &text) {
this->text = text;
this->correct = false;
}

std::string Answer::getText() {
    return {this->text};
}

bool Answer::isCorrect() const {
    return this->correct;
}

void Answer::setCorrect() {
this->correct = true;
}
