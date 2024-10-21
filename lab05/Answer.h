//
// Created by Csala on 2024. 10. 21..
//

#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H
#include <string>

class Answer {
private:
    std::string text;
    bool correct{};
public:
    explicit Answer(const std::string& text);
    std::string getText();
    bool isCorrect() const;
    void setCorrect();

};


#endif //LAB5_ANSWER_H
